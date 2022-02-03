/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:52:58 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:53:00 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_ps *const ps)
{
	t_int	buf;

	ps->count++;
	if (ps->len_a > 1)
	{
		buf = ps->a[ps->len_a - 1];
		ps->a[ps->len_a - 1] = ps->a[ps->len_a - 2];
		ps->a[ps->len_a - 2] = buf;
	}
	ps->oper[ps->call] = SA;
	ps->call++;
}

void	ft_sb(t_ps *const ps)
{
	t_int	buf;

	ps->count++;
	if (ps->len_b > 1)
	{
		buf = ps->b[ps->len_b - 1];
		ps->b[ps->len_b - 1] = ps->b[ps->len_b - 2];
		ps->b[ps->len_b - 2] = buf;
	}
	ps->oper[ps->call] = SB;
	ps->call++;
}

void	ft_ss(t_ps *const ps)
{
	ps->count++;
	ft_sa(ps);
	ft_sb(ps);
	ps->oper[ps->call] = SS;
	ps->call++;
}

void	ft_pa(t_ps *const ps)
{
	ps->count++;
	if (ps->len_b > 0)
		ps->a[ps->len_a++] = ps->b[--ps->len_b];
	ps->oper[ps->call] = PA;
	ps->call++;
}

void	ft_pb(t_ps *const ps)
{
	ps->count++;
	if (ps->len_a > 0)
		ps->b[ps->len_b++] = ps->a[--ps->len_a];
	ps->oper[ps->call] = PB;
	ps->call++;
}
