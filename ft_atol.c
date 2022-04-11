/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 03:16:32 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/07 03:16:32 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	ft_atol_part2(size_t i, int minus, const char *nptr)
{
	long int	v;

	v = 0;
	while (*(nptr + i) && ft_isdigit(*(nptr + i)))
	{
		v *= 10;
		v += *(nptr + i) - '0';
		i++;
	}
	if (minus)
		v *= -1;
	return (v);
}

long int	ft_atol(const char *nptr)
{
	size_t	i;
	int		minus;

	i = 0;
	minus = 0;
	while (*(nptr + i) == '\f' || *(nptr + i) == '\n' || *(nptr + i) == '\r'
		|| *(nptr + i) == '\t' || *(nptr + i) == '\v' || *(nptr + i) == ' ')
		i++;
	if (*(nptr + i) == '-')
	{
		i++;
		minus = 1;
	}
	else if (*(nptr + i) == '+')
		i++;
	return (ft_atol_part2(i, minus, nptr));
}
