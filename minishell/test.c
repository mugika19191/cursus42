#include "lib_ft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int	env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**export(char ***env, char *str)
{
	int		i;
	char	**copy;

	i = env_len(*env);
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	while ((*env)[--i])
	{
		copy[i] = malloc(ft_strlen((*env)[i]) + 1);
		copy[i] = ft_strdup((*env)[i]);
	}
	copy[env_len(*env) - 1] = ft_strdup(str);
	return (copy);
}

int	main(int count, char **args, char **env)
{
	int i = 0;
	env = export(&env, "sex=help");
	while (env[i])
		printf("%s\n", env[i++]);
	return (0);
}