/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:40:04 by imugica-          #+#    #+#             */
/*   Updated: 2025/05/06 13:46:53 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_take_fork(t_philo *philo, int mode)
{
	pthread_mutex_lock(&philo->stats->state_mutex);
	if (philo->stats->is_over)
	{
		pthread_mutex_unlock(&philo->stats->state_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->stats->state_mutex);
	if (mode)
	{
		pthread_mutex_lock(&philo->fork);
	}
	else
		pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(&philo->stats->state_mutex);
	if (philo->stats->is_over)
	{
		pthread_mutex_unlock(&philo->stats->state_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->stats->state_mutex);
	print_msg("has taken a fork", philo);
	return (1);
}

int	check_over(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < philo->stats->philo_amount)
	{
		pthread_mutex_lock(&philo->eat_mutex);
		if (philo->meals == 0)
			j++;
		pthread_mutex_unlock(&philo->eat_mutex);
		pthread_mutex_lock(&philo->time_mutex);
		if (get_current_time() - philo->last_meal >= philo->die_t
			|| j == philo->stats->philo_amount)
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
	philo_c->start_time = get_current_time();
	philo_c->last_meal = get_current_time();
	while (1)
	{
		pthread_mutex_lock(&philo_c->stats->state_mutex);
		if (philo_c->stats->is_over)
		{
			pthread_mutex_unlock(&philo_c->stats->state_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo_c->stats->state_mutex);
		philo_eat(philo_c);
		philo_sleep(philo_c);
		philo_think(philo_c);
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
	}
	return (NULL);
}

int	main(int count, char **args)
{
	t_philo		*p_head;
	t_stats		stats;
	t_manager	manager;
	int			i;

	p_head = NULL;
	i = 1;
	if (count < 5 || count > 6)
		return (printf("Error arg count: %d\n", count), 1);
	if (check_inputs(args, count))
		return (printf("Error arg type\n"), 1);
	init_stats(&stats, args);
	while (i <= ft_atoi(args[1]))
		ft_philoadd_back(&p_head, ft_philotnew(i++, args, &stats, count == 6));
	manager.philos = p_head;
	manager.stats = &stats;
	throw_thread(p_head, ft_atoi(args[1]));
	pthread_create(&(manager.thread), NULL, manage_loop, (void *)&manager);
	join_all(p_head, manager);
	return (0);
}
