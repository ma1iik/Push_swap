/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:23:18 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/23 12:19:24 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	total_arg(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	sort(t_struct *struc, int i)
{
	if (ft_strncmp(struc->instruction[i], "pa\n", 3) == 0)
		func_pa1(struc);
	else if (ft_strncmp(struc->instruction[i], "pb\n", 3) == 0)
		func_pb1(struc);
	else if (ft_strncmp(struc->instruction[i], "sa\n", 3) == 0)
		func_sa1(struc);
	else if (ft_strncmp(struc->instruction[i], "sb\n", 3) == 0)
		func_sb1(struc);
	else if (ft_strncmp(struc->instruction[i], "ss\n", 3) == 0)
		func_ss1(struc);
	else if (ft_strncmp(struc->instruction[i], "ra\n", 3) == 0)
		func_ra1(struc);
	else if (ft_strncmp(struc->instruction[i], "rb\n", 3) == 0)
		func_rb1(struc);
	else if (ft_strncmp(struc->instruction[i], "rrr\n", 4) == 0)
		func_rrr1(struc);
	else if (ft_strncmp(struc->instruction[i], "rra\n", 4) == 0)
		func_rra1(struc);
	else if (ft_strncmp(struc->instruction[i], "rrb\n", 4) == 0)
		func_rrb1(struc);
	else if (ft_strncmp(struc->instruction[i], "rr\n", 3) == 0)
		func_rr1(struc);
	else
		return (0);
	return (1);
}

void	checker(t_struct *struc)
{
	int	i;

	i = 0;
	while (1)
	{
		struc->instruction[i] = get_next_line(0);
		if (struc->instruction[i] == NULL)
			break ;
		if (!sort(struc, i))
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		if (stack_sorted(struc) && struc->sb_nbr == 0)
			break ;
		i++;
	}
	if (stack_sorted(struc) && struc->sb_nbr == 0)
		printf("OK\n");
	else
		printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_struct	*struc;

	struc = malloc(sizeof(t_struct));
	struc->instruction = malloc(sizeof(char *) * 6666);
	check_arg(argc, argv, struc);
	dec_st(struc);
	checker(struc);
	free(struc->a);
	free(struc->b);
	free (struc);
}
