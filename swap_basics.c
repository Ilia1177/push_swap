#include "push_swap.h"

t_list	*get_min(t_list *stack)
{
	t_list	*min;

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
	t_list	*max;

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
	while (stack->next)
	{
		ft_printf("%d, ", *(int *)(stack->content));
		stack = stack->next;
	}
	ft_printf("%d", *(int *)(stack->content));
}

void	ft_lstinit(t_list **stack, char **av, int size, int flag)
{
	int		i;
	int		j;
	int		*content;
	t_list	*new;

	j = 0;
	i = 1;
	while (i <= size)
	{
		if (flag == i)
			j++;
		content = (int *)malloc(sizeof(int));
		*content = ft_atoi(av[i + j]);
		new = ft_lstnew(content);
		new->name = "a";
		ft_lstadd_back(stack, new);
		i++;
	}
}

void	push_last(t_list **a, t_list **b)
{
	r_rotate(b, 1);
	push(a, b);
}
