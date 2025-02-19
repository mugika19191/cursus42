#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

int	main(int count, char **args)
{
	int i;
	char **numbers;

	i = 0;
	if(count != 2)
		return (1);
	numbers = ft_split(args[1], ' ');
	while(numbers[i])
	{
		printf("%s\n", numbers[i]);
		i++;
	}
	return (0);
}
