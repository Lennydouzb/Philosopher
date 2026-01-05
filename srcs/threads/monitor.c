/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:28:01 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 18:06:17 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include <pthread.h>

void	*monitor_routine(void *arg)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (flag == 1)
	{
		while (((t_table *)arg)->philos[i].lfork != NULL && flag == 1)
		{
			flag = checkeat(&(((t_table *)arg)->philos[i]));
			++i;
		}
		i = 0;
	}
	pthread_mutex_lock(&(((t_table *)arg)->lockrun));
	((t_table *)arg)->running = 0;
	pthread_mutex_unlock(&(((t_table *)arg)->lockrun));
	return (NULL);
}
