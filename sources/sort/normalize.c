#include <push_swap.h>

void mappping(t_stack *stack)
{
    int i = 0;
    int j = 0;
    int *array = (int *)malloc(sizeof(int) * stack->size);
    t_node *temp = stack->head;
    while (temp)
    {
        array[i] = temp->item;
        temp = temp->next;
        i++;
    }
    quick_sort(array, 0, stack->size - 1);
    temp = stack->head;
    while (temp)
    {
        temp->index = array[j];
        temp = temp->next;
        j++;
    }
    free(array);
}

void normalize(int size, t_stack *stack)
{
    int i = 0;
    int j = 0;
    int *array = (int *)malloc(sizeof(int) * size);
    t_node *temp = stack->head;
    while (temp)
    {
        array[i] = temp->item;
        temp = temp->next;
        i++;
    }
    quick_sort(array, 0, size - 1);
    temp = stack->head;
    while (temp)
    {
        temp->item = array[j];
        temp = temp->next;
        j++;
    }
    free(array);
}

void show_index(t_stack *stack)
{
    t_node *temp = stack->head;
    normalize(stack->size, stack);
    while (temp)
    {
        printf("%d ", temp->index);
        temp = temp->next;
    }
}