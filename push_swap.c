/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:24:50 by npolack           #+#    #+#             */
/*   Updated: 2024/10/31 19:13:58 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_flags(int ac, char **av)
{
	(void)ac;
	if (!ft_strncmp(av[1], "-d", 3))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;
	int		debug_flag;

	if (ac <= 1)
		return (0);
	// To implement...
	debug_flag = check_for_flags(ac, av);
	if (debug_flag)
	{
		ac -= 1;
	}
	a = 0;
	b = 0;
	size = get_input(&a, ac, av);
	if (!size)
		ft_printf("Error\n");
	else if (size < 50)
			mixed_sort(&a, &b, debug_flag);
	else if (size >= 50)
		radix_sort(&a, &b);
	ft_lstclear(&a, free);
//	if (is_sorted(a, size))
//		ft_printf("-----SORTED-----\n");
//	ft_printf("STACK A : ");
//	ft_lstprint(a);
//	ft_printf("\nSTACK B : ");
//	ft_lstprint(b);
}

