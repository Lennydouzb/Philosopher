/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:39:26 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 16:25:43 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	updateeat(t_philo *philo)
{
	philo->lasteat = get_time_in_ms();
}

int	checkeat(t_philo *philo)
{
	if (get_time_in_ms() - philo->lasteat < philo->ttd)
		return (1);
	print(5, philo->nb, philo);
	return (0);
}

long long	get_time_in_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((long long)((t.tv_sec * 1000) + (t.tv_usec / 1000)));
}
