#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int check_all_num(char *args)
{
	int i;
	i = 0;
	while (args[i])
	{
		if(ft_isdigit(args[i]))
			return (0);
	}
	return (1);
}


