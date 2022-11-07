#include <push_swap.h>

void	swap_b(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	else
	{
		temp = stack_b->head;
		stack_b->head = stack_b->head->next;
		temp->next = stack_b->head->next;
		stack_b->head->next = temp;
		ft_putstr_fd("sb\n", 1);
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	value_temp;

	if (stack_a->head == NULL)
		return ;
	value_temp = stack_a->head->item;
	delete_at_head(stack_a);
	insert_at_head(value_temp, stack_b);
	ft_putstr_fd("pb\n", 1);
}

void	rotate_b(t_stack *stack_b)
{
	int	temp;

	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	else
	{
		temp = stack_b->head->item;
		delete_at_head(stack_b);
		insert_at_tail(temp, stack_b);
		ft_putstr_fd("rb\n", 1);
	}
}

void	rotate_reverse_b(t_stack *stack_b)
{
	int temp;

	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	else
	{
		temp = stack_b->tail->item;
		delete_at_tail(stack_b);
		insert_at_head(temp, stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
}