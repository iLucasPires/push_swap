#include <push_swap.h>

void	create_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
}

void	check_argv(int argc, char **argv, t_stack *stack_a)
{
	check_overflow(argv);
	check_duplicate(argv);
	check_is_sorting(argv);
}

void	handle_list(t_stack *stack_a, t_stack *stack_b, int *array_temp)
{
	if (stack_a->size == 0 && stack_b->size == 0)
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
		more_than_five(stack_a, stack_b, array_temp);
}

int	main(int argc, char **argv)
{
	t_data data;
	if (argc == 1)
		return (0);
	create_stack(&data.stack_a, &data.stack_b);
	check_argv(argc, argv, &data.stack_a);
	data.array_temp = malloc(sizeof(int) * (argc - 1));
	add_argv_to_stack(argv, &data.stack_a, data.array_temp);
	handle_list(&data.stack_a, &data.stack_b, data.array_temp);
	delete_all(&data.stack_a);
	delete_all(&data.stack_b);
	free(data.array_temp);
	return (0);
}