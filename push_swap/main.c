/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:10:48 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/26 19:06:44 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique(t_stack *a)
{
	int		i;
	t_stack	*b;

	while (a)
	{
		i = a->content;
		b = a->next;
		while (b)
		{
			if (i == b->content)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			b = b->next;
		}
		a = a->next;
	}
	return (1);
}

void	load_numbers(t_stack **a, char **args)
{
	int		i;
	char	**numbers;
	int		corr;

	i = 0;
	corr = 1;
	numbers = ft_split(args[1], ' ');
	while (numbers[i])
	{
		st_atoi(numbers[i], &corr);
		if (corr)
			ft_stadd_back(a, ft_stnew(ft_atoi(numbers[i++])));
		else
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		free(numbers[i - 1]);
	}
	free(numbers);
}

void	ft_stfree(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	main(int count, char **args)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	i = 0;
	if (count != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	load_numbers(&a, args);
	if (!is_unique(a))
		return (1);
	set_indices(&a);
	resolve(&a, &b);
	ft_stfree(a);
	return (0);
}
