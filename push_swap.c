/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:52:29 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/16 08:35:31 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stackA, t_stack *stackB)
{
	if (stackA->size == 2)
		case2(stackA);
	else if (stackA->size == 3)
		case3(stackA, stackB);
	else if (stackA->size < 46)
		case4to45(stackA, stackB);
	else
		caseover45(stackA, stackB);
	if (stackA->tab != NULL)
		free(stackA->tab);
	if (stackB->tab != NULL)
		free(stackB->tab);
}

int	main(int ac, char **av)
{
	t_stack	stacka;
	t_stack	stackb;

	stacka.tab = NULL;
	stackb.tab = NULL;
	stacka.size = 0;
	stackb.size = 0;
	if (ac == 1)
		return (1);
	if (!verification(av, ac))
		return (write(1, "Error\n", 6));
	add_to_list(&stacka, ac, av);
	if (stacka.tab == NULL)
		return (1);
	push_swap(&stacka, &stackb);
	return (0);
}
