/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:39:46 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/12 12:07:08 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include <pthread.h>

int	check_run(t_philo *philo)
{
	int	a;

	if (!philo || !philo->table)
		return (0);
	pthread_mutex_lock(&(philo->table->lockrun));
	a = philo->table->running;
	pthread_mutex_unlock(&(philo->table->lockrun));
	return (a);
}

void	print(int type, int nb, t_philo *phi)
{
	pthread_mutex_lock(&(phi->table->lock));
	if (type == 1)
		printf("%lld %d is thinking\n", get_relative_time(phi), nb);
	if (type == 2)
		printf("%lld %d has taken a fork\n", get_relative_time(phi), nb);
	if (type == 3)
		printf("%lld %d is eating\n", get_relative_time(phi), nb);
	if (type == 4)
		printf("%lld %d is sleeping\n", get_relative_time(phi), nb);
	if (type == 5)
		printf("%lld %d died\n", get_relative_time(phi), nb);
	pthread_mutex_unlock(&(phi->table->lock));
}

static void	*routine(void *arg)
{
	while (1 && check_run(((t_philo *)arg)) == 1)
	{
		if (((t_philo *)arg)->state == 0 && check_run(((t_philo *)arg)) == 1)
		{
			print(1, ((t_philo *)arg)->nb, (t_philo *)arg);
			((t_philo *)arg)->state = 2;
		}
		if (((t_philo *)arg)->state == 2 && check_run(((t_philo *)arg)) == 1)
		{
			if (((t_philo *)arg)->lfork == ((t_philo *)arg)->rfork)
			{
				pthread_mutex_lock(&(((t_philo *)arg)->lfork->lock));
				((t_philo *)arg)->lhandedf = ((t_philo *)arg)->lfork;
				print(2, ((t_philo *)arg)->nb, (t_philo *)arg);
				return (NULL);
			}
			if (((t_philo *)arg)->nb % 2 == 0)
			{
				pthread_mutex_lock(&(((t_philo *)arg)->lfork->lock));
				((t_philo *)arg)->lhandedf = ((t_philo *)arg)->lfork;
				print(2, ((t_philo *)arg)->nb, (t_philo *)arg);
				pthread_mutex_lock(&(((t_philo *)arg)->rfork->lock));
				((t_philo *)arg)->rhandedf = ((t_philo *)arg)->rfork;
				print(2, ((t_philo *)arg)->nb, (t_philo *)arg);
			}
			else
			{
				pthread_mutex_lock(&(((t_philo *)arg)->rfork->lock));
				((t_philo *)arg)->rhandedf = ((t_philo *)arg)->rfork;
				print(2, ((t_philo *)arg)->nb, (t_philo *)arg);
				pthread_mutex_lock(&(((t_philo *)arg)->lfork->lock));
				((t_philo *)arg)->lhandedf = ((t_philo *)arg)->lfork;
				print(2, ((t_philo *)arg)->nb, (t_philo *)arg);
			}
		}
		if (((t_philo *)arg)->lhandedf && ((t_philo *)arg)->rhandedf && check_run(((t_philo *)arg)) == 1)
		{
			print(3, ((t_philo *)arg)->nb, (t_philo *)arg);
			usleep(((t_philo *)arg)->tte * 1000);
			updateeat(((t_philo *)arg));
			((t_philo *)arg)->rhandedf = NULL;
			pthread_mutex_unlock(&(((t_philo *)arg)->rfork->lock));
			((t_philo *)arg)->lhandedf = NULL;
			pthread_mutex_unlock(&(((t_philo *)arg)->lfork->lock));
			((t_philo *)arg)->state = 1;
		}
		if (((t_philo *)arg)->state == 1 && check_run(((t_philo *)arg)) == 1)
		{
			print(4, ((t_philo *)arg)->nb, (t_philo *)arg);
			usleep(((t_philo *)arg)->tts * 1000);
			((t_philo *)arg)->state = 0;
		}
	}
	return (NULL);
}

void	launch_routine(t_table	*table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(table->mu_hour));
	table->start_hour = get_time_in_ms();
	pthread_mutex_unlock(&(table->mu_hour));
	while (table->philos[i].lfork != NULL)
	{
		pthread_create(&(table->philos[i].thread_id), NULL, routine,
			&(table->philos[i]));
		++i;
	}
}
