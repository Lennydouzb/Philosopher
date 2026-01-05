/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:39:20 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 11:15:46 by root             ###   ########.fr       */
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
	int				islock;
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
	int				musteat;	
}	t_philo;

typedef struct s_table
{
	t_fork	*forks;
	t_philo	*philos;

}	t_table;
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strsisnum(const char *str);
int		checkav(char **av);
void	init(t_philo *philos, t_fork *forks, char **arg);
t_table	parser(char **arg);
void	freeforksandphilos(t_fork *forks, t_philo *philos);
#endif
