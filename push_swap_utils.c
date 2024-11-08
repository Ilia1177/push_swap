/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:17:42 by npolack           #+#    #+#             */
/*   Updated: 2024/10/31 17:17:25 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, int print)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (print)
		ft_printf("s%s\n", (*stack)->name);
}

void	swap_both(t_list **a, t_list **b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss");
}

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	if ((*b)->next)
		*b = (*b)->next;
	else
		*b = NULL;
	if (tmp->name[0] == 'a')
		tmp->name = "b";
	else if (tmp->name[0] == 'b')
		tmp->name = "a";
	ft_lstadd_front(a, tmp);
	ft_printf("p%s\n", tmp->name);
}

// First become last
void	rotate(t_list **stack, int print)
{
	t_list	*tmp;

	if (!*stack || (ft_lstsize(*stack) == 1))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	if (print)
		ft_printf("r%s\n", (*stack)->name);
}

// Last become first
void	r_rotate(t_list **stack, int print)
{
	t_list	*tmp;
	int		size;

	if (!*stack || (ft_lstsize(*stack) == 1))
		return ;
	size = ft_lstsize(*stack);
	ft_lstadd_front(stack, ft_lstlast(*stack));
	tmp = *stack;
	while (size > 1)
	{
		tmp = tmp->next;
		size--;
	}
	tmp->next = NULL;
	if (print)
		ft_printf("rr%s\n", (*stack)->name);
}
