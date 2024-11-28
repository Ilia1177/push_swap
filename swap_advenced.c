/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_advenced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:49:33 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 15:50:17 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_list **a, t_list **b, t_count *cpt)
{
	cpt->counter++;
	rotate(a, 0, cpt);
	rotate(b, 0, cpt);
	ft_printf("rr\n");
}

void	r_rotate_both(t_list **a, t_list **b, t_count *cpt)
{
	cpt->counter++;
	r_rotate(a, -1, cpt);
	r_rotate(b, -1, cpt);
	ft_printf("rrr\n");
}

void	push_all(t_list **stk, t_list **obj, t_count *cpt, int print)
{
	while (ft_lstsize(*obj))
		push(stk, obj, cpt, print);
}

void	push_back(t_list **a, t_list **b, t_count *count, int print)
{
	push(a, b, count, print);
	rotate(a, 1, count);
}
