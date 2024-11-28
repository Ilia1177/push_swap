/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:18:16 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 14:33:48 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack, int size)
{
	if (!stack)
		return (0);
	while (stack->next && size != 0)
	{
		if (ft_lstcmp(stack, stack->next) > 0)
			return (0);
		stack = stack->next;
		size--;
	}
	if (size != 1)
		return (0);
	return (1);
}

int	is_revsorted(t_list *stack, int size)
{
	if (!stack)
		return (-1);
	while (stack->next && size != 0)
	{
		if (ft_lstcmp(stack, stack->next) < 0)
			return (0);
		stack = stack->next;
		size--;
	}
	if (size != 1)
		return (0);
	return (1);
}

int	ft_lstcmp(t_list *a, t_list *b)
{
	if (!a || !b)
		return (0);
	return (*(int *)a->content - *(int *)b->content);
}

void	print_debug(t_list *a, t_list *b, t_count *cpt)
{
	if (a)
	{
		ft_printf("┉┉┉┉┉ STACK %s", a->name);
		ft_lstprint(a);
		ft_printf("\n");
	}
	if (b)
	{
		ft_printf("┉┉┉┉┉ STACK %s", b->name);
		ft_lstprint(b);
		ft_printf("\n");
	}
	ft_printf("┉┉┉┉┉ nb of operation : %d\n\n\n", cpt->counter);
}

// main test -- OK -> TO CLEAN
void	mixed_sort(t_list **a, t_list **b, int print, t_count *cpt)
{
	int			size;
	t_list		*max;
	t_list		*min;

	if (print == 2)
		ft_printf("----- mixed sort\n");
	size = ft_lstsize(*a);
	while (!is_sorted(*a, size))
	{
		max = get_max(*a);
		min = get_min(*a);
		if ((is_sorted(*a, ft_lstsize(*a)) && *b))
			push_all(a, b, cpt, print);
		else if (ft_lstcmp(*a, max) == 0
			&& !is_sorted(min, ft_lstsize(min)))
			place_in_between(b, a, cpt, print);
		else if (ft_lstcmp(*a, min) == 0
			&& !is_sorted(min, ft_lstsize(min)))
			place_in_between(b, a, cpt, print);
		else if (ft_lstcmp(*a, (*a)->next) > 0
			&& ft_lstcmp(*a, max))
			swap(a, print, cpt);
		else if (!is_sorted(*a, ft_lstsize(*a)))
			rotate(a, print, cpt);
	}
}
