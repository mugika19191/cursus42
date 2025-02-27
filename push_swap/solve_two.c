/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:57:35 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/27 12:57:39 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_stack *a, int pos)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->pos == pos)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

void	solve_insert(t_stack **a, t_stack **b)
{
	int	i;
	int	j;

	i = st_len(*a);
	j = st_len(*a);
	while (!has_ended(*a) || ft_stlast(*b))
	{
		while (find_pos(*a, i - j) != 0)
		{
			if (find_pos(*a, i - j) >= (i / 2))
				rra(a);
			else
				ra(a);
			if (has_ended(*a) && !ft_stlast(*b))
				return ;
		}
		pb(a, b);
		if (in_reverse_order(*b) && in_order(*a))
		{
			while (ft_stlast(*b))
				pa(a, b);
		}
		j--;
	}
}

void	solve_tres(t_stack **a)
{
	if ((*a)->pos == 0)
	{
		while (!has_ended(*a))
		{
			sa(a);
			ra(a);
		}
	}
	else if ((*a)->pos == 1 && (*a)->next->pos == 2)
		rra(a);
	else if ((*a)->pos == 1 && (*a)->next->pos == 0)
		sa(a);
	else if ((*a)->pos == 2 && (*a)->next->pos == 0)
		ra(a);
	else if ((*a)->pos == 2 && (*a)->next->pos == 1)
	{
		ra(a);
		sa(a);
	}
}

void	solve_two(t_stack **a)
{
	if (ft_stsize(*a) == 2)
	{
		while (!has_ended(*a))
			ra(a);
	}
	else if (ft_stsize(*a) == 3)
	{
		solve_tres(a);
	}
}
