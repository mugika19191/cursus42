#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_philo	*ft_philotnew(int id, t_stats *stats)
{
	t_philo	*mylist;

	mylist = malloc(sizeof(struct s_philo));
	if (!mylist)
		return (NULL);
	mylist->next = mylist;
	mylist->id = id;
	mylist->last_meal = get_current_time();
	mylist->stats = stats;
	pthread_mutex_init(&(mylist->time_mutex), NULL);
	//pthread_create(&(mylist->thread), NULL, philo_sleep, (void *)p_head);
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