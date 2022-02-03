/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:52:05 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:52:07 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	print_oper_dop(t_ps *const ps, int i)
{
	if (ps->oper[i] == RA)
		write(1, "ra\n", 3);
	else if (ps->oper[i] == RB)
		write(1, "rb\n", 3);
	else if (ps->oper[i] == RR)
		write(1, "rr\n", 3);
	else if (ps->oper[i] == RRA)
		write(1, "rra\n", 4);
	else if (ps->oper[i] == RRB)
		write(1, "rrb\n", 4);
	else if (ps->oper[i] == RRR)
		write(1, "rrr\n", 4);
}

void	print_oper(t_ps *const ps)
{
	int	i;

	i = 0;
	while (i < ps->call)
	{
		if (ps->oper[i] == SA)
			write(1, "sa\n", 3);
		else if (ps->oper[i] == SB)
			write(1, "sb\n", 3);
		else if (ps->oper[i] == SS)
			write(1, "ss\n", 3);
		else if (ps->oper[i] == PA)
			write(1, "pa\n", 3);
		else if (ps->oper[i] == PB)
			write(1, "pb\n", 3);
		else
			print_oper_dop(ps, i);
		i++;
	}
}
