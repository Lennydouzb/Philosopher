/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:00:08 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 11:21:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static void initfirstphilo(t_philo *philo, t_fork *forks, char **arg)
{
	philo->nb = 1;
	philo->lfork = &(forks[0]);
	philo->ttd = ft_atoi(arg[2]);
	philo->tte = ft_atoi(arg[3]);
	philo->tts = ft_atoi(arg[4]);
	if (!arg[5])
	{
		philo->musteat = -1;
		return ;
	}
	philo->musteat = ft_atoi(arg[5]);
}

static void	initphilos(t_philo *philo, t_fork *forks, char **arg, int i)
{
	philo->nb = i + 1;
	philo->lfork = &(forks[i]);
	philo->rfork = &(forks[i - 1]);
	philo->ttd = ft_atoi(arg[2]);
	philo->tte = ft_atoi(arg[3]);
	philo->tts = ft_atoi(arg[4]);
	if (!arg[5])
	{
		philo->musteat = -1;
		return ;
	}
	philo->musteat = ft_atoi(arg[5]);
}

void	init(t_philo *philos, t_fork *forks, char **arg)
{
	int	i;

	i = 0;
	while (i < ft_atoi(arg[1]))
	{
		forks[i].valid_mutex = pthread_mutex_init(&(forks[i].lock), NULL);
		if (forks[i].valid_mutex != 0)
			return ;
		forks[i].nb = i;
		forks[i].islock = 0;
		++i;
	}
	i = 1;
	initfirstphilo(&(philos[0]), forks, arg);
	while (i < ft_atoi(arg[1]))
	{
		initphilos(&(philos[i]), forks, arg, i);
		++i;
	}
	philos[i].lfork = NULL;
	philos[0].rfork = &(forks[i - 1]);
}
