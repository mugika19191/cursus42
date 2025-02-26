/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:39:54 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/26 18:44:21 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int number, int i)
{
	int	j;
	int	rem;

	j = 0;
	rem = 0;
	while (j < i)
	{
		rem = number % 2;
		number = number / 2;
		j++;
	}
	return (rem);
}

int	check_n_bit(t_stack *a, int i)
{
	while (a)
	{
		if (get_bit(a->pos, i) == 1)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	has_ended(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->pos == i)
			a = a->next;
		else
			return (0);
		i++;
	}
	return (1);
}
