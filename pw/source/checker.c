/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:51:13 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:51:15 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_check(t_ps *const ps, char *const *const oper)
{
	if (0 == ft_strcmp(*oper, "sa"))
		ft_sa(ps);
	else if (0 == ft_strcmp(*oper, "sb"))
		ft_sb(ps);
	else if (0 == ft_strcmp(*oper, "ss"))
		ft_ss(ps);
	else if (0 == ft_strcmp(*oper, "pa"))
		ft_pa(ps);
	else if (0 == ft_strcmp(*oper, "pb"))
		ft_pb(ps);
	else if (0 == ft_strcmp(*oper, "ra"))
		ft_ra(ps);
	else if (0 == ft_strcmp(*oper, "rb"))
		ft_rb(ps);
	else if (0 == ft_strcmp(*oper, "rr"))
		ft_rr(ps);
	else if (0 == ft_strcmp(*oper, "rra"))
		ft_rra(ps);
	else if (0 == ft_strcmp(*oper, "rrb"))
		ft_rrb(ps);
	else if (0 == ft_strcmp(*oper, "rrr"))
		ft_rrr(ps);
	else
		write(1, "Error\n", 6);
}

int	main(int ac, char **av)
{
	static t_ps		ps;
	char			*oper;

	ft_bzero(&ps, sizeof(t_ps));
	if (ac > 1)
	{
		ps_read_a(&ps, ac, av);
		while (get_next_line(0, &oper) > 0)
		{
			ps_check(&ps, &oper);
			free(oper);
		}
		if (1 == ps_is_sort(&ps))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
}
