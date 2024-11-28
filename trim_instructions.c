/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:50:47 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 16:43:24 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_instr(t_count *cpt, int to_delete, int i, char *new_instr)
{
	free(cpt->instr[to_delete]);
	free(cpt->instr[i]);
	cpt->instr[to_delete] = ft_strdup(new_instr);
	cpt->instr[i] = ft_strdup("");
}

int	is_target(char *target_a, char *target_b, char *current, char *todel)
{
	if (!ft_strcmp(target_a, current) && !ft_strcmp(target_b, todel))
		return (1);
	if (!ft_strcmp(target_b, current) && !ft_strcmp(target_a, todel))
		return (1);
	return (0);
}

void	check_n_replace_rr(t_count *cpt, int *i, int *to_delete, int *count)
{
	char	*instr;

	instr = cpt->instr[*i];
	if (!ft_strcmp("rra\n", instr) || !ft_strcmp("rrb\n", instr))
	{
		if (*to_delete == -1)
			*to_delete = *i;
		else if (is_target("rra\n", "rrb\n", instr, cpt->instr[*to_delete]))
		{
			replace_instr(cpt, *to_delete, *i, "rrr\n");
			*count += 1;
			*i = *to_delete;
			*to_delete = -1;
		}
	}
	else if (ft_strcmp(instr, "rra\n") && ft_strcmp(instr, "rrb\n")
		&& ft_strcmp(instr, "") && ft_strcmp(instr, "rrr\n"))
		*to_delete = -1;
}

void	check_n_replace_r(t_count *cpt, int	*i, int *to_delete, int *count)
{
	char	*instr;

	instr = cpt->instr[*i];
	if (!ft_strcmp("ra\n", instr) || !ft_strcmp("rb\n", instr))
	{
		if (*to_delete == -1)
			*to_delete = *i;
		else if (is_target("ra\n", "rb\n", instr, cpt->instr[*to_delete]))
		{
			replace_instr(cpt, *to_delete, *i, "rr\n");
			*count += 1;
			*i = *to_delete;
			*to_delete = -1;
		}
	}
	else if (ft_strcmp(instr, "ra\n") && ft_strcmp(instr, "rb\n")
		&& ft_strcmp(instr, "") && ft_strcmp(instr, "rr\n"))
		*to_delete = -1;
}

int	replace_r_rotate(t_count *cpt)
{
	int		count;
	int		i;
	int		to_delete;

	i = -1;
	count = 0;
	to_delete = -1;
	while (++i < cpt->counter)
		check_n_replace_rr(cpt, &i, &to_delete, &count);
	return (count);
}
