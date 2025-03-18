#include "lib_ft/libft.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	get_var_len(char *str)
{
	int	i;

	i = 0;
	while (ft_isalpha(str[++i]))
		;
	return (i);
}

char	*get_var(char *str)
{
	int		i;
	char	*var;
	char	*value;

	i = 0;
	while (ft_isalpha(str[++i]))
		;
	if (i == 1)
		return (printf("returning a dollarr \n"), "$");
	var = malloc(i + 1);
	ft_strlcpy(var, str, i + 1);
	value = getenv(var + 1);
	free(var);
	if (value)
		return (value);
	return ("");
}

char	*replace_var(char *str, char **env)
{
	int		len;
	char	*var;
	char	*replace;
	char	*temp;
	char	*final;

	len = 0;
	var = ft_strchr(str + len, '$');
	final = str;
	while (var)
	{
		if (!var)
			return (final);
		replace = get_var(var);
		len = (var - final);
		temp = malloc(len + 1 + ft_strlen(replace) + (ft_strlen(final) - (len
						+ get_var_len(var))));
		ft_strlcpy(temp, final, len + 1);
		ft_strlcpy(temp + len, replace, ft_strlen(replace)  + 1);
		final = ft_strjoin(temp, final + len + get_var_len(var));
		free(temp);
		var = ft_strchr(final + len + 1, '$');
	}
	return (final);
}

int	read_line(char *user, char **env)
{
	char	*line;

	line = readline(user);
	if (line)
	{
		printf("PARSED LINE: %s\n", replace_var(line, env));
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
