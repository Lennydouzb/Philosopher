/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:39:46 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 11:57:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include <sys/time.h>
void	print(int type, int nb)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	if (type == 1)
		printf("%ld %d is thinking\n", t.tv_usec / 1000, nb);
	if (type == 2)
		printf("%ld %d has taken a fork\n", t.tv_usec / 1000, nb);
	if (type == 3)
		printf("%ld %d is eating\n", t.tv_usec / 1000, nb);
	if (type == 4)
		printf("%ld %d is sleeping\n", t.tv_usec / 1000, nb);
	if (type == 5)
		printf("%ld %d died\n", t.tv_usec / 1000, nb);
}
void	*routine(void *arg)
{

	if (((t_philo *)arg)->state == 0)
		printf("%ld %d is thinking", t.tv_usec / 1000, ((t_philo *)arg)->nb);
	if (((t_philo *)arg)->lfork->islock == 0
			&& ((t_philo *)arg)->rfork->islock == 0)
	{
		phtread_mutex_lock(&(((t_philo *)arg)->lfork->lock));
		((t_philo *)arg)->lfork->islock = 1;
		((t_philo *)arg)->lhandedf = ((t_philo *)arg)->lfork;
		printf("%ld %d has taken a fork", t.tv_usec / 1000, ((t_philo *)arg)->nb);
	return (NULL);
}

void	launch_routine(t_table	*table)
{
	int	i;

	i = 0;
	while (table->philos[i].lfork == NULL)
	{
		pthread_create(&(table->philos[i].thread_id), NULL, routine,
				&(table->philos[i]));
		pthread_detach(table->philos[i].thread_id);
		++i;
	}
}
