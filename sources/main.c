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

void	show_stack(t_stack *stack)
{
	t_node	*node_temp;

	node_temp = stack->tail;
	while (node_temp != NULL)
	{
		printf("%d ", node_temp->value);
		node_temp = node_temp->prev;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_arguments(argv);
	ft_bzero(&data, sizeof(t_data));
	add_argv_to_stack(argc, argv, &data);
	handle_stack(&data.stack_a, &data.stack_b, data.array_temp);
	delete_data(&data);
	return (0);
}
