#include "push_swap.h"

int	st_len(t_stack *a)
{
	int	i;

	i = 1;
	if (!a)
		return (0);
	while (a->next)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	set_indices(t_stack **a)
{
	int		small;
	int		i;
	t_stack	*b;
	t_stack	*c;

	b = *a;
	c = *a;
	i = 1;
	small = 2147483647;
	while (i <= st_len(*a))
	{
		while (b)
		{
			if ((b->pos < 0) && (small > b->content))
			{
				small = b->content;
				c = b;
			}
			b = b->next;
		}
		b = *a;
		small = 2147483647;
		c->pos = i++;
	}
}
