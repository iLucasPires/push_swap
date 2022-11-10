/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:59:39 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 15:58:00 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	handle_stack(t_stack *stack_a, t_stack *stack_b, int *array_temp)
{
	if (stack_a->size == 0 || stack_b->size == 1)
		return ;
	if (stack_a->size == 2)
		two_elements(stack_a);
	else if (stack_a->size == 3)
		three_elements(stack_a);
	else if (stack_a->size == 4)
		four_elements(stack_a, stack_b);
	else if (stack_a->size == 5)
		five_elements(stack_a, stack_b);
	else
	{
		mappping_index_stack(stack_a, array_temp);
		radix_sort(stack_a, stack_b);
	}
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

int	main(int argc, char **argv)
{
	t_data	data;

	check_arguments(argv);
	ft_bzero(&data, sizeof(t_data));
	add_argv_to_stack(argc, argv, &data);
	handle_stack(&data.stack_a, &data.stack_b, data.array_temp);
	show_stack(&data.stack_a);
	delete_data(&data);
	return (0);
}
