/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:28:01 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 17:30:38 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	*monitor_routine(void *arg)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (i == 0 && flag == 1)
	{
		while (((t_table *)arg)->philos[i].lfork != NULL && flag == 1)
		{
			flag = checkeat(&(((t_table *)arg)->philos[i]));
			++i;
		}
		i = 0;
	}
	((t_table *)arg)->running = 0;
	return (NULL);
}
