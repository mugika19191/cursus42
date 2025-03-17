#include "lib_ft/libft.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*replace_var(char **str, char **env)
{
	int		i;
	int		len;
	char	*var;
	char	*replace;
	char	*temp;

	i = 0;
	var = ft_strchr(*str, '$');
	if (!var)
		return (NULL);
	len = (var - *str);
	temp = malloc(len + 1);
	ft_strlcpy(temp, *str, len + 1);
	/*
	while (ft_strchr(*str, '$'))
	{
		temp = malloc(len + 1);
		ft_strlcpy(temp, *str, len);
	}*/
	printf("num of chars: %d\n", len);
	printf("up to $: %s \n", temp);
	free(temp);
	while (ft_isalpha(var[++i]));
	return (0);
}

int	read_line(char *user, char **env)
{
	char	*line;

	line = readline(user);
	if (line)
	{
		printf("Contains Var: %s\n", replace_var(&line, env));
		free(line);
	}
	else
		printf("Error reading line.\n");
	return (0);
}

int	main(int count, char **args, char **env)
{
	char *user;

	user = ft_strjoin(getenv("USER"), "@minishell ");
	while (1)
		read_line(user, env);
	free(user);
	return (0);
}
