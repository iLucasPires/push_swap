/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:00:13 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 04:00:13 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_bit_size(int size)
{
	int	max_bit;
	int	bits_size;

	max_bit = 0;
	bits_size = size;
	while (bits_size)
	{
		max_bit += 1;
		bits_size = bits_size >> 1;
	}
	return (max_bit);
}

static void	push_bit(t_stack *stack_a, t_stack *stack_b, int bit,
		int bigger_number)
{
	int	index_list;

	index_list = 0;
	while (index_list < bigger_number)
	{
		if (((stack_a->head->value_normalized >> bit) & 1) == 1)
			rotate_stack(stack_a, "ra\n");
		else
			push_stack(stack_a, stack_b, "pb\n");
		index_list++;
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	index_bit;
	int	size_bigger_bits;
	int	biggest_number;

	index_bit = 0;
	size_bigger_bits = get_bit_size(stack_a->size);
	biggest_number = stack_a->size;
	while (index_bit < size_bigger_bits)
	{
		push_bit(stack_a, stack_b, index_bit, biggest_number);
		while (stack_b->head)
			push_stack(stack_b, stack_a, "pa\n");
		index_bit += 1;
	}
}
