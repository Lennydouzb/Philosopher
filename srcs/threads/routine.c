/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:39:46 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 17:25:29 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	print(int type, int nb, t_philo *phi)
{
	pthread_mutex_lock(&(phi->table->lock));
	if (type == 1)
		printf("%lld %d is thinking\n", get_time_in_ms(), nb);
	if (type == 2)
		printf("%lld %d has taken a fork\n", get_time_in_ms(), nb);
	if (type == 3)
		printf("%lld %d is eating\n", get_time_in_ms(), nb);
	if (type == 4)
		printf("%lld %d is sleeping\n", get_time_in_ms(), nb);
	if (type == 5)
		printf("%lld %d died\n", get_time_in_ms(), nb);
	pthread_mutex_unlock(&(phi->table->lock));
}

void	*routine(void *arg)
{
	if (((t_philo *)arg)->nb % 2 == 0)
		usleep(((t_philo *)arg)->tte / 5);
	while (1 && ((t_philo *)arg)->table->running == 1)
	{
		if (((t_philo *)arg)->state == 0 && ((t_philo *)arg)->table->running == 1)
		{
			print(1, ((t_philo *)arg)->nb, (t_philo *)arg);
			((t_philo *)arg)->state = 2;
		}
		if (((t_philo *)arg)->state == 2 && ((t_philo *)arg)->table->running == 1)
		{
			pthread_mutex_lock(&(((t_philo *)arg)->lfork->lock));
			((t_philo *)arg)->lhandedf = ((t_philo *)arg)->lfork;
			print(2, ((t_philo *)arg)->nb, (t_philo *)arg);
			pthread_mutex_lock(&(((t_philo *)arg)->rfork->lock));
			((t_philo *)arg)->rhandedf = ((t_philo *)arg)->rfork;
			print(2, ((t_philo *)arg)->nb, (t_philo *)arg);
		}
		if (((t_philo *)arg)->lhandedf && ((t_philo *)arg)->rhandedf && ((t_philo *)arg)->table->running == 1)
		{
			print(3, ((t_philo *)arg)->nb, (t_philo *)arg);
			usleep(((t_philo *)arg)->tte);
			updateeat(((t_philo *)arg));
			((t_philo *)arg)->rhandedf = NULL;
			pthread_mutex_unlock(&(((t_philo *)arg)->rfork->lock));
			((t_philo *)arg)->lhandedf = NULL;
			pthread_mutex_unlock(&(((t_philo *)arg)->lfork->lock));
			((t_philo *)arg)->state = 1;
		}
		if (((t_philo *)arg)->state == 1 && ((t_philo *)arg)->table->running == 1)
		{
			print(4, ((t_philo *)arg)->nb, (t_philo *)arg);
			usleep(((t_philo *)arg)->tts);
			((t_philo *)arg)->state = 0;
		}
	}
	return (NULL);
}

void	launch_routine(t_table	*table)
{
	int	i;

	i = 0;
	while (table->philos[i].lfork != NULL)
	{
		pthread_create(&(table->philos[i].thread_id), NULL, routine,
			&(table->philos[i]));
		++i;
	}
}
