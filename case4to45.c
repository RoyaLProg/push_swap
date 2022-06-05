/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case4to45.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:36:43 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/05 15:51:36 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	index_of_min(t_stack *stack)
{
	size_t	i;
	size_t	min;

	i = -1;
	min = 0;
	while (++i < stack->size)
		if (stack->tab[i] < stack->tab[min])
			min = i;
	return (min);
}

static void	move_to_top(t_stack *stackA)
{
	size_t	i;
	size_t	index;

	index = index_of_min(stackA);
	i = -1;
	if (index <= stackA->size / 2)
		while (++i < index)
			push_ra(stackA);
	else if (index > stackA->size / 2)
		while (++i < stackA->size - index)
			push_rra(stackA);
}

static int	stack_is_sorted(t_stack *stack)
{
	size_t	i;

	i = 0;
	if (stack->size <= 1)
		return (1);
	while (++i < stack->size)
		if (stack->tab[i - 1] > stack->tab[i])
			return (0);
	return (1);
}

void	case4to45(t_stack *stackA, t_stack *stackB)
{
	if (is_sorted(stackA, stackB))
		return ;
	while (stackA->size > 1 && !stack_is_sorted(stackA))
	{
		if (stackA->size == 2 && !stack_is_sorted(stackA))
		{
			push_sa(stackA);
			continue ;
		}
		move_to_top(stackA);
		push_pb(stackA, stackB);
	}
	while (stackB->size > 0)
		push_pa(stackA, stackB);
}
