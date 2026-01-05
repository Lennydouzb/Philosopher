/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:39:20 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 21:09:29 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
typedef struct s_fork
{
	unsigned int	nb;
	pthread_mutex_t	lock;
	int				valid_mutex;
}	t_fork;

typedef struct s_philo
{
	t_fork			*lfork;
	t_fork			*rfork;
	t_fork			*lhandedf;
	t_fork			*rhandedf;
	pthread_t       thread_id;
	unsigned int	nb;
	int				state;
	int				ttd;
	int				tte;
	int				tts;
	long long		lasteat;
	int				has_ate;
	pthread_mutex_t lockeat;
	int				valid_eat;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		monitor;
	pthread_mutex_t lock;
	int				valid_mu;
	int				running;
	pthread_mutex_t lockrun;
	int				musteat;
	int				valid_lockrun;
}	t_table;
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_strsisnum(const char *str);
int			checkav(char **av);
void		init(t_philo *philos, t_fork *forks, char **arg, t_table *table);
int		parser(t_table *table, char **arg);
void		freeforksandphilos(t_fork *forks, t_philo *philos);
void		updateeat(t_philo *philo);
void		launch_routine(t_table	*table);
int			checkeat(t_philo *philo);
void		print(int type, int nb, t_philo *phi);
long long	get_time_in_ms(void);
void		*monitor_routine(void *arg);
void		jointhreads(t_table *table);
void		freeeverything(t_table *table, char **arg);
int			check_mutexes(t_table *table, char **arg);
#endif
