/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:44:51 by ccambium          #+#    #+#             */
/*   Updated: 2022/01/12 12:30:21 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_stack	push_rx(t_stack stack)
{
	int		temp;
	int		*tab;
	size_t	i;	
	size_t	size;

	size = stack.size;
	tab = stack.tab;
	if (size < 2)
		return (stack);
	temp = tab[0];
	i = 1;
	while (++i < size)
		tab[i - 1] = tab[i];
	tab[size - 1] = temp;
	return (stack);
}

t_stack	push_ra(t_stack stack)
{
	write(1, "ra\n");
	return (push_rx(stack));
}

t_stack	push_rb(t_stack stack)
{
	write(1, "rb\n");
	return (push_rx(stack));
}

void	push_rr(t_stack stackA, t_stack stackB)
{
	write(1, "rr\n");
	push_rx(stackA);
	push_rx(stackB);
	return ;
}
