/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:52:23 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:52:26 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_exit_fail(char *const message)
{
	write(2, message, ft_strlen(message));
	exit(1);
}

static int	length_digit(const char *const str)
{
	int		i;
	int		j;

	j = 0;
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t' || \
		str[j] == '\f' || str[j] == '\r' || str[j] == '\v')
		++j;
	if (str[j] == '-' || str[j] == '+')
		j += 1;
	else
		j += 0;
	i = 0;
	while (ft_isdigit(str[j + i]))
		++i;
	return (i);
}

static void	add_elem(t_ps *const ps, const char *const str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(ft_isdigit(str[i]) || '-' == str[i] || '+' == str[i] || \
			ft_is_space(str[i])))
			ft_exit_fail("Error\n");
	if (!is_duplicate(ps, ft_atol(str)) && \
			ps->len_a < SIZE && \
			length_digit(str) <= LEN_INT && \
			!((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1))) && \
			(ft_atol(str) >= MIN_INT && ft_atol(str) <= MAX_INT))
	{
		ps->a[ps->len_a++].value = ft_atol(str);
		ft_ra(ps);
	}
	else
		ft_exit_fail("Error\n");
}

void	ps_read_a(t_ps *const ps, const int ac, char *const *const av)
{
	int		i;

	if (ac > 2)
	{
		i = 0;
		while (ac > ++i)
			add_elem(ps, av[i]);
	}
	else
	{
		i = 0;
		while (av[1][i])
		{
			while (ft_is_space(av[1][i]))
				++i;
			if (av[1][i])
				add_elem(ps, av[1] + i);
			while (ft_isdigit(av[1][i]) || '-' == av[1][i] || '+' == av[1][i])
				++i;
		}
	}
}
