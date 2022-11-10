#include <push_swap.h>

void	swap_stack(t_stack *stack, char *str)
{
	int	swap[2];

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	else
	{
		swap[0] = stack->head->value;
		swap[1] = stack->head->value_normalized;
		stack->head->value = stack->head->next->value;
		stack->head->value_normalized = stack->head->next->value_normalized;
		stack->head->next->value = swap[0];
		stack->head->next->value_normalized = swap[1];
		if (str != NULL)
			ft_putstr_fd(str, STDOUT_FILENO);
	}
}

void	push_stack(t_stack *origem, t_stack *destiny, char *str)
{
	int	value_temp[2];

	if (origem->head != NULL)
	{
		value_temp[0] = origem->head->value;
		value_temp[1] = origem->head->value_normalized;
		delete_at_head(origem);
		insert_at_head(value_temp[0], value_temp[1], destiny);
		if (str != NULL)
			ft_putstr_fd(str, STDOUT_FILENO);
	}
}

void	rotate_stack(t_stack *stack, char *str)
{
	int	value_temp[2];

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	else
	{
		value_temp[0] = stack->head->value;
		value_temp[1] = stack->head->value_normalized;
		delete_at_head(stack);
		insert_at_tail(value_temp[0], value_temp[1], stack);
		if (str != NULL)
			ft_putstr_fd(str, STDOUT_FILENO);
	}
}

void	rotate_reverse_stack(t_stack *stack, char *str)
{
	int value_temp[2];

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	else
	{
		value_temp[0] = stack->tail->value;
		value_temp[1] = stack->tail->value_normalized;
		delete_at_tail(stack);
		insert_at_head(value_temp[0], value_temp[1], stack);
		if (str != NULL)
			ft_putstr_fd(str, STDOUT_FILENO);
	}
}