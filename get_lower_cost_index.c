/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lower_cost_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:27:37 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/05 13:39:40 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_cost(int *cost)
{
	size_t	i;
	size_t	v;

	i = -1;
	while (++i < 6)
		v += cost[i];
	return (v);
}

size_t	get_lower_cost_index(int **cost_tab, size_t size)
{
	size_t	i;
	size_t	min;

	i = -1;
	min = 0;
	while (++i < size)
		if (get_cost(cost_tab[i]) < get_cost(cost_tab[min]))
			min = i;
	return (min);
}
