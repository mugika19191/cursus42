/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:40:04 by imugica-          #+#    #+#             */
/*   Updated: 2025/04/22 13:38:53 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	printf("%zu %d is thinking\n", get_current_time(), philo->id);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	*philo_sleep(void *philo)
{
	printf("%zu %d is sleeping\n", get_current_time()
		- ((t_philo *)philo)->last_meal, ((t_philo *)philo)->id);
	ft_usleep(((t_philo *)philo)->stats->sleep_t);
	return (NULL);
}

int	check_over(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->time_mutex);
	while (i < philo->stats->philo_amount)
	{
		i++;
		if (get_current_time() - philo->last_meal >= philo->stats->die_t)
		{
			pthread_mutex_unlock(&philo->time_mutex);
			return (1);
		}
		philo = philo->next;
	}
	pthread_mutex_unlock(&philo->time_mutex);
	return (0);
}

void	*manage_loop(void *manager)
{
	t_manager	*manager_c;

	manager_c = (t_manager *)manager;
	while (1)
	{
		pthread_mutex_lock(&manager_c->state_mutex);
		if (manager_c->is_over)
		{
			pthread_mutex_unlock(&manager_c->state_mutex);
			break ;
		}
		manager_c->is_over = check_over(manager_c->philos);
		pthread_mutex_unlock(&manager_c->state_mutex);
	}
	return (NULL);
}

void	init_stats(t_stats *stats, char **args, int mode)
{
	stats->philo_amount = ft_atoi(args[1]);
	stats->die_t = ft_atoi(args[2]);
	stats->eat_t = ft_atoi(args[3]);
	stats->sleep_t = ft_atoi(args[4]);
	if (mode)
		stats->amount_to_eat = ft_atoi(args[5]);
	return ;
}

int	main(int count, char **args)
{
	t_philo		*philos;
	t_philo		*p_head;
	t_stats		stats;
	t_manager	manager;
	int			i;

	philos = NULL;
	i = 1;
	if (count < 5 || count > 6)
		return (printf("Error arg count: %d\n", count), 1);
	init_stats(&stats, args, (count == 6));
	while (i <= ft_atoi(args[1]))
		ft_philoadd_back(&philos, ft_philotnew(i++, &stats));
	p_head = philos;
	while (p_head->id)
	{
		pthread_create(&(p_head->thread), NULL, philo_sleep, (void *)p_head);
		p_head = p_head->next;
		if (p_head->id == 1)
			break ;
	}
	manager.is_over = 0;
	pthread_mutex_init(&manager.state_mutex, NULL);
	pthread_create(&(manager.thread), NULL, manage_loop, (void *)&manager);
	while (p_head->id)
	{
		pthread_join(p_head->thread, NULL);
		p_head = p_head->next;
		if (p_head->id == 1)
			break ;
	}
	return (0);
}
