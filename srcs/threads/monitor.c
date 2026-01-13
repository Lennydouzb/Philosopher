/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:28:01 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/12 23:18:42 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include <pthread.h>

static int	checkallphilos(t_table *table)
{
	int	i;

	i = 0;
	while (table->philos[i].lfork != NULL)
	{
		pthread_mutex_lock(&(table->philos[i].lockeat));
		if (table->philos[i].has_ate < table->musteat)
		{
			pthread_mutex_unlock(&(table->philos[i].lockeat));
			return (1);
		}
		pthread_mutex_unlock(&(table->philos[i].lockeat));
		++i;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (flag == 1)
	{
		flag = checkallphilos(((t_table *)arg));
		while (((t_table *)arg)->philos[i].lfork != NULL && flag == 1)
		{
			flag = checkeat(&(((t_table *)arg)->philos[i]));
			++i;
		}
		i = 0;
		usleep(1000);
	}
	pthread_mutex_lock(&(((t_table *)arg)->lockrun));
	((t_table *)arg)->running = 0;
	pthread_mutex_unlock(&(((t_table *)arg)->lockrun));
	return (NULL);
}
