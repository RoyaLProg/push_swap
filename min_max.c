/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:05:06 by ccambium          #+#    #+#             */
/*   Updated: 2022/05/19 23:09:13 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	ft_min(int x, int y)
{
	if (x > y)
		return (y);
	return (x);
}
