/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:58:58 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 15:20:15 by  lpires-n        ###   ########.fr       */
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
	int	index;

	index = 1;
	while (argv[index])
	{
		if (ft_strlen(argv[index]) > 11)
			error_exit("Error\n");
		if (ft_strlen(argv[index]) >= 10)
		{
			if (ft_strncmp(argv[index], "2147483647", 10) > 0)
				error_exit("Error\n");
			if (ft_strncmp(argv[index], "-2147483648", 11) > 0)
				error_exit("Error\n");
		}
		index++;
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
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_SUCCESS);
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
