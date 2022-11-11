/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:58:50 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 16:11:56 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	delete_stack(t_stack *stack)
{
	t_node	*node_temp;

	if (stack->head == NULL)
		return ;
	while (stack->head != NULL)
	{
		node_temp = stack->head;
		stack->head = stack->head->next;
		free(node_temp);
	}
}

void	delete_data(t_data *data)
{
	delete_stack(&data->stack_a);
	delete_stack(&data->stack_b);
	free(data->array_temp);
}

void	delete_at_head(t_stack *stack)
{
	t_node	*node_temp;

	if (stack->head == NULL)
		return ;
	node_temp = stack->head;
	stack->head = stack->head->next;
	if (stack->head != NULL)
		stack->head->prev = NULL;
	free(node_temp);
	stack->size--;
}

void	delete_at_tail(t_stack *stack)
{
	t_node	*node_temp;

	if (stack->head == NULL)
		return ;
	node_temp = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->tail != NULL)
		stack->tail->next = NULL;
	free(node_temp);
		stack->size--;
}
