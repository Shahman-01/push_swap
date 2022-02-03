/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:51:49 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:51:52 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_index_a_was_positive(t_ps *const ps)
{
	int	i;
	int	val;

	i = 0;
	val = max_index_a(ps);
	while (i < ps->len_a)
	{
		if (val > ps->a[i].index && ps->a[i].was != -1)
			val = ps->a[i].index;
		i++;
	}
	return (val);
}

static	void	sort_dop(t_ps *const ps, int i, int j, t_int a_dup[SIZE])
{
	int	tmp;

	while (i < ps->len_a - 1)
	{
		j = 0;
		while (j < ps->len_a - i - 1)
		{
			if (a_dup[j].value > a_dup[j + 1].value)
			{
				tmp = a_dup[j].value;
				a_dup[j].value = a_dup[j + 1].value;
				a_dup[j + 1].value = tmp;
			}
			j++;
		}
		i++;
	}
}

static	void	sort_init(t_ps *const ps, int i, int j, t_int a_dup[SIZE])
{
	while (i < ps->len_a)
	{
		j = 0;
		while (j < ps->len_a)
		{
			if (ps->a[i].value == a_dup[j].value)
				ps->a[i].index = a_dup[j].index;
			j++;
		}
		i++;
	}
}

void	init_index(t_ps *const ps)
{
	int		i;
	int		j;
	t_int	a_dup[SIZE];

	i = 0;
	j = 0;
	while (i < ps->len_a)
	{
		ps->a[i].was = 0;
		a_dup[i].value = ps->a[i].value;
		ps->a[i].flag = 0;
		i++;
	}
	i = 0;
	sort_dop(ps, i, j, a_dup);
	i = -1;
	while (++i < ps->len_a)
		a_dup[i].index = i + 1;
	i = 0;
	sort_init(ps, i, j, a_dup);
}
