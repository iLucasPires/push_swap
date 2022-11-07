#include <push_swap.h>

void	swap_a(t_stack *stack_a)
{
	int swap[2];

	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	else
	{
		swap[0] = stack_a->head->item;
		swap[1] = stack_a->head->next->item;
		delete_at_head(stack_a);
		delete_at_head(stack_a);
		insert_at_head(swap[0], stack_a);
		insert_at_head(swap[1], stack_a);
		ft_putstr_fd("sa\n", 1);
	}
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int value_temp;

	if (stack_b->head == NULL)
		return ;
	value_temp = stack_b->head->item;
	delete_at_head(stack_b);
	insert_at_head(value_temp, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	rotate_a(t_stack *stack_a)
{
	int	temp;

	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	else
	{
		temp = stack_a->head->item;
		delete_at_head(stack_a);
		insert_at_tail(temp, stack_a);
		ft_putstr_fd("ra\n", 1);
	}
}

void	rotate_reverse_a(t_stack *stack_a)
{
	int temp;

	if (stack_a->head == NULL )
		return ;
	else
	{
		temp = stack_a->tail->item;
		delete_at_tail(stack_a);
		insert_at_head(temp, stack_a);
		ft_putstr_fd("rra\n", 1);
	}
}