#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_stats
{
	int				is_over;
	size_t			sleep_t;
	size_t			eat_t;
	size_t			die_t;
	size_t			start_time;
	int				amount_to_eat;
	int				philo_amount;
	pthread_mutex_t	state_mutex;
}					t_stats;

typedef struct s_philo
{
	int				id;
	int				meals;
	int				eating;
	size_t			last_meal;
	t_stats			*stats;
	pthread_t		thread;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	fork;
	struct s_philo	*next;
}					t_philo;

typedef struct s_manager
{
	pthread_t		thread;
	t_stats			*stats;
	struct s_philo	*philos;
}					t_manager;

t_philo				*ft_philotnew(int id, t_stats *stats);
void				ft_philoadd_back(t_philo **lst, t_philo *new_elem);
t_philo				*ft_philolast(t_philo *lst);
int					ft_atoi(const char *str);
size_t				get_current_time(void);
void				*philo_sleep(void *philo);
void				*philo_loop(void *philo);

#endif