/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:16:22 by imugica-          #+#    #+#             */
/*   Updated: 2025/05/06 13:47:38 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_all_num(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_isdigit(args[i]))
			return (0);
	}
	return (1);
}

void	print_msg(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->stats->print_mutex);
	printf("%zu %d %s\n", get_current_time() - philo->start_time, philo->id,
		str);
	pthread_mutex_unlock(&philo->stats->print_mutex);
}
