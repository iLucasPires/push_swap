/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:58:58 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 21:37:07 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_SUCCESS);
}

static void	check_overflow(char **argv)
{
	long long int	keep;
	int				neg;
	int				i;
	int				j;

	i = 0;
	j = 0;
	neg = 0;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) > 11)
			error_exit("Error\n");
		if (ft_strlen(argv[i]) >= 10)
		{
			keep = ft_atolli(argv[i]);
			if (keep > 2147483647 || keep < -2147483648)
				error_exit("Error\n");
		}
	}
}

static void	check_duplicate(char **argv)
{
	int	line;
	int	column;

	line = 1;
	while (argv[line] != NULL)
	{
		column = line + 1;
		while (argv[column] != NULL)
		{
			if (ft_atoi(argv[line]) == ft_atoi(argv[column]))
			{
				error_exit("Error\n");
			}
			column++;
		}
		line++;
	}
}

static void	check_is_sorting(char **argv)
{
	int	index;

	index = 0;
	while (argv[index + 1] != NULL)
	{
		if (ft_isnumber(argv[index]) && ft_isnumber(argv[index + 1]))
		{
			if (ft_atoi(argv[index]) > ft_atoi(argv[index + 1]))
				return ;
		}
		index += 1;
	}
	exit(EXIT_SUCCESS);
}

void	check_arguments(char **argv)
{
	int	index;

	index = 1;
	while (argv[index] != NULL)
	{
		if (!ft_isnumber(argv[index]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_SUCCESS);
		}
		index++;
	}
	check_overflow(argv);
	check_duplicate(argv);
	check_is_sorting(argv);
}
