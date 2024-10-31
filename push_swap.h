/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:18:29 by npolack           #+#    #+#             */
/*   Updated: 2024/10/31 14:37:12 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/srcs/include/libft.h"

void	ft_lstprint(t_list *stack);
void	ft_lstinit(t_list **stack, char **av, int size);

void	swap(t_list **stack, int print);
void	swap_both(t_list **a, t_list **b);
void	push(t_list **a, t_list **b);
void	rotate(t_list **stack, int print);
void	rotate_both(t_list **a, t_list **b);
void	r_rotate(t_list **stack, int print);
void	ft_lstprint(t_list *stack);
void	ft_lstinit(t_list **stack, char **av, int size);
void	sort_stack(t_list **a, t_list **b);

#endif
