/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caseover45.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:46:30 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/05 15:51:16 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// * ra rb rr rra rrb rrr

void	proceed_push_cost(int *cost, t_stack *stackA, t_stack *stackB)
{
	while (cost[0]-- > 0)
		push_ra(stackA);
	while (cost[1]-- > 0)
		push_rb(stackB);
	while (cost[2]-- > 0)
		push_rr(stackA, stackB);
	while (cost[3]-- > 0)
		push_rra(stackA);
	while (cost[4]-- > 0)
		push_rrb(stackB);
	while (cost[5]-- > 0)
		push_rrr(stackA, stackB);
	push_pb(stackA, stackB);
}

void	caseover45(t_stack *stackA, t_stack *stackB)
{
	size_t	x;
	int		**cost_tab;

	if (is_sorted(stackA, stackB))
		return ;
	lis_and_push(stackA, stackB);
	while (stackA->size > 0)
	{
		cost_tab = get_cost_tab(stackA, stackB);
		x = get_lower_cost_index(cost_tab, stackA->size);
		proceed_push_cost(cost_tab[x], stackA, stackB);
		free_tab(cost_tab);
	}
	while (stackB->size > 0)
		push_pa(stackA, stackB);
}
