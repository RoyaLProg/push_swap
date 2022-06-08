/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_b_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:36:28 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/08 17:53:11 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_tmp(int tmp[2])
{
	tmp[0] = 0;
	tmp[1] = 0;
}

static void	retry_b_movement(t_stack *stackB, int *cost)
{
	int			tmp[2];
	int			max;
	size_t		i;

	max = -2147483648;
	init_tmp(tmp);
	i = -1;
	while (++i < stackB->size)
	{
		if (stackB->tab[i] > max)
		{
			max = stackB->tab[i];
			if (i > stackB->size / 2)
			{
				tmp[1] = stackB->size - i;
				tmp[0] = 0;
			}
			else
			{
				tmp[1] = 0;
				tmp[0] = i;
			}
		}
	}
	cost[1] += tmp[0];
	cost[4] += tmp[1];
}

void	get_b_movement(int *cost, int x, t_stack *stackA, t_stack *stackB)
{
	size_t	i;
	int		target;
	char	trigger;

	i = -1;
	trigger = 0;
	target = -2147483648;
	while (++i < stackB->size)
	{
		if ((i == 0 || target < stackB->tab[i])
			&& stackB->tab[i] < stackA->tab[x])
		{
			target = stackB->tab[i];
			if (i > stackB->size / 2)
			{
				cost[1] = 0;
				cost[4] = stackB->size - i;
			}
			else
			{
				cost[1] = i;
				cost[4] = 0;
			}
			trigger = 1;
		}
	}
	if (trigger == 0)
		retry_b_movement(stackB, cost);
}
