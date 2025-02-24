#include "push_swap.h"

void push(t_stack **a, t_stack **b)
{
	t_stack *c;

	c = NULL;
	if (a)
	{
		c = (*a);
		*a = *b;
		(*b) = (*b)->next;
		(*a)->next = c;
	}
}

void	pb(t_stack **a, t_stack **b)
{
	push(b,a);
	write(1, "pb\n", 3);
}
void	pa(t_stack **a, t_stack **b)
{
	push(a,b);
	write(1, "pa\n", 3);
}