/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:17:04 by imugica-          #+#    #+#             */
/*   Updated: 2025/05/06 13:22:03 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
		|| c == '\f')
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

void	init_stats(t_stats *stats, char **args, int mode)
{
	stats->is_over = 0;
	stats->created = ft_atoi(args[1]);
	stats->philo_amount = ft_atoi(args[1]);
	pthread_mutex_init(&stats->state_mutex, NULL);
	pthread_mutex_init(&stats->created_mutex, NULL);
	pthread_mutex_init(&stats->print_mutex, NULL);
	if (mode)
		stats->amount_to_eat = ft_atoi(args[5]);
	return ;
}

int	check_inputs(char **args, int count)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < count)
	{
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	join_all(t_philo *p_head, t_manager manager)
{
	while (p_head->id)
	{
		pthread_join(p_head->thread, NULL);
		p_head = p_head->next;
		if (p_head->id == 1)
			break ;
	}
	pthread_join(manager.thread, NULL);
}
