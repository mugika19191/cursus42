#include "philo.h"

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


