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
    t_list *tmp;

    if (!*stack || !(*stack)->next)
        return;
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
	t_list *tmp;

	if (!*stack || (ft_lstsize(*stack) == 1))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	if (print)
		ft_printf("r%s\n", (*stack)->name);
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr");
}

// last become first
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

void	r_rotate_both(t_list **a, t_list **b)
{
	r_rotate(a, 0);
	r_rotate(b, 0);
	ft_printf("rrr");
}	

t_list	*get_min(t_list *stack)
{
	t_list *min;

	min = stack;
	while (stack)
	{
		if (ft_lstcmp(min, stack) > 0)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*get_max(t_list *stack)
{
	t_list *max;

	max = stack;
	while (stack)
	{
		if (ft_lstcmp(max, stack) < 0)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
void	ft_lstprint(t_list *stack)
{
	if (!stack)
		return ;
	while(stack->next)
	{
		ft_printf("%d, ", *(int *)(stack->content));
		stack = stack->next;
	}
		ft_printf("%d", *(int *)(stack->content));
}

void	ft_lstinit(t_list **stack, char **av, int size)
{
	int	i;
	t_list *new;
	int	*content;

	i = 0;
	while (i < size)
	{
		content = (int *)malloc(sizeof(int));
		*content = ft_atoi(av[i + 1]);
		new = ft_lstnew(content);
		new->name = ft_strdup("a");
		ft_lstadd_back(stack, new);
		i++;
	}
}

int	ft_lstcmp(t_list *a, t_list *b)
{
	if (!a || !b)
		return (0);
	return (*(int *)a->content - *(int *)b->content);
}

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

void	push_last(t_list **a, t_list **b)
{
	r_rotate(b, 1);
	push(a, b);
}

void	push_all(t_list **a, t_list **b)
{
	while (ft_lstsize(*b))
	{
		if (ft_lstcmp(*b, *a) > 0)
			push_back(a, b);
		else if (ft_lstcmp(*b, *a) < 0)
			push(a, b);
	}
}

void	push_back(t_list **a, t_list **b)
{
	push(a, b);
	rotate(a, 1);
}
