/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizing_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:52:19 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/10 04:40:52 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_cost(int *cost)
{
	int	x;

	if (cost[0] && cost[1])
	{
		x = ft_min(cost[0], cost[1]);
		cost[2] += x;
		cost[0] -= x;
		cost[1] -= x;
	}
	if (cost[3] && cost[4])
	{
		x = ft_min(cost[3], cost[4]);
		cost[5] += x;
		cost[3] -= x;
		cost[4] -= x;
	}
}
