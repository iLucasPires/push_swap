/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:58:40 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 03:58:41 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (array[j] <= pivot)
		{
			i += 1;
			swap(&array[i], &array[j]);
		}
		j += 1;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quick_sort(int *array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
	}
}

void	mappping_index_stack(t_stack *stack, int *array_temp)
{
	t_node	*node_temp;
	int		index[2];

	index[0] = 0;
	node_temp = stack->head;
	quick_sort(array_temp, 0, stack->size - 1);
	while (index[0] < stack->size)
	{
		index[1] = 0;
		while (index[1] < stack->size)
		{
			if (node_temp->value == array_temp[index[1]])
			{
				node_temp->value_normalized = index[1];
				break ;
			}
			index[1]++;
		}
		node_temp = node_temp->next;
		index[0]++;
	}
}
