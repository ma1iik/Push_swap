/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 02:30:46 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 15:56:56 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_struct
{
	char			**argvs;
	int				ac;
	int				*a;
	int				*b;
	int				sa_nbr;
	int				sb_nbr;

	char			**instruction;
	int				*checker_a;
	int				*checker_b;
	int				checker_sa_nbr;
	int				checker_sb_nbr;
}	t_struct;

int		check_if_digit(char **argv);
int		check_int_size(char **argv);
void	check_arg(int argc, char **argv, t_struct *struc);
int		check_dup(char **argv);
char	**split_argv(t_struct *struc, int argc, char **argv);
int		total_arg(char **argv);
void	ft_errors(int x);
int		func_pa(t_struct *struc);
int		func_pa1(t_struct *struc);
int		func_pb(t_struct *struc);
int		func_pb1(t_struct *struc);
void	func_rra(t_struct *struc);
void	func_rra1(t_struct *struc);
void	func_rrb(t_struct *struc);
void	func_rrb1(t_struct *struc);
void	func_rrr(t_struct *struc);
void	func_rrr1(t_struct *struc);
void	func_ra(t_struct *struc);
void	func_ra1(t_struct *struc);
void	func_rb(t_struct *struc);
void	func_rb1(t_struct *struc);
void	func_rr(t_struct *struc);
void	func_rr1(t_struct *struc);
int		func_sa(t_struct *struc);
int		func_sa1(t_struct *struc);
int		func_sb(t_struct *struc);
int		func_sb1(t_struct *struc);
void	func_ss(t_struct *struc);
void	func_ss1(t_struct *struc);
int		find_max(int *list, int max_nbr);
int		find_min(int *list, int max_nbr);
void	dec_st(t_struct *struc);
int		stack_sorted(t_struct *struc);
void	minrange_alg2(t_struct *struc, int min, int max);
void	minrange_alg(t_struct *struc);
int		closest_supr(t_struct *struc, int num);
int		get_moves_nbr(int index, int stack_nbr);
int		shortest_option(t_struct *struc, int i);
int		get_index(int *stack, int len, int value);
void	bring_num_up2(t_struct *struc, int b_index, int b_n);
void	bring_num_up(t_struct *struc);

#endif