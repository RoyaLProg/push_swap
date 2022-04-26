/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:48:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/26 16:45:19 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	possible case :
	1 2 3 - already sorted
	1 3 2 - rra sa
	2 1 3 - sa 
	2 3 1 - rra 
	3 1 2 - ra 
	3 2 1 - rra rra sa 
*/
void	case3(t_stack *stackA, t_stack *stackB)
{
	if (is_sorted(stackA, stackB))
		return ;
	if (stackA->tab[0] < stackA->tab[1] && stackA->tab[1] > stackA->tab[2]
		&& stackA->tab[0] < stackA->tab[2])
	{
		push_rra(stackA);
		push_sa(stackA);
	}
	else if (stackA->tab[0] > stackA->tab[1] && stackA->tab[0] < stackA->tab[2])
		push_sa(stackA);
	else if (stackA->tab[0] < stackA->tab[1] && stackA->tab[0] > stackA->tab[2])
		push_rra(stackA);
	else if (stackA->tab[2] > stackA->tab[1])
		push_ra(stackA);
	else if (stackA->tab[1] > stackA->tab[2])
	{
		push_rra(stackA);
		push_rra(stackA);
		push_sa(stackA);
	}
}

