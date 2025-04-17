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
