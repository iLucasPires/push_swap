#include <push_swap.h>

void	mappping_index_stack(t_stack *stack, int *array_temp)
{
	t_node	*node_temp;
	int		index[2];

	index[0] = 0;
	node_temp = stack->head;
	while (index[0] < stack->size)
	{
		index[1] = 0;
		while (index[1] < stack->size)
		{
			if (node_temp->item == array_temp[index[1]])
			{
				node_temp->index = index[1];
				break ;
			}
			index[1]++;
		}
		node_temp = node_temp->next;
		index[0]++;
	}
}
