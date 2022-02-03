/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:53:10 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:53:13 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	ra_or_rra(t_ps *const ps)
{
	int	start;
	int	finish;
	int	i;

	i = ps->len_a - 1;
	start = 0;
	finish = 1;
	while (ps->a[i--].index != min_index_a(ps))
		start++;
	i = 0;
	while (ps->a[i++].index != min_index_a(ps))
		finish++;
	if (start <= finish)
		return (1);
	return (0);
}

static	void	three_sort(t_ps *const ps)
{
	if (ps->a[2].value > ps->a[0].value && ps->a[0].value > ps->a[1].value)
		ft_ra(ps);
	else if (ps->a[2].value > ps->a[1].value && ps->a[1].value > ps->a[0].value)
	{
		ft_sa(ps);
		ft_rra(ps);
	}
	else if (ps->a[0].value > ps->a[2].value && ps->a[2].value > ps->a[1].value)
		ft_sa(ps);
	else if (ps->a[1].value > ps->a[2].value && ps->a[2].value > ps->a[0].value)
		ft_rra(ps);
	else if (ps->a[1].value > ps->a[0].value && ps->a[0].value > ps->a[2].value)
	{
		ft_sa(ps);
		ft_ra(ps);
	}
}

static	void	four_sort(t_ps *const ps)
{
	if (ra_or_rra(ps) == 1)
	{
		while (ps->a[ps->len_a - 1].index != min_index_a(ps))
			ft_ra(ps);
	}
	else
	{
		while (ps->a[ps->len_a - 1].index != min_index_a(ps))
			ft_rra(ps);
	}
	ft_pb(ps);
	three_sort(ps);
	ft_pa(ps);
}

static	void	five_sort(t_ps *const ps)
{
	if (ra_or_rra(ps) == 1)
	{
		while (ps->a[ps->len_a - 1].index != min_index_a(ps))
			ft_ra(ps);
	}
	else
	{
		while (ps->a[ps->len_a - 1].index != min_index_a(ps))
			ft_rra(ps);
	}
	ft_pb(ps);
	four_sort(ps);
	ft_pa(ps);
}

void	under_five(t_ps *const ps, int len)
{
	if (len == 3)
		three_sort(ps);
	else if (len == 4)
		four_sort(ps);
	else if (len == 5)
		five_sort(ps);
}
