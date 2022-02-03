/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:52:48 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:52:49 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_ps *const ps)
{
	t_int	buf;
	int		i;

	ps->count++;
	i = 1;
	buf = ps->a[ps->len_a - 1];
	if (ps->len_a > 1)
	{
		while (i < ps->len_a)
		{
			ps->a[ps->len_a - i] = ps->a[ps->len_a - (i + 1)];
			i++;
		}
		ps->a[0] = buf;
	}
	ps->oper[ps->call] = RA;
	ps->call++;
}

void	ft_rb(t_ps *const ps)
{
	t_int	buf;
	int		i;

	ps->count++;
	i = 1;
	buf = ps->b[ps->len_b - 1];
	if (ps->len_b > 1)
	{
		while (i < ps->len_b)
		{
			ps->b[ps->len_b - i] = ps->b[ps->len_b - (i + 1)];
			i++;
		}
		ps->b[0] = buf;
	}
	ps->oper[ps->call] = RB;
	ps->call++;
}

void	ft_rr(t_ps *const ps)
{
	ps->count++;
	ft_ra(ps);
	ft_rb(ps);
	ps->oper[ps->call] = RR;
	ps->call++;
}
