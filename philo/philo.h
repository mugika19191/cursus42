#ifndef PHILO_H
# define PHILO_H
# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_stats
{
	size_t			sleep_t;
	size_t			eat_t;
	size_t			die_t;
}					t_stats;

typedef struct s_philo
{
	int				id;
	struct s_philo	*next;
}					t_philo;

t_philo				*ft_philotnew(int id);
void				ft_philoadd_back(t_philo **lst, t_philo *new_elem);
t_philo				*ft_philolast(t_philo *lst);

#endif