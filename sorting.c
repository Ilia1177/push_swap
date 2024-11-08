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

int	ft_lstcmp(t_list *a, t_list *b)
{
	if (!a || !b)
		return (0);
	return (*(int *)a->content - *(int *)b->content);
}

void	print_debug(t_list *a, t_list *b, int count)
{
	ft_printf("| STACK A : ");
	ft_lstprint(a);
	ft_printf("\n");
	ft_printf("| STACK B : ");
	ft_lstprint(b);
	ft_printf("\n");
	ft_printf("| nb of operation : %d\n", count);
}

void	mixed_sort(t_list **a, t_list **b, int debug)
{
	int			size;
	t_list		*current;
	t_list		*max;
	t_list		*min;
	static int	count;

	size = ft_lstsize(*a);
	while (!is_sorted(*a, size))
	{
		count++;
		current = *a;
		max = get_max(*a);
		min = get_min(*a);
		if ((is_sorted(*a, ft_lstsize(*a)) && *b))
			push_all(a, b);
		else if (ft_lstcmp(current, max) == 0
			&& !is_sorted(min, ft_lstsize(min)))
			push_back(b, a);
		else if (ft_lstcmp(current, min) == 0
			&& !is_sorted(min, ft_lstsize(min)))
			push(b, a);
		else if (ft_lstcmp(current, current->next) > 0
			&& ft_lstcmp(current, max))
			swap(a, 1);
		else if (!is_sorted(*a, ft_lstsize(*a)))
			rotate(a, 1);
		if (debug)
			print_debug(*a, *b, count);
	}
}

void	radix_sort(t_list **a, t_list **b)
{
	int		size;
	int		max_num;
	int		max_bits;
	int		i;
	int		j;
	int		num;
	t_list	*max;

	max_bits = 0;
	max = get_max(*a);
	max_num = *(int *)max->content;
	size = ft_lstsize(*a);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = *(int *)(*a)->content;
			if (((num >> i) & 1) == 1)
				rotate(a, 1);
			else
				push(b, a);
			j++;
		}
		while (ft_lstsize(*b))
			push(a, b);
		i++;
	}
}
