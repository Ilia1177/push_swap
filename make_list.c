/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:30:01 by npolack           #+#    #+#             */
/*   Updated: 2024/12/03 17:35:34 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_check(char *nptr)
{
	long int	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr) - '0';
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (0);
		nptr++;
	}
	return (1);
}

int	make_list(t_list **stack, int size, char **av, int flag)
{
	int	*tab;
	int	i;
	int	j;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	i = 1;
	j = 0;
	while (i <= size)
	{
		if (flag == i)
			j++;
		if (!int_check(av[i + j]))
			return (free_all(tab, NULL, 0));
		tab[i - 1] = ft_atoi(av[i + j]);
		i++;
	}
	if (!sort_tab(tab, size))
		return (free_all(tab, NULL, size));
	ft_lstinit(stack, av, size, flag);
	put_position(*stack, tab, size);
	free_all(tab, NULL, size);
	return (size);
}

int	init_strings(char **strings, int *tab, int size)
{
	int	i;

	i = -1;
	strings[0] = ft_strdup("");
	while (++i < size)
	{
		strings[i + 1] = ft_itoa(tab[i]);
		if (!strings[i + 1] || !int_check(strings[i + 1]))
			return (free_all(tab, strings, i + 1));
	}
	return (1);
}

int	make_list_from_str(t_list **stack, int size, char *str)
{
	int		*tab;
	char	**strings;

	tab = (int *)malloc(size * sizeof (int));
	tab = str_to_tab(tab, str);
	if (!tab)
		return (free_all(tab, NULL, 0));
	strings = (char **)malloc(sizeof (char *) * (size + 1));
	if (!strings)
		return (free_all(tab, strings, size));
	if (!init_strings(strings, tab, size))
		return (free_all(tab, strings, size));
	if (!sort_tab(tab, size))
		return (free_all(tab, strings, size));
	ft_lstinit(stack, strings, size, 0);
	put_position(*stack, tab, size);
	free_all(tab, strings, size);
	return (size);
}
