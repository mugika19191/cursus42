#include "push_swap.h"

void	r_rotate(t_stack **a)
{
	t_stack	*b;
	t_stack	*c;

	if (*a)
	{
		b = ft_stsemilast(*a);
		c = ft_stlast(*a);
		c->next = *a;
		*a = c;
		b->next = NULL;
	}
}

void	rra(t_stack **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **a)
{
	r_rotate(a);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rrr\n", 4);
}