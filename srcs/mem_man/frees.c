/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:36:04 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 21:05:04 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include <pthread.h>

void	freeforksandphilos(t_fork *forks, t_philo *philos)
{
	free (forks);
	free (philos);
}

void	freeeverything(t_table *table, char **arg)
{
	int	i;

	i = 0;
	while (i < ft_atoi(arg[1]))
	{
		pthread_mutex_destroy(&(table->philos[i].lockeat));
		pthread_mutex_destroy(&(table->forks[i].lock));
		++i;
	}
	pthread_mutex_destroy(&(table->lockrun));
	pthread_mutex_destroy(&(table->lock));
	freeforksandphilos(table->forks, table->philos);
}
