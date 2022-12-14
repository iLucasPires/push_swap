/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:58:46 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 03:59:21 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	same_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a, NULL);
	swap_stack(stack_b, NULL);
	ft_putstr_fd("ss", 1);
}

void	same_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a, NULL);
	rotate_stack(stack_b, NULL);
	ft_putstr_fd("rr", 1);
}

void	same_rotate_reverse(t_stack *stack_a, t_stack *stack_b)
{
	rotate_reverse_stack(stack_a, NULL);
	rotate_reverse_stack(stack_b, NULL);
	ft_putstr_fd("rrr", 1);
}
