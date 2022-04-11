/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:57:40 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/09 00:14:52 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stackA, t_stack *stackB)
{
	size_t	i;

	i = 0;
	if (stackB->size != 0)
		return (0);
	if (stackA->size == 0)
		return (1);
	while (i < stackA->size - 1)
	{
		if (stackA->tab[i] > stackA->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
