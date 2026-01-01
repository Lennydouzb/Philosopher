/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:39:20 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/01 21:27:36 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
typedef struct s_fork
{
	unsigned int	nb;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philo
{
	t_fork			*lfork;
	t_fork			*rfork;
	t_fork			*lhandedf;
	t_fork			*rhandedf;
	pthread_t       thread_id;
	unsigned int	nb;
	
}	t_philo;
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
#endif
