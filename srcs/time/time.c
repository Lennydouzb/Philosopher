/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:39:26 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/16 23:56:40 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include <pthread.h>

void	updateeat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->locklasteat));
	philo->lasteat = get_time_in_ms();
	pthread_mutex_unlock(&(philo->locklasteat));
	pthread_mutex_lock(&(philo->lockeat));
	philo->has_ate += 1;
	pthread_mutex_unlock(&(philo->lockeat));
}

int	checkeat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->locklasteat));
	if (get_time_in_ms() - philo->lasteat < philo->ttd)
	{
		pthread_mutex_unlock(&(philo->locklasteat));
		return (1);
	}
	pthread_mutex_unlock(&(philo->locklasteat));
	print(5, philo->nb, philo);
	return (0);
}

long long	get_relative_time(t_philo *phil)
{
	long long	time;

	pthread_mutex_lock(&(phil->table->mu_hour));
	time = get_time_in_ms() - phil->table->start_hour;
	pthread_mutex_unlock(&(phil->table->mu_hour));
	return (time);
}

long long	get_time_in_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((long long)((t.tv_sec * 1000) + (t.tv_usec / 1000)));
}

void	better_sleep(t_philo *philo, long long time)
{
	long long	slept;

	slept = 0;
	while (check_run(philo) == 1 && slept < time)
	{
		usleep(1000);
		slept += 1000;
	}
}
