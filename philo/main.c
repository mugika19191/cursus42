/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:40:04 by imugica-          #+#    #+#             */
/*   Updated: 2025/04/23 13:16:01 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	printf("%zu %d is thinking\n", get_current_time()
		- philo->stats->start_time, philo->id);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(100);
	return (0);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	printf("%zu %d has taken a fork\n", get_current_time()
		- ((t_philo *)philo)->stats->start_time, ((t_philo *)philo)->id);
	pthread_mutex_lock(&philo->next->fork);
	printf("%zu %d has taken a fork\n", get_current_time()
		- ((t_philo *)philo)->stats->start_time, ((t_philo *)philo)->id);
	printf("%zu %d is eating\n", get_current_time()
		- ((t_philo *)philo)->stats->start_time, ((t_philo *)philo)->id);
	pthread_mutex_lock(&philo->time_mutex);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->time_mutex);
	ft_usleep(((t_philo *)philo)->stats->eat_t);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	*philo_sleep(void *philo)
{
	printf("%zu %d is sleeping\n", get_current_time()
		- ((t_philo *)philo)->stats->start_time, ((t_philo *)philo)->id);
	ft_usleep(((t_philo *)philo)->stats->sleep_t);
	return (NULL);
}

void	dead_philo(t_philo *philo)
{
	printf("%zu %d is dead\n", get_current_time()
		- ((t_philo *)philo)->stats->start_time, ((t_philo *)philo)->id);
	return ;
}

int	check_over(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->stats->philo_amount)
	{
		pthread_mutex_lock(&philo->time_mutex);
		if (get_current_time() - philo->last_meal >= philo->stats->die_t)
		{
			dead_philo(philo);
			pthread_mutex_unlock(&philo->time_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->time_mutex);
		philo = philo->next;
		i++;
	}
	return (0);
}

void	*philo_loop(void *philo)
{
	t_philo	*philo_c;

	philo_c = (t_philo *)philo;
	philo_think(philo_c);
	while (1)
	{
		pthread_mutex_lock(&philo_c->stats->state_mutex);
		if (philo_c->stats->is_over)
		{
			pthread_mutex_unlock(&philo_c->stats->state_mutex);
			break ;
		}
		philo_eat(philo_c);
		philo_sleep(philo_c);
		pthread_mutex_unlock(&philo_c->stats->state_mutex);
		philo_think(philo_c);
		ft_usleep(100);
	}
	return (NULL);
}

void	*manage_loop(void *manager)
{
	t_manager	*manager_c;

	manager_c = (t_manager *)manager;
	while (1)
	{
		pthread_mutex_lock(&manager_c->stats->state_mutex);
		if (manager_c->stats->is_over)
		{
			pthread_mutex_unlock(&manager_c->stats->state_mutex);
			break ;
		}
		manager_c->stats->is_over = check_over(manager_c->philos);
		pthread_mutex_unlock(&manager_c->stats->state_mutex);
		ft_usleep(100); // Sleep a bit to reduce CPU usage
	}
	return (NULL);
}

void	init_stats(t_stats *stats, char **args, int mode)
{
	stats->is_over = 0;
	stats->philo_amount = ft_atoi(args[1]);
	stats->die_t = ft_atoi(args[2]);
	stats->eat_t = ft_atoi(args[3]);
	stats->sleep_t = ft_atoi(args[4]);
	stats->start_time = get_current_time();
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
	manager.philos = philos;
	manager.stats = &stats;
	pthread_mutex_init(&manager.stats->state_mutex, NULL);
	pthread_create(&(manager.thread), NULL, manage_loop, (void *)&manager);
	while (p_head->id)
	{
		pthread_join(p_head->thread, NULL);
		p_head = p_head->next;
		if (p_head->id == 1)
			break ;
	}
	pthread_join(manager.thread, NULL);
	return (0);
}
