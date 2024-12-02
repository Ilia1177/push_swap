/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:20:52 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 17:42:32 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (0);
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

// IMPLEMENT OVERFLOW PROTECT !!
int	*str_to_tab(int	*tab, char *str)
{
	int	len;
	int	num;
	int	j;
	int	i;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
		{
			if (!int_check(str + i))
				return (NULL);
			num = ft_atoi(str + i); //here
			if (str[i] == '+')
				i++;
			i += get_intlen(num, 10);
			tab[j] = num;
			j++;
		}
		while (ft_isspace(str[i]))
			i++;
	}
	return (tab);
}

void	put_position(t_list *current, int *tab, int size)
{
	int	i;

	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)current->content == tab[i])
			{
				*(int *)current->content = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

//IMPLEMENT OVERFLOW PROTECT
int	get_input(t_list **stack, int ac, char **av, int flag)
{
	int		size;

	*stack = 0;
	size = ac - 1;
	if (flag)
		size--;
	if (size > 1)
	{
		size = check_input(ac, av, flag);
		if (size)
			size = make_list(stack, size, av, flag); //here
		return (size);
	}
	else if (size == 1)
	{
		size = check_input(ac, av, flag);
		if (size && (flag == 2 || !flag))
			size = make_list_from_str(stack, size, av[1]); //here
		if (size && flag == 1)
			size = make_list_from_str(stack, size, av[2]); //here
		return (size);
	}
	return (0);
}
