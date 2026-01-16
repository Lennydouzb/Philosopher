/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:49:24 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/16 23:39:54 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	ft_atol(const char *nptr)
{
	int			coef;
	int			k;
	long long	nbr;

	k = 0;
	coef = 1;
	nbr = 0;
	while ((nptr[k] >= 9 && nptr[k] <= 13) || nptr[k] == ' ')
		++k;
	if (nptr[k] == '-' || nptr[k] == '+')
	{
		if (nptr[k] == '-')
			coef *= -1;
		++k;
	}
	while (nptr[k] >= '0' && nptr[k] <= '9')
	{
		nbr = nbr * 10 + nptr[k] - '0';
		++k;
	}
	return (nbr * coef);
}

int	ft_atoi(const char *nptr)
{
	int	coef;
	int	k;
	int	nbr;

	k = 0;
	coef = 1;
	nbr = 0;
	while ((nptr[k] >= 9 && nptr[k] <= 13) || nptr[k] == ' ')
		++k;
	if (nptr[k] == '-' || nptr[k] == '+')
	{
		if (nptr[k] == '-')
			coef *= -1;
		++k;
	}
	while (nptr[k] >= '0' && nptr[k] <= '9')
	{
		nbr = nbr * 10 + nptr[k] - '0';
		++k;
	}
	return (nbr * coef);
}
