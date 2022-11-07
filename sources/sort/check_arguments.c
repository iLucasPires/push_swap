#include <push_swap.h>

void	check_overflow(char **argv)
{
	int	index;

	index = 1;
	while (argv[index])
	{
		if (ft_strlen(argv[index]) >= 10)
		{
			if (ft_strncmp(argv[index], MAX_INT, 10) > 0
				|| ft_strncmp(argv[index], MIN_INT, 10) < 0)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_SUCCESS);
			}
		}
		index += 1;
	}
}

void	check_duplicate(char **argv)
{
	int	index[2];

	index[0] = 1;
	while (argv[index[0]] != NULL)
	{
		index[1] = index[0] + 1;
		while (argv[index[1]] != NULL)
		{
			if (ft_atoi(argv[index[0]]) == ft_atoi(argv[index[1]]))
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_SUCCESS);
			}
			index[1] += 1;
		}
		index[0] += 1;
	}
}

void	check_is_sorting(char **argv)
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
	ft_putstr_fd("error\n", 1);
	exit(EXIT_SUCCESS);
}

void	add_argv_to_stack(char **argv, t_stack *stack, int *array_temp)
{
	int index;
	int temp;

	index = 1;
	while (argv[index])
	{
		if (ft_isnumber(argv[index]))
		{
			temp = ft_atoi(argv[index]);
			insert_at_tail(temp, stack);
			array_temp[index - 1] = temp;
			stack->size += 1;
		}
		index += 1;
	}
}