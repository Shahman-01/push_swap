/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_diff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:51:21 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:51:23 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	diff_dop_2(t_ps *const ps, int num1, int num2, \
	t_nums *const nums)
{
	while (ps->oper[nums->j] == num1)
	{
		nums->st++;
		nums->j++;
		if (ps->oper[nums->j] == num2)
		{
			while (ps->oper[nums->j] == num2)
			{
				nums->fn++;
				nums->j++;
			}
		}
	}
}

static	void	del_diff_dop(t_ps *const ps, int num1, int num2, \
	t_nums *const nums)
{
	int	numr;

	if (num1 == RA || num1 == RB)
		numr = RR;
	else if (num1 == RRA || num1 == RRB)
		numr = RRR;
	nums->st = 0;
	nums->fn = 0;
	if (ps->oper[nums->i] == num1)
	{
		nums->j = nums->i;
		diff_dop_2(ps, num1, num2, nums);
		if (nums->st < nums->fn)
		{
			nums->dup = nums->st;
			while (nums->st-- > 0)
				ps->oper[nums->i++] = numr;
			while (nums->dup-- > 0)
				ps->oper[nums->i++] = 0;
		}
	}
}

void	del_diff(t_ps *const ps, t_nums *const nums)
{
	nums->i = 0;
	while (nums->i < ps->call)
	{
		nums->j = nums->i;
		if (ps->oper[nums->j] == RA)
			del_diff_dop(ps, RA, RB, nums);
		else if (ps->oper[nums->j] == RB)
			del_diff_dop(ps, RB, RA, nums);
		else if (ps->oper[nums->j] == RRA)
			del_diff_dop(ps, RRA, RRB, nums);
		else if (ps->oper[nums->j] == RRB)
			del_diff_dop(ps, RRB, RRA, nums);
		nums->i++;
	}
}
