/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:49:08 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/02 10:55:39 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
	* ra rb rr rra rrb rrr
	Le tableau suivant est constitué de chaque coup a effectuer dans la stack A 
	pour le deplacer à la bonne position dans la stack B

	! ne pas oubliez de rajouter + 1
	* COST CALCULATION

	* @param size : taille de la stack A
*/
static int	**create_cost_tab(size_t size)
{
	int		**v;
	size_t	i;
	size_t	j;

	i = -1;
	v = (int **)malloc(sizeof(int *) * size);
	if (v == NULL)
		return (v);
	while (++i < size)
	{
		v[i] = (int *)malloc(sizeof(int) * 6);
		if (v[i] == NULL)
		{
			free_tab(v);
			return (NULL);
		}
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < 6)
			v[i][j] = 0;
	}
	return (v);
}

static int	*calculate_cost(t_stack *stackA, t_stack *stackB,
						size_t x, int *cost)
{
	size_t	i;
	size_t	j;
	size_t	n;

	if (x >= stackA->size / 2)
		cost[3] += stackA->size - x;
	else
		cost[0] += x;
	return (cost);
	while (++i < stackA->size)
	{
		if (stackA->tab[i] < stackB->tab[x])
		{
			n = i;
			break ;
		}
	}
	if (n >= stackB->size / 2)
		cost[4] += stackB->size - n;
	else
		cost[1] += n;
	optimize_cost(cost);
	return (cost);
}

int	**get_cost_tab(t_stack *stackA, t_stack *stackB)
{
	int		**cost_tab;
	size_t	i;

	cost_tab = create_cost_tab(stackA->size);
	if (cost_tab == NULL)
		return (NULL);
	i = -1;
	while (++i < stackA->size)
	{
		cost_tab[i] = calculate_cost(stackA, stackB, i, 0);
	}
	return (cost_tab);
}
