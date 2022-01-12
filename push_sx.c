/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:09:04 by ccambium          #+#    #+#             */
/*   Updated: 2022/01/12 11:53:26 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	*push_sx(t_stack stack)
{
	int		temp;
	int		*tab;
	size_t	size;

	size = stack.size;
	tab = stack.tab;
	if (size < 2)
		return (stack);
	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
	return (stack);
}

int	*push_sa(t_stack stack)
{
	write(1, "sa\n");
	return (push_sx(stack));
}

int	*push_sb(t_stack stack)
{
	write(1, "sb\n");
	return (push_sx(stack));
}

void	push_ss(t_stack stackA, t_stack stackB)
{
	write(1, "ss\n");
	stackA = push_sx(stackA);
	stackB = push_sx(stackB);
	return ;
}
