/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:50:36 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:50:38 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define SIZE 1024
# define OPER 15000
# define BUFF 1024
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define LEN_INT 11
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_int
{
	int	value;
	int	index;
	int	flag;
	int	was;
}		t_int;

typedef struct s_ps
{
	t_int	a[SIZE];
	t_int	b[SIZE];
	int		oper[OPER];
	int		was_min;
	int		want;
	int		call;
	int		count;
	int		mid;
	int		max;
	int		len_a;
	int		len_b;
}		t_ps;

typedef struct s_rot
{
	int	start_b;
	int	finish_b;
	int	start_a;
	int	finish_a;
}		t_rot;

typedef struct s_nums
{
	int	i;
	int	j;
	int	st;
	int	fn;
	int	dup;
}		t_nums;

void	ft_sa(t_ps *const ps);
void	ft_sb(t_ps *const ps);
void	ft_ss(t_ps *const ps);
void	ft_pa(t_ps *const ps);
void	ft_pb(t_ps *const ps);
void	ft_ra(t_ps *const ps);
void	ft_rb(t_ps *const ps);
void	ft_rr(t_ps *const ps);
void	ft_rra(t_ps *const ps);
void	ft_rrb(t_ps *const ps);
void	ft_rrr(t_ps *const ps);
int		ft_atoi(const char *str);
void	init_index(t_ps *const ps);
void	del_diff(t_ps *const ps, t_nums *const nums);
void	under_five(t_ps *const ps, int len);
void	print_oper(t_ps *const ps);
int		ps_is_sort(t_ps *const ps);
int		similar_was(t_ps *const ps);
int		max_was(t_ps *const ps);
int		max_index_b(t_ps *const ps);
int		max_index_a(t_ps *const ps);
int		min_index_a(t_ps *const ps);
void	init(t_ps *const ps);
void	pa_ra_funk(t_ps *const ps);
void	mid_sort(t_ps *const ps);
void	if_want(t_ps *const ps);
int		is_duplicate(t_ps *const ps, int num);
void	push_in_down_a(t_ps *const ps);
void	ft_exit_fail(char *const message);
void	if_idex_a_wanted(t_ps *const ps);
int		min_index_a_was_positive(t_ps *const ps);
void	ps_read_a(t_ps *const ps, const int ac, char *const *const av);

#endif
