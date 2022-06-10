/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:36:28 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/10 08:35:23 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	retry(int *cost, t_stack *stackA, int target)
{
	size_t	i;
	int		min;

	i = -1;
	min = stackA->tab[0];
	while (++i < stackA->size)
	{
		if (stackA->tab[i] < min && stackA->tab[i] > target)
		{
			min = stackA->tab[i];
			cost[0] = my_ternarie(i < stackA->size / 2, i, 0);
			cost[3] = my_ternarie(i < stackA->size / 2, 0, stackA->size - i);
		}
	}
}

void	get_a_movement(int *cost, int x, t_stack *stackA, t_stack *stackB)
{
	size_t	i;
	int		max;
	char	trigger;

	trigger = 0;
	max = stackA->tab[0];
	i = -1;
	while (++i < stackA->size)
	{
		if (stackA->tab[i] >= max && stackA->tab[i] < stackB->tab[x])
		{
			max = stackA->tab[i];
			cost[0] = my_ternarie(i < stackA->size / 2, i + 1, 0);
			cost[3] = my_ternarie(i < stackA->size / 2, 0,
					stackA->size - i - 1);
			trigger = 1;
		}
	}
	if (!trigger)
		retry(cost, stackA, stackB->tab[x]);
}
