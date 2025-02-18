/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:31:54 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/18 11:15:01 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipes.h"

void	free_all_mem(char ***str2)
{
	int	i;

	i = 0;
	while ((*str2)[i])
		free((*str2)[i++]);
	free((*str2));
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*joined;
	char	**splited;

	splited = ft_split(s2, ' ');
	joined = ft_strjoin(s1, splited[0]);
	free((void *)s1);
	free_all_mem(&splited);
	return (joined);
}

int	execve_free(char *path, char *args, char **env)
{
	char	**str;

	str = ft_split(args, ' ');
	execve(path, str, env);
	free_all_mem(&str);
	return (1);
}

int	execute_command(char *args, char **env)
{
	int		i;
	char	*str;
	char	**str2;
	char	*path;
	int		j;

	i = -1;
	while (env[++i])
	{
		j = 0;
		str = ft_strnstr(env[i], "PATH=", ft_strlen("PATH="));
		if (str)
		{
			str2 = ft_split(&str[5], ':');
			while (str2[j])
			{
				path = ft_strjoin_free(ft_strjoin(str2[j++], "/"), args);
				execve_free(path, args, env);
				free(path);
			}
			free_all_mem(&str2);
		}
	}
	return (0);
}
