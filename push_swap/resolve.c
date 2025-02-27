/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:39:42 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/27 12:54:57 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_reverse_order(t_stack *a)
{
	t_stack	*current;

	if (a == NULL || a->next == NULL)
		return (1);
	current = a;
	while (current->next != NULL)
	{
		if (current->pos < current->next->pos)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	in_order(t_stack *a)
{
	t_stack	*current;

	if (a == NULL || a->next == NULL)
		return (1);
	current = a;
	while (current->next != NULL)
	{
		if (current->pos > current->next->pos)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

void	resolve(t_stack **a, t_stack **b)
{
	int	i;
	int	j;

	i = 1;
	j = st_len(*a);
	while (!has_ended(*a) || ft_stlast(*b))
	{
		while (j-- && !in_order(*a))
		{
			if (!get_bit((*a)->pos, i))
			{
				pb(a, b);
			}
			else
				ra(a);
		}
		i++;
		while (ft_stlast(*b))
		{
			pa(a, b);
		}
		j = st_len(*a);
	}
}
