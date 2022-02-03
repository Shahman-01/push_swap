/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_funk_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:51:40 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:51:42 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_duplicate(t_ps *const ps, int num)
{
	int	i;

	i = ps->len_a;
	while (--i >= 0)
		if (num == ps->a[i].value)
			return (1);
	return (0);
}

int	ps_is_sort(t_ps *const ps)
{
	int		i;

	if (ps->len_b != 0)
		return (0);
	i = ps->len_a;
	while (--i > 0)
		if (ps->a[i].value >= ps->a[i - 1].value)
			return (0);
	return (1);
}

void	if_want(t_ps *const ps)
{
	ps->b[ps->len_b - 1].was = -1;
	ps->want++;
	ft_pa(ps);
	ft_ra(ps);
}

void	push_in_down_a(t_ps *const ps)
{
	ps->a[ps->len_a - 1].was = -1;
	ps->want++;
	ft_ra(ps);
}

void	if_idex_a_wanted(t_ps *const ps)
{
	if (ps->a[ps->len_a - 2].index == ps->want)
		ft_sa(ps);
	while (ps->a[ps->len_a - 1].index == ps->want)
	{
		ps->a[ps->len_a - 1].was = -1;
		ps->want++;
		ft_ra(ps);
	}
}
