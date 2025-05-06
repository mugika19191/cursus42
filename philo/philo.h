/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:17:16 by imugica-          #+#    #+#             */
/*   Updated: 2025/05/06 13:44:21 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				philo_amount;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
}					t_stats;

typedef struct s_philo
{
	int				id;
	int				meals;
	int				eating;
	size_t			last_meal;
	size_t			sleep_t;
	size_t			eat_t;
	size_t			die_t;
	size_t			start_time;
	t_stats			*stats;
	pthread_t		thread;
	pthread_mutex_t	eat_mutex;
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

void				ft_philoadd_back(t_philo **lst, t_philo *new_elem);
t_philo				*ft_philolast(t_philo *lst);
int					ft_atoi(const char *str);
size_t				get_current_time(void);
void				*philo_sleep(void *philo);
void				*philo_loop(void *philo);
t_philo				*ft_philotnew(int id, char **args, t_stats *stats, int mode);
int					ft_isdigit(int c);
void				join_all(t_philo *p_head, t_manager manager);
int					check_inputs(char **args, int count);
void				init_stats(t_stats *stats, char **args);
void				philo_think(t_philo *philo);
int					ft_usleep(size_t milliseconds);
void				philo_eat(t_philo *philo);
void				*philo_sleep(void *philo);
void				dead_philo(t_philo *philo);
void				throw_thread(t_philo *p_head, int count);
int					philo_take_fork(t_philo *philo, int mode);
void				print_msg(char *str, t_philo *philo);

#endif
