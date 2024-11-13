#include "push_swap.h"

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

void	r_rotate_both(t_list **a, t_list **b)
{
	r_rotate(a, 0);
	r_rotate(b, 0);
	ft_printf("rrr\n");
}

void	push_all(t_list **stk, t_list **obj)
{
	while (ft_lstsize(*obj))
		push(stk, obj);
}

void	push_back(t_list **a, t_list **b)
{
	push(a, b);
	rotate(a, 1);
}


