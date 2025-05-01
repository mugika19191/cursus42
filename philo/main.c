/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:40:04 by imugica-          #+#    #+#             */
/*   Updated: 2025/05/01 13:17:42 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->stats->print_mutex);
	printf("%zu %d is thinking\n", get_current_time() - philo->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->stats->print_mutex);
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
	// ft_usleep(100);
	pthread_mutex_lock(&philo->fork);       // left
	pthread_mutex_lock(&philo->next->fork); // right
	pthread_mutex_lock(&philo->stats->print_mutex);
	printf("%zu %d has taken a fork\n", get_current_time() - philo->start_time,
		philo->id);
	printf("%zu %d has taken a fork\n", get_current_time() - philo->start_time,
		philo->id);
	printf("%zu %d is eating\n", get_current_time() - philo->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->stats->print_mutex);
	pthread_mutex_lock(&philo->time_mutex);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->time_mutex);
	usleep(philo->eat_t * 1000);
	pthread_mutex_unlock(&philo->next->fork); // right
	pthread_mutex_unlock(&philo->fork);       // left
}

void	*philo_sleep(void *philo)
{
	t_philo	*philo_c;

	philo_c = philo;
	pthread_mutex_lock(&philo_c->stats->print_mutex);
	printf("%zu %d is sleeping\n", get_current_time()
		- ((t_philo *)philo)->start_time, ((t_philo *)philo)->id);
	pthread_mutex_unlock(&philo_c->stats->print_mutex);
	usleep(((t_philo *)philo)->sleep_t * 1000);
	return (NULL);
}

void	dead_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->stats->print_mutex);
	printf("%zu %d is dead\n", get_current_time()
		- ((t_philo *)philo)->start_time, ((t_philo *)philo)->id);
	pthread_mutex_unlock(&philo->stats->print_mutex);
	return ;
}

int	check_over(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->stats->philo_amount)
	{
		pthread_mutex_lock(&philo->time_mutex);
		if (get_current_time() - philo->last_meal >= philo->die_t)
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
	philo_think(philo_c); // Philosopher starts by thinking
	while (1)
	{
		pthread_mutex_lock(&philo_c->stats->state_mutex);
		if (philo_c->stats->is_over) // Check if the simulation is over
		{
			pthread_mutex_unlock(&philo_c->stats->state_mutex);
			break ; // Exit the loop if simulation is over
		}
		pthread_mutex_unlock(&philo_c->stats->state_mutex);
		philo_eat(philo_c); // Philosopher eats
		pthread_mutex_lock(&philo_c->stats->state_mutex);
		if (philo_c->stats->is_over) // Double check after eating
		{
			pthread_mutex_unlock(&philo_c->stats->state_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo_c->stats->state_mutex);
		philo_sleep(philo_c); // Philosopher sleeps
		pthread_mutex_lock(&philo_c->stats->state_mutex);
		if (philo_c->stats->is_over) // Double check after sleeping
		{
			pthread_mutex_unlock(&philo_c->stats->state_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo_c->stats->state_mutex);
		philo_think(philo_c); // Philosopher thinks again
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
		if (manager_c->stats->is_over) // Check if the simulation is over
		{
			pthread_mutex_unlock(&manager_c->stats->state_mutex);
			break ; // Exit the loop if simulation is over
		}
		manager_c->stats->is_over = check_over(manager_c->philos);
			// Check if any philosopher has died
		pthread_mutex_unlock(&manager_c->stats->state_mutex);
		// usleep(100);  // Reduced sleep time for quicker response
	}
	return (NULL);
}

void	init_stats(t_stats *stats, char **args, int mode)
{
	stats->is_over = 0;
	stats->philo_amount = ft_atoi(args[1]);
	pthread_mutex_init(&stats->state_mutex, NULL);
	pthread_mutex_init(&stats->print_mutex, NULL);
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
		ft_philoadd_back(&philos, ft_philotnew(i++, args, &stats));
	manager.philos = philos;
	manager.stats = &stats;
	p_head = philos;
	i = 1;
	while (i <= ft_atoi(args[1]))
	{
		pthread_create(&(p_head->thread), NULL, philo_loop, (void *)p_head);
		if (i % 2 == 0)
			ft_usleep(500);
		p_head = p_head->next;
		i++;
	}
	pthread_create(&(manager.thread), NULL, manage_loop, (void *)&manager);
	p_head = philos;
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
