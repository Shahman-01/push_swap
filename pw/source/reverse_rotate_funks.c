/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_funks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:52:34 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:52:36 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rra(t_ps *const ps)
{
	t_int	buf;
	int		i;

	ps->count++;
	i = 0;
	buf = ps->a[0];
	if (ps->len_a > 1)
	{
		while (i < ps->len_a)
		{
			ps->a[i] = ps->a[i + 1];
			i++;
		}
		ps->a[ps->len_a - 1] = buf;
	}
	ps->oper[ps->call] = RRA;
	ps->call++;
}

void	ft_rrb(t_ps *const ps)
{
	t_int	buf;
	int		i;

	ps->count++;
	i = 0;
	buf = ps->b[0];
	if (ps->len_b > 1)
	{
		while (i < ps->len_b)
		{
			ps->b[i] = ps->b[i + 1];
			i++;
		}
	}
	ps->b[ps->len_b - 1] = buf;
	ps->oper[ps->call] = RRB;
	ps->call++;
}

void	ft_rrr(t_ps *const ps)
{
	ps->count++;
	ft_rra(ps);
	ft_rrb(ps);
	ps->oper[ps->call] = RRR;
	ps->call++;
}
