/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:49:42 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/17 13:45:40 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static int	checkmax(char **av)
{
	if (ft_atol(av[1]) > 400 || ft_atol(av[1]) <= 0)
		return (0);
	if (ft_atol(av[2]) > 2147483647 || ft_atol(av[2]) <= 0)
		return (0);
	if (ft_atol(av[3]) > 2147483647 || ft_atol(av[3]) <= 0)
		return (0);
	if (ft_atol(av[4]) > 2147483647 || ft_atol(av[4]) <= 0)
		return (0);
	if (av[5])
	{
		if (ft_atol(av[5]) > 2147483647 || ft_atol(av[5]) <= 0)
			return (0);
	}
	return (1);
}

int	checkav(char **av)
{
	int	i;

	if (ft_strsisnum(av[1]) == 0)
		return (0);
	else
	{
		if (ft_atoi(av[1]) == 0)
			return (0);
	}
	if (ft_strsisnum(av[2]) == 0)
		return (0);
	if (ft_strsisnum(av[3]) == 0)
		return (0);
	if (ft_strsisnum(av[4]) == 0)
		return (0);
	if (av[5])
	{
		if (ft_strsisnum(av[5]) == 0)
			return (0);
	}
	i = checkmax(av);
	return (i);
}
