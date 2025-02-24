/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:10:48 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/24 13:24:37 by imugica-         ###   ########.fr       */
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
	load_numbers(&b, args);
	if (!is_unique(a))
		return (1);
	pb(&a,&b);
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	printf("b\n");
	while (b)
	{
		printf("%d\n", b->content);
		b = b->next;
	}
	// set_indices(&a);
	return (0);
}
