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
	add_argv_to_stack(argv, stack_a);
}

void	handle_list(t_stack *stack_a, t_stack *stack_b)
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
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	int *array_temp;

	create_stack(&stack_a, &stack_b);
	check_argv(argc, argv, &stack_a);
	handle_list(&stack_a, &stack_b);

	delete_all(&stack_a);
	delete_all(&stack_b);
	return (0);
}