/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:58:32 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 04:00:28 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	two_elements(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value)
		swap_stack(stack, "sa\n");
}

void	three_elements(t_stack *stack)
{
	int	position_bigger_number;

	position_bigger_number = get_postion_bigger_number(stack);
	if (!check_is_stack_sorting(stack))
	{
		if (position_bigger_number == 0)
		{
			rotate_stack(stack, "ra\n");
			two_elements(stack);
		}
		else if (position_bigger_number == 1)
		{
			rotate_reverse_stack(stack, "rra\n");
			two_elements(stack);
		}
		else if (position_bigger_number == 2)
			two_elements(stack);
	}
}

void	four_elements(t_stack *stack_a, t_stack *stack_b)
{
	int	position_lower_number;

	position_lower_number = get_postion_lower_number(stack_a);
	if (!check_is_stack_sorting(stack_a))
	{
		if (position_lower_number == 0)
		{
			push_stack(stack_a, stack_b, "pb\n");
			three_elements(stack_a);
			push_stack(stack_b, stack_a, "pa\n");
		}
		else if (position_lower_number == 1)
		{
			swap_stack(stack_a, "sa\n");
			four_elements(stack_a, stack_b);
		}
		else if (position_lower_number == 2 || position_lower_number == 3)
		{
			rotate_reverse_stack(stack_a, "rra\n");
			four_elements(stack_a, stack_b);
		}
	}
}

void	five_elements(t_stack *stack_a, t_stack *stack_b)
{
	int	position_lower_number;

	position_lower_number = get_postion_lower_number(stack_a);
	if (!check_is_stack_sorting(stack_a))
	{
		if (position_lower_number == 0)
		{
			push_stack(stack_a, stack_b, "pb\n");
			four_elements(stack_a, stack_b);
			push_stack(stack_b, stack_a, "pa\n");
		}
		else if (position_lower_number == 1 || position_lower_number == 2)
		{
			rotate_stack(stack_a, "ra\n");
			five_elements(stack_a, stack_b);
		}
		else if (position_lower_number == 3 || position_lower_number == 4)
		{
			rotate_reverse_stack(stack_a, "rra\n");
			five_elements(stack_a, stack_b);
		}
	}
}
