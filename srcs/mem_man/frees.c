/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:36:04 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/15 19:13:36 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include <pthread.h>

void	freeforksandphilos(t_fork *forks, t_philo *philos)
{
	free (forks);
	free (philos);
}

void	smartdestroy(void *ptr)
{
	if (ptr != NULL)
		pthread_mutex_destroy((pthread_mutex_t *)ptr);
}

void	destroy(t_table *table)
{
	int	i;

	i = 0;
	smartdestroy(&(table->lock));
	smartdestroy(&(table->lockrun));
	smartdestroy(&(table->lockstart));
	smartdestroy(&(table->mu_hour));
	while (i < table->nb_philo)
	{
		smartdestroy(&(table->forks[i].lock));
		++i;
	}
	i = 0;
	while (i < table->nb_philo)
	{
		smartdestroy(&(table->philos->lockeat));
		smartdestroy(&(table->philos->locklasteat));
		++i;
	}
	freeforksandphilos(table->forks, table->philos);
}
