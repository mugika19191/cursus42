/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:40:04 by imugica-          #+#    #+#             */
/*   Updated: 2025/04/17 11:04:08 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * neg);
}

int main(int count, char **args)
{
	t_philo *philos;
	t_philo *p_head;
	
	philos = NULL;
	int i = 1;
	if (count <= 5)
		return (printf("Error arg count: %d\n", count), 1);
	while (i <= ft_atoi(args[1]))
	{
		ft_philoadd_back(&philos , ft_philotnew(i++));
	}
	p_head = philos;
	printf("philo id: %d\n", p_head->id);
	p_head = philos->next;
	while (philos != p_head)
	{
		printf("philo id: %d\n", p_head->id);
		p_head = p_head->next;
	}
	usleep(ft_atoi(args[4]));
	printf("last philo id: %d\n", ft_philolast(philos)->id);
	printf("first philo id: %d\n", ft_philolast(philos)->next->id);
}
