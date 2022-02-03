/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_funk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:51:33 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:51:35 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	max_index_a(t_ps *const ps)
{
	int	i;
	int	val;

	i = 0;
	val = 0;
	while (i < ps->len_a)
	{
		if (val < ps->a[i].index)
			val = ps->a[i].index;
		i++;
	}
	return (val);
}

int	max_index_b(t_ps *const ps)
{
	int	i;
	int	val;

	i = 0;
	val = 0;
	while (i < ps->len_b)
	{
		if (val < ps->b[i].index)
			val = ps->b[i].index;
		i++;
	}
	return (val);
}

int	min_index_a(t_ps *const ps)
{
	int	i;
	int	val;

	i = 0;
	val = ps->a[0].index;
	while (i < ps->len_a)
	{
		if (val > ps->a[i].index)
			val = ps->a[i].index;
		i++;
	}
	return (val);
}

int	max_was(t_ps *const ps)
{
	int	i;
	int	was;

	i = ps->len_a - 1;
	was = 0;
	while (i >= 0)
	{
		if (was < ps->a[i].was)
			was = ps->a[i].was;
		i--;
	}
	return (was);
}

int	similar_was(t_ps *const ps)
{
	int	i;
	int	sim;

	sim = ps->a[ps->len_a - 1].was;
	i = ps->len_a - 1;
	while (i >= 0)
	{
		if (ps->a[i].was != ps->was_min && ps->a[i].was != -1)
			return (0);
		i--;
	}
	return (1);
}
