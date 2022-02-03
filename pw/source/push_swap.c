/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:52:14 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:52:16 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init(t_ps *const ps)
{
	ps->len_a = 0;
	ps->len_b = 0;
	ps->call = 0;
	ps->count = 0;
	ps->want = 1;
	ps->was_min = 0;
}

void	pa_ra_funk(t_ps *const ps)
{
	ps->b[ps->len_b - 1].was = -1;
	ps->want++;
	ft_pa(ps);
	ft_ra(ps);
}

void	call_funk(t_ps *const ps)
{
	t_nums	nums;

	init_index(ps);
	if (ps->len_a < 6)
		under_five(ps, ps->len_a);
	else
		mid_sort(ps);
	del_diff(ps, &nums);
	print_oper(ps);
}

void	call_atoi(t_ps *const ps, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (argc - 1 > ps->len_a)
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			ft_exit_fail("error\n");
		else if (is_duplicate(ps, ft_atoi(argv[i])) == 0)
			ps->a[ps->len_a].value = ft_atoi(argv[i--]);
		else
		{
			ft_exit_fail("error, duplicate number \n");
			return ;
		}
		ps->len_a++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_ps	ps;

	i = 0;
	init(&ps);
	if (argc > 1)
	{
		call_atoi(&ps, argc, argv);
		if (ps_is_sort(&ps) == 0)
		{
			call_funk(&ps);
		}
	}
}
