/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:44:51 by ccambium          #+#    #+#             */
/*   Updated: 2022/01/12 11:53:16 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*push_rx(t_stack stack)
{
	int		temp;
	int		*tab;
	size_t	size;

	size = stack.size;
	tab = stack.tab;
	if (size < 2)
		return (stack);
}
