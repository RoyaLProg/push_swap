/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:37:44 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/26 14:41:33 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case2(t_stack *stackA, t_stack *stackB)
{
	if (stackA->tab[0] > stackA->tab[1])
		push_sa(stackA);
}
