#include <push_swap.h>

static void	check_overflow(char **argv)
{
	int	index;

	index = 1;
	while (argv[index])
	{
		if (ft_strlen(argv[index]) >= 10)
		{
			if ((ft_strncmp(argv[index], MAX_INT, 10) > 0
				|| ft_strncmp(argv[index], MIN_INT, 10) < 0 ))
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_SUCCESS);
			}
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
	ft_putstr_fd("error\n", 1);
	exit(EXIT_SUCCESS);
}

void	check_arguments(char **argv)
{	
	int index;

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

void	add_argv_to_stack(int argc, char **argv, t_data *data)
{
	int	index;
	int	value_temp;

	index = 1;
	data->array_temp = (int *)malloc(sizeof(int) * (argc - 1));
	while (argv[index] != NULL)
	{
		value_temp = ft_atoi(argv[index]);
		data->array_temp[index - 1] = value_temp;
		insert_at_tail(value_temp, 0, &data->stack_a);
		index++;
	}
}