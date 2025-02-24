#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*b;

	if (*a)
	{
		b = ft_stlast(*a);
		b->next = *a;
		b = *a;
		*a = (*a)->next;
		b->next = NULL;
	}
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **a)
{
	rotate(a);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}