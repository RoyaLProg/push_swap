/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifcations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:21:33 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/08 02:13:15 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_all_int(char **argv, int argc)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}

static int	min_max(char **argv, int argc)
{
	long int	x;
	int			i;

	i = 0;
	while (i < argc)
	{
		x = ft_atol(argv[i]);
		if (x > 2147483647 || x < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

static int	not_twice(char **argv, int argc)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verification(char **argv, int argc)
{
	if (is_all_int(argv, argc))
		return (0);
	if (min_max(argv, argc))
		return (0);
	if (not_twice(argv, argc))
		return (0);
	return (1);
}
