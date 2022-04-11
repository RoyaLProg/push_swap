/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_less100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 03:01:05 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/09 13:43:03 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	case_less100(t_stack *stackA, t_stack *stackB)
{
	while (!is_sorted(stackA, stackB))
	{
		if (stackA->tab[0] > stackA->tab[1])
		{
			if (stackA->tab[0] > stackA->tab[2])
				push_sa(stackA);
			else
				push_ra(stackA);
		}
		else if (stackA->tab[1] > stackA->tab[2])
			push_sa(stackA);
		else
			push_ra(stackA);
	}
}
