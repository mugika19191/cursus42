
#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if ((*a)->next)
	{
		b = (*a)->next;
		(*a)->next = (*a)->next->next;
		b->next = *a;
		(*a) = b;
	}
}
void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **a)
{
	swap(a);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "sb\n", 3);
}
/*
void	pa(t_stack **a)
{
}
void	pb(t_stack **a)
{
}
void	ra(t_stack **a)
{
}
*/