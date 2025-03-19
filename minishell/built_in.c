#include "lib_ft/libft.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	pwd(char **env)
{
	printf(getenv("PWD"));
}

void	env(char **env)
{
	int i;

	i = 0;
	while (env[i])
		printf("%s\n", env[i++]);
}

void	export(char ***env, char *var)
{
	int i;

	i = 0;
	while (*env[i])
		i++;
}