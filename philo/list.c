#include "philo.h"

t_philo	*ft_philotnew(int id)
{
	t_philo	*mylist;

	mylist = malloc(sizeof(struct s_philo));
	if (!mylist)
		return (NULL);
	mylist -> next = mylist;
	mylist -> id = id;
	return (mylist);
}

void	ft_philoadd_back(t_philo **lst, t_philo *new_elem)
{
	if (!new_elem || !lst)
		return ;
	if (!*lst)
	{
		*lst = new_elem;
		return ;
	}
	ft_philolast(*lst)->next = new_elem;
	new_elem->next = *lst;
}

t_philo	*ft_philolast(t_philo *lst)
{
	t_philo *lst_cpy;
	lst_cpy = lst->next;
	if (!lst)
		return (NULL);
	if (lst == lst_cpy)
		return (lst);
	while (lst_cpy->next != lst)
		lst_cpy = lst_cpy->next;
	return (lst_cpy);
}