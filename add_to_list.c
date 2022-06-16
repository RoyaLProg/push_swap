/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:58:06 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/16 08:31:24 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(t_stack *a, int ac, char **av)
{
	int	i;

	a->size = ac - 1;
	a->tab = (int *)malloc(sizeof(int) * ac - 1);
	if (a->tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac - 1)
	{
		a->tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
}
