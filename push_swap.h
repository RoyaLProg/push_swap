/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:13:40 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/09 00:46:46 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack{
	size_t	size;
	int		*tab;
}	t_stack;

t_stack			*push_sa(t_stack *stack);
t_stack			*push_sb(t_stack *stack);
void			push_ss(t_stack *stackA, t_stack *stackB);
void			push_pa(t_stack *stackA, t_stack *stackB);
void			push_pb(t_stack *stackA, t_stack *stackB);
t_stack			*push_ra(t_stack *stack);
t_stack			*push_rb(t_stack *stack);
void			push_rr(t_stack *stackA, t_stack *stackB);
t_stack			*push_rra(t_stack *stack);
t_stack			*push_rrb(t_stack *stack);
void			push_rrr(t_stack *stackA, t_stack *stackB);
void			*ft_calloc(size_t nmemb, size_t size);
long int		ft_atol(const char *nptr);
long long int	ft_atoll(const char *nptr);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
void			add_to_list(t_stack *a, int ac, char **av);
int				verification(char **argv, int argc);
void			ft_bzero(void *s, size_t n);
int				is_sorted(t_stack *stackA, t_stack *stackB);
void			case2(t_stack *stackA);
size_t			ft_strlen(const char *s);

#endif
