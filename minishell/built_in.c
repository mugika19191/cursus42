#include "lib_ft/libft.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
int	env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}*/

char	*find_var(char *var, char **env)
{
	int		i;
	char	*str;

	i = -1;
	while (env[++i])
	{
		str = ft_strnstr(env[i], var, ft_strlen(var));
		if (str)
		{
			if (*(str + ft_strlen(var)) == '=')
				return (str + ft_strlen(var) + 1);
		}
	}
	return (NULL);
}

void	pwd(char **env)
{
	printf("%s\n",find_var("PWD",env));
}

void	env(char **env)
{
	int i;

	i = 0;
	while (env[i])
		printf("%s\n", env[i++]);
}
/*
char	**export(char **env, char *str)
{
	int		i;
	char	**copy;

	i = env_len(env);
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	while ((env)[--i])
	{
		copy[i] = malloc(ft_strlen((env)[i]) + 1);
		copy[i] = ft_strdup((env)[i]);
	}
	copy[env_len(env) - 1] = ft_strdup(str);
	return (copy);
}*/

void	echo(char *str, int mode)
{
	printf("%s",str);
	if (mode == 1)
		printf("\n");
}
