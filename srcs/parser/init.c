/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:00:08 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/13 11:08:06 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include <pthread.h>

static void	initfirstphilo(t_philo *philo, t_fork *forks, char **arg)
{
	philo->nb = 1;
	philo->rfork = &(forks[0]);
	philo->ttd = ft_atoi(arg[2]);
	philo->tte = ft_atoi(arg[3]);
	philo->tts = ft_atoi(arg[4]);
	philo->valid_eat = pthread_mutex_init(&(philo->lockeat), NULL);
	if (philo->valid_eat != 0)
		return ;
	philo->valid_lasteat = pthread_mutex_init(&(philo->locklasteat), NULL);
	if (philo->valid_lasteat != 0)
	{
		pthread_mutex_destroy(&(philo->lockeat));
		return ;
	}
}

static void	initphilos(t_philo *philo, t_fork *forks, char **arg, int i)
{
	philo->nb = i + 1;
	philo->lfork = &(forks[i]);
	philo->rfork = &(forks[i - 1]);
	philo->ttd = ft_atoi(arg[2]);
	philo->tte = ft_atoi(arg[3]);
	philo->tts = ft_atoi(arg[4]);
	philo->valid_eat = pthread_mutex_init(&(philo->lockeat), NULL);
	if (philo->valid_eat != 0)
		return ;
	philo->valid_lasteat = pthread_mutex_init(&(philo->locklasteat), NULL);
	if (philo->valid_lasteat != 0)
	{
		pthread_mutex_destroy(&(philo->lockeat));
		return ;
	}
}

void	init(t_philo *philos, t_fork *forks, char **arg, t_table *table)
{
	int	i;

	i = 0;
	while (i < ft_atoi(arg[1]))
	{
		forks[i].valid_mutex = pthread_mutex_init(&(forks[i].lock), NULL);
		if (forks[i].valid_mutex != 0)
			return ;
		forks[i].nb = i;
		++i;
	}
	i = 1;
	initfirstphilo(&(philos[0]), forks, arg);
	philos[0].table = table;
	table->nb_philo = ft_atoi(arg[1]);
	while (i < ft_atoi(arg[1]))
	{
		initphilos(&(philos[i]), forks, arg, i);
		philos[i].table = table;
		++i;
	}
	philos[i].lfork = NULL;
	philos[0].lfork = &(forks[i - 1]);
}
