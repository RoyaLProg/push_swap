/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:49:08 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/08 17:00:04 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(int **tab)
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

void	init_tab(int **tab, size_t size)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < 6)
			tab[i][j] = 0;
	}
}

/*
	* ra rb rr rra rrb rrr
	Le tableau suivant est constitué de chaque coup a effectuer dans la stack A 
	pour le deplacer à la bonne position dans la stack B

	! ne pas oubliez de rajouter + 1 (meme si useless)
	* COST CALCULATION

	* @param size : taille de la stack A
*/

void	debug(t_stack *stackA, t_stack *stackB, int **cost)
{
	size_t	i;

	i = 0;
	printf("\n\nstackA\t\t\tstackB\n");
	while (i < stackA->size)
	{
		printf("%d", stackA->tab[i]);
		if (i < stackB->size)
			printf("\t\t\t%d\t[%d %d %d %d %d %d] %lu\n", stackB->tab[i], cost[i][0], cost[i][1], cost[i][2], cost[i][3], cost[i][4], cost[i][5], get_cost(cost[i]));
		else
			printf("\t\t\t\t[%d %d %d %d %d %d] %lu\n", cost[i][0], cost[i][1], cost[i][2], cost[i][3], cost[i][4], cost[i][5], get_cost(cost[i]));
		i++;
	}
	if (i >= stackB->size)
	{
		printf("\n\n");
		return ;
	}
	while (i < stackB->size)
	{
		printf("\t\t\t%d\n", stackB->tab[i]);
		i++;
	}
	printf("\n\n");
}

static int	**create_cost_tab(size_t size)
{
	int		**v;
	size_t	i;

	i = -1;
	v = (int **)malloc(sizeof(int *) * (size + 1));
	if (v == NULL)
		return (v);
	while (++i < size)
	{
		v[i] = (int *)malloc(sizeof(int) * 6 + 1);
		if (v[i] == NULL)
		{
			free_tab(v);
			return (NULL);
		}
	}
	init_tab(v, size);
	v[size] = NULL;
	return (v);
}

static int	*calculate_cost(t_stack *stackA, t_stack *stackB,
						size_t x, int *cost)
{
	if (x >= stackA->size / 2 && stackA->size > 1)
		cost[3] += stackA->size - x;
	else if (stackA->size > 1)
		cost[0] += x;
	if (stackB->size < 2)
		return (cost);
	get_b_movement(cost, x, stackA, stackB);
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
		cost_tab[i] = calculate_cost(stackA, stackB, i, cost_tab[i]);
	debug(stackA, stackB, cost_tab);
	return (cost_tab);
}
