/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:57:13 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/23 15:48:12 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j]) == 1)
				return (1);
			if (((argv[i][j]) == '-' && (argv[i][j +1]) == '\0')
				|| ((argv[i][j]) == '+' && (argv[i][j +1]) == '\0'))
				return (1);
			j++;
		}
		i++;
	}
	if (i == 1)
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	check_int_size(char **argv)
{
	long long int	i;
	int				j;

	j = 0;
	while (argv[j])
	{
		if (ft_strlen(argv[j]) > 11)
			return (1);
		i = ft_atoi(argv[j]);
		if (i > 2147483647 || i < -2147483648)
			return (1);
		j++;
	}
	return (0);
}

int	check_dup(char **argv)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (argv[len])
		len++;
	while (argv[i])
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**split_argv(t_struct *struc, int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
		struc->argvs = ft_split(argv[1], ' ');
	else
	{
		while (argv[i])
		{
			if (ft_strlen(argv[i]) == 0)
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			i++;
		}
	struc->argvs = &argv[1];
	}
	return (struc->argvs);
}

void	check_arg(int argc, char **argv, t_struct *struc)
{
	struc->argvs = split_argv(struc, argc, argv);
	if (check_if_digit(struc->argvs) > 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (check_int_size(struc->argvs) > 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if ((check_dup(struc->argvs)) > 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	struc->ac = total_arg(struc->argvs);
}
