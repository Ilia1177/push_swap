#include "push_swap.h"

void	replace_instr(t_count *cpt, int to_delete, int i, char *new_instr)
{
	free(cpt->instr[to_delete]);
	free(cpt->instr[i]);
	cpt->instr[to_delete] = ft_strdup(new_instr);
	cpt->instr[i] = ft_strdup("");
}

int		replace_r_rotate(t_count *cpt)
{
	char	*instr;
	int		count;
	int		i;
	int		to_delete;

	i 			= 0;
	count 		= 0;
	to_delete	= -1;
	while (i < cpt->counter)
	{
		instr = cpt->instr[i];
		if (!ft_strcmp("rra\n", instr) || !ft_strcmp("rrb\n", instr))
		{ 
			if (to_delete == -1)
				to_delete = i;
			else if ((!ft_strcmp("rra\n", instr) && !ft_strcmp("rrb\n", cpt->instr[to_delete]))
					|| (!ft_strcmp("rrb\n", instr) && !ft_strcmp("rra\n", cpt->instr[to_delete])))
			{
				replace_instr(cpt, to_delete, i, "rrr\n");
				count++;
				i = to_delete;
				to_delete = -1;
			}
		}
		else if (ft_strcmp(instr, "rra\n") && ft_strcmp(instr, "rrb\n") 
				&& ft_strcmp(instr, "") && ft_strcmp(instr, "rrr\n"))
			to_delete = -1;
		i++;
	}
	return (count);
}

int	replace_rotate(t_count *cpt)
{
	char *instr;
	int	count;
	int i;
	int to_delete;

	i = 0;
	count = 0;
	to_delete = -1;
	while (i < cpt->counter)
	{
		instr = cpt->instr[i];
		if (ft_strcmp("ra\n", instr) == 0 || ft_strcmp("rb\n", instr) == 0)
		{ 
			if (to_delete == -1)
				to_delete = i;
			else if ((!ft_strcmp("ra\n", instr) && !ft_strcmp("rb\n", cpt->instr[to_delete]))
					|| (!ft_strcmp("rb\n", instr) && !ft_strcmp("ra\n", cpt->instr[to_delete])))
			{
				replace_instr(cpt, to_delete, i, "rr\n");
				count++;
				i = to_delete;
				to_delete = -1;
			}
		}
		else if (ft_strcmp(instr, "ra\n") && ft_strcmp(instr, "rb\n") 
				&& ft_strcmp(instr, "") && ft_strcmp(instr, "rr\n"))
			to_delete = -1;
		i++;
	}
	return (count);
}

int trim_instr(t_count *cpt)
{
	int	count;

	count = replace_r_rotate(cpt);
	count += replace_rotate(cpt);
	return (count);
}
