/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizing_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:52:19 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/05 14:30:17 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_cost(int *cost)
{
	if (cost[0] && cost[1])
	{
		cost[2] += ft_min(cost[0], cost[1]);
		cost[0] -= ft_min(cost[0], cost[1]);
		cost[1] -= ft_min(cost[0], cost[1]);
	}
	if (cost[3] && cost[4])
	{
		cost[5] += ft_min(cost[3], cost[4]);
		cost[3] -= ft_min(cost[3], cost[4]);
		cost[4] -= ft_min(cost[3], cost[4]);
	}
}
