/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 02:58:51 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 18:06:10 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_arg(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	rotate_till(t_struct *struc)
{
	int		max;
	int		i;
	int		max_index;

	i = 0;
	max = find_max(struc->a, struc->sa_nbr);
	max_index = get_index(struc->a, struc->sa_nbr, max);
	if ((struc->sa_nbr / 2) > max_index)
	{
		while (struc->a[struc->sa_nbr - 1] != max)
			func_ra(struc);
	}
	else
	{
		while (struc->a[struc->sa_nbr - 1] != max)
			func_rra(struc);
	}
}

void	print_stacks(t_struct *struc)
{
	int		i;

	i = 0;
	while (i < struc->sa_nbr)
	{
		printf("[%d]", struc->a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < struc->sb_nbr)
	{
		printf("[%d]", struc->b[i]);
		i++;
	}
	printf("\n");
}

void	big_alg(t_struct *struc)
{
	int			max;

	while (!stack_sorted(struc))
	{
		if (struc->sa_nbr == 3)
			minrange_alg(struc);
		else if (struc->sa_nbr == 2)
			func_sa(struc);
		else
		{
			max = find_max(struc->a, struc->sa_nbr);
			while (struc->sa_nbr > 2)
			{
				if (struc->a[0] == max)
					func_ra(struc);
				func_pb(struc);
			}
			while (struc->sb_nbr > 0)
			{
				bring_num_up(struc);
				func_pa(struc);
			}
			rotate_till(struc);
		}
	}
}

int	main(int argc, char **argv)
{
	t_struct	*struc;

	struc = malloc(sizeof(t_struct));
	check_arg(argc, argv, struc);
	dec_st(struc);
	big_alg(struc);
	free(struc->a);
	free(struc->b);
	free (struc);
}
