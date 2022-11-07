#include <push_swap.h>

int	get_postion_lower_number(t_stack *stack)
{
	t_node	*node_temp;
	int		number_aux[3];

	node_temp = stack->head;
	number_aux[0] = node_temp->item;
	number_aux[1] = 0;
	number_aux[2] = 0;
	while (node_temp)
	{
		if (node_temp->item < number_aux[0])
		{
			number_aux[0] = node_temp->item;
			number_aux[1] = number_aux[2];
		}
		node_temp = node_temp->next;
		number_aux[2]++;
	}
	return (number_aux[1]);
}

int	get_postion_bigger_number(t_stack *stack)
{
	t_node	*node_temp;
	int		number_aux[3];

	node_temp = stack->head;
	number_aux[0] = node_temp->item;
	number_aux[1] = 0;
	number_aux[2] = 0;
	while (node_temp)
	{
		if (node_temp->item > number_aux[0])
		{
			number_aux[0] = node_temp->item;
			number_aux[1] = number_aux[2];
		}
		node_temp = node_temp->next;
		number_aux[2]++;
	}
	return (number_aux[1]);
}

int	check_is_stack_sorting(t_stack *stack)
{
	t_node *node_temp;

	node_temp = stack->head;
	while (node_temp->next != NULL)
	{
		if (node_temp->item > node_temp->next->item)
			return (false);
		node_temp = node_temp->next;
	}
	return (true);
}