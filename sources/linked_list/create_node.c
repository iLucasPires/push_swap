#include <push_swap.h>

t_node	*get_new_node(int value, int value_n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->value_normalized = value_n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	insert_at_tail(int value, int value_n, t_stack *stack)
{
	t_node	*new_node;

	new_node = get_new_node(value, value_n);
	stack->size++;
	if (stack->head == NULL)
	{
		stack->tail = new_node;
		stack->head = new_node;
		return ;
	}
	stack->tail->next = new_node;
	new_node->prev = stack->tail;
	stack->tail = new_node;
}

void	insert_at_head(int value, int value_n, t_stack *stack)
{
	t_node	*new_node;

	new_node = get_new_node(value, value_n);
	stack->size++;
	if (stack->head == NULL)
	{
		stack->tail = new_node;
		stack->head = new_node;
		return ;
	}
	stack->head->prev = new_node;
	new_node->next = stack->head;
	stack->head = new_node;
}
