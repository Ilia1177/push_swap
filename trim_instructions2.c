/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_instructions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:53:45 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 16:56:22 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	replace_rotate(t_count *cpt)
{
	int		count;
	int		i;
	int		to_delete;

	i = -1;
	count = 0;
	to_delete = -1;
	while (++i < cpt->counter)
		check_n_replace_r(cpt, &i, &to_delete, &count);
	return (count);
}

int	trim_instr(t_count *cpt)
{
	int	count;

	count = replace_r_rotate(cpt);
	count += replace_rotate(cpt);
	return (count);
}
