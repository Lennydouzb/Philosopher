/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:00:08 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/02 17:02:47 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	init(t_philo *philos, t_fork *forks, int *nb)
{
	int	i;

	i = 0;
	while (i < *nb)
	{
		forks[i].valid_mutex = pthread_mutex_init(&(forks[i].lock), NULL);	
		if (forks[i].valid_mutex != 0)
			return ;
		forks[i].nb = i;
		forks[i].islock = 0;
		++i;
	}
	i = 1;
	philos[0].nb = 0;
	philos[0].lfork = &(forks[0]);
	while (i < *nb)
	{
		philos[i].nb = i;
		philos[i].lfork = &(forks[i]);
		philos[i].rfork = &(forks[i - 1]);
		++i;
	}
	philos[0].rfork = &(forks[i - 1]);
}
