#include <push_swap.h>

void	same_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putstr_fd("ss", 1);
}

void	same_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putstr_fd("rr", 1);
}

void	same_rotate_reverse(t_stack *stack_a, t_stack *stack_b)
{
	rotate_reverse_a(stack_a);
	rotate_reverse_b(stack_b);
	ft_putstr_fd("rrr", 1);
}