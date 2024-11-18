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

	if (print)
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

int		cmp_swap(t_list **a, t_count *cpt)
{
	if (!*a || !(*a)->next)
		return (0);
	if (ft_lstcmp(*a, (*a)->next) > 0)
			swap(a, 1, cpt);
	return (ft_lstcmp(*a, (*a)->next));
}

int get_index(t_list *target, t_list *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		if (ft_lstcmp(target, stack) == 0)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}

int	find_closest_inferior_index(t_list *curr, t_list *obj)
{
	int	i;
	int target_i;
	int	diff;

	i = 0;
	diff = 0;
	while (curr)
	{
		if (ft_lstcmp(obj, curr) > 0)
		{
			if (diff > ft_lstcmp(obj, curr) || !diff)
			{
				diff = ft_lstcmp(obj, curr);
				target_i = i;
			}
		}
		i++;
		curr = curr->next;
	}
	if (!diff)
		return (0);
	return (target_i);
}

// move is between -size(a) and +size(a)
int	closest_inferior(t_list *stk, t_list *obj)
{
	int		move;

	if (!stk)
		return (0);
	move = 0;
	if (ft_lstcmp(obj, get_min(stk)) < 0)
		move = get_index(get_max(stk), stk);
	else
		move = find_closest_inferior_index(stk, obj);
	if (move > ft_lstsize(stk) / 2)
		move = (move - ft_lstsize(stk));
	else
		move = move;
	return (move);
}

void	place_in_between(t_list **stk, t_list **obj, t_count *cpt, int print)
{
	int		move;

	if (print == 2)
		ft_printf("----- place in between\n");
	if (!*stk || !(*stk)->next)
		push(stk, obj, cpt, print);
	else
	{
		move = closest_inferior(*stk, *obj);
		while (move)
		{
			if (move < 0)
			{
				r_rotate(stk, print, cpt);
				move++;
			}
			else if (move > 0)
			{
				rotate(stk, print, cpt);
				move--;
			}
		}
		push(stk, obj, cpt, print);
	}
}

int	move_calc(int index, int size)
{
	int move;

	move = 0;
	if (index <= size / 2)
		move = index;
	else if (index > size / 2)
		move = (index - size);
	return (move);
}

int		in_range(t_list *stack, int lowlim, int hilim)
{
	int		i;
	int		closest_index;
	int		min_move;
	int		move;
	t_list	*curr;

	curr = stack;
	i = 0;
	closest_index = -1;
	min_move = ft_lstsize(stack);
	while (curr && ++i)
	{
		if (*(int *)curr->content >= lowlim && *(int *)curr->content <= hilim)
		{
			move = move_calc(i, ft_lstsize(stack));
			if (move < 0)
				move *= -1;
			if (min_move > move)
			{
				min_move = move;
				closest_index = i;
			}
		}
		if (!curr->next && closest_index != -1)
			return (closest_index);
		curr = curr->next;
	}
	return (0);
}

void	bring_index_up(t_list **stk, int index, t_count *cpt, int print)
{
	int	i;

	if (index > ft_lstsize(*stk) / 2)
		i = index - ft_lstsize(*stk);
	else
		i = index;
	while (i)
	{
		if (i < 0)
		{
			r_rotate(stk, print, cpt);
			i++;
		}
		else if (i > 0)
		{
			i--;
			rotate(stk, print, cpt);
		}
	}
}

void	make_run(t_list **a, t_list **b, int cursor, int print, t_count *cpt)
{
	int pivot;
	int i;
	t_list	*curr;
	int a_value;
	int hilim;
	int lowlim;

	pivot = ft_lstsize(*a) / cursor;	
	i = 0;
	curr = *a;
	while (i <= cursor)
	{
		hilim = (1 + i) * pivot;
		lowlim = i * pivot;
		while (in_range(*a, lowlim, hilim))
		{
			curr = *a;
			a_value = *(int*)curr->content;
			if (a_value >= lowlim && a_value <= hilim)
				place_in_between(b, a, cpt, print);
			else
				bring_index_up(a, in_range(*a, lowlim, hilim) - 1, cpt,  print);
		}
		i++;
	}		
}

void	sort_stack(t_list **a, t_list **b, int print, t_count *cpt)
{
	int size;
	size = ft_lstsize(*a);
	if (size < 0)
		mixed_sort(a, b, print, cpt);
	else
	{
		if (size < 250)
			make_run(a, b, 5, print, cpt);
		else
			make_run(a, b, 13, print, cpt);
		bring_index_up(b, get_index(get_max(*b), *b), cpt, print);
		push_all(a, b, cpt, print);
	}
}
