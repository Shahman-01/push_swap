/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:51:58 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:52:00 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_in_b_mid(t_ps *const ps)
{
	ps->mid = (max_index_a(ps) + min_index_a_was_positive(ps)) / 2;
	while (ps->a[ps->len_a - 1].was == ps->was_min)
	{
		if (ps->a[ps->len_a - 1].index <= ps->mid + 1)
		{
			ps->a[ps->len_a - 1].was++;
			ft_pb(ps);
		}
		else
		{
			ps->a[ps->len_a - 1].was++;
			ft_ra(ps);
		}
	}
	ps->was_min++;
}

void	two_b_wanted(t_ps *const ps)
{
	if (ps->b[ps->len_b - 2].index == ps->want && \
	ps->b[ps->len_b - 1].index == ps->want + 1)
	{
		ps->b[ps->len_b - 1].was = -1;
		ps->want++;
		ft_pa(ps);
		ps->b[ps->len_b - 1].was = -1;
		ps->want++;
		ft_pa(ps);
		ft_ra(ps);
		ft_ra(ps);
	}
}

void	while_b_not_empty_dop(t_ps *const ps, int equal)
{
	ps->mid = ((max_index_b(ps) + ps->want) / 2);
	equal = ps->b[ps->len_b - 1].was;
	while (ps->b[ps->len_b - 1].was == equal)
	{
		if_idex_a_wanted(ps);
		two_b_wanted(ps);
		if (ps->b[ps->len_b - 1].index == ps->want)
			if_want(ps);
		else if (ps->b[ps->len_b - 1].index >= ps->mid + 4)
		{
			ps->b[ps->len_b - 1].was++;
			ft_pa(ps);
		}
		else
		{	
			ps->b[ps->len_b - 1].was++;
			ft_rb(ps);
		}
		if_idex_a_wanted(ps);
		two_b_wanted(ps);
	}
	two_b_wanted(ps);
}

void	while_b_not_empty(t_ps *const ps, int equal)
{
	while (ps->len_b > 0)
	{
		while_b_not_empty_dop(ps, equal);
		if_idex_a_wanted(ps);
	}
}

void	mid_sort(t_ps *const ps)
{
	int	equal;
	int	max_ws;

	equal = 0;
	while (ps_is_sort(ps) == 0)
	{
		ps->mid = max_index_a(ps) / 2 + ps->want;
		push_in_b_mid(ps);
		if (ps->want > 1)
			while (ps->a[0].was != -1)
				ft_rra(ps);
		while_b_not_empty(ps, equal);
		if_idex_a_wanted(ps);
		while (similar_was(ps) == 0 && ps->len_b == 0)
		{
			max_ws = max_was(ps);
			while (ps->a[ps->len_a - 1].was == max_ws)
				ft_pb(ps);
			while_b_not_empty(ps, equal);
		}
	}
}
