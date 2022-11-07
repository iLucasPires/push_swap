#include <push_swap.h>

void	two_elements(t_stack *stack)
{
	if (stack->head->item > stack->head->next->item)
		swap_a(stack);
}

void	three_elements(t_stack *stack)
{
	int	position_bigger_number;

	position_bigger_number = get_postion_bigger_number(stack);
	if (!check_is_stack_sorting(stack))
		if (position_bigger_number == 0)
		{
			rotate_a(stack);
			two_elements(stack);
		}
		else if (position_bigger_number == 1)
		{
			rotate_reverse_a(stack);
			two_elements(stack);
		}
		else if (position_bigger_number == 2)
			two_elements(stack);
}

void	four_elements(t_stack *stack_a, t_stack *stack_b)
{
	int	position_lower_number;

	position_lower_number = get_postion_lower_number(stack_a);
	if (!check_is_stack_sorting(stack_a))
		if (position_lower_number == 0)
		{
			push_b(stack_a, stack_b);
			three_elements(stack_a);
			push_a(stack_a, stack_b);
		}
		else if (position_lower_number == 1)
		{
			swap_a(stack_a);
			four_elements(stack_a, stack_b);
		}
		else if (position_lower_number == 2 || position_lower_number == 3)
		{
			rotate_reverse_a(stack_a);
			four_elements(stack_a, stack_b);
		}
}

void	five_elements(t_stack *stack_a, t_stack *stack_b)
{
	int	position_lower_number;

	position_lower_number = get_postion_lower_number(stack_a);
	if (!check_is_stack_sorting(stack_a))
		if (position_lower_number == 0)
		{
			push_b(stack_a, stack_b);
			four_elements(stack_a, stack_b);
			push_a(stack_a, stack_b);
		}
		else if (position_lower_number == 1 || position_lower_number == 2)
		{
			rotate_a(stack_a);
			five_elements(stack_a, stack_b);
		}
		else if (position_lower_number == 3 || position_lower_number == 4)
		{
			rotate_reverse_a(stack_a);
			five_elements(stack_a, stack_b);
		}
}

void	more_than_five(t_stack *stack_a, t_stack *stack_b, int *array_temp)
{

	t_node *node_temp;
	printf("more_than_five\n");
	quick_sort(array_temp, 0, stack_a->size - 1);
	mappping_index_stack(stack_a, array_temp);

	node_temp = stack_a->head;
	while (node_temp)
	{
		printf("item = %d, index = %d\n", node_temp->item, node_temp->index);
		node_temp = node_temp->next;
	}
}
