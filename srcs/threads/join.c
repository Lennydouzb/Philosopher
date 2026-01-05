/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:57:17 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/05 17:35:12 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include <pthread.h>

void	jointhreads(t_table *table)
{
	int	i;

	i = 0;
	pthread_join(table->monitor, NULL);
	while (table->philos[i].lfork != NULL)
	{
		pthread_join(table->philos[i].thread_id, NULL);
		++i;
	}
}
