#include <push_swap.h>

void	display_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	ft_putstr_fd("stack: ", 1);
	if (temp == NULL)
		ft_putstr_fd("empty", 1);
	while (temp != NULL)
	{
		ft_putnbr_fd(temp->item, 1);
		ft_putstr_fd(" ", 1);
		temp = temp->next;
	}
	ft_putstr_fd("\n", 1);
}

void	display_node(t_node *node)
{
	ft_putnbr_fd(node->item, 1);
	ft_putstr_fd("\n", 1);
}