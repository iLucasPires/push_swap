/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:59:05 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 19:50:31 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>	
# define A 0
# define B 1
# define MAX_INT "2147483647"
# define MIN_INT "2147483648"

enum				e_bool
{
	false,
	true
};

typedef struct s_node
{
	int				value;
	int				value_normalized;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*head;
	t_node			*tail;
}					t_stack;

typedef struct s_data
{
	t_stack			stack_a;
	t_stack			stack_b;
	int				*array_temp;
}					t_data;

void				check_arguments(char **argv);
t_node				*get_new_node(int value, int value_n);
void				insert_at_tail(int value, int valeu_n, t_stack *stack);
void				insert_at_head(int value, int valeu_n, t_stack *stack);

void				delete_at_head(t_stack *stack);
void				delete_at_tail(t_stack *stack);
void				delete_data(t_data *data);
void				delete_stack(t_stack *stack);

void				two_elements(t_stack *stack);
void				three_elements(t_stack *stack);
void				four_elements(t_stack *stack_a, t_stack *stack_b);
void				five_elements(t_stack *stack_a, t_stack *stack_b);

void				swap_stack(t_stack *stack_b, char *str);
void				push_stack(t_stack *stack_a, t_stack *stack_b, char *str);
void				rotate_stack(t_stack *stack_a, char *str);
void				rotate_reverse_stack(t_stack *stack_a, char *str);
void				same_swap(t_stack *stack_a, t_stack *stack_b);
void				same_rotate(t_stack *stack_a, t_stack *stack_b);
void				same_rotate_reverse(t_stack *stack_a, t_stack *stack_b);

int					check_is_stack_sorting(t_stack *stack);
int					get_postion_lower_number(t_stack *stack);
int					get_postion_bigger_number(t_stack *stack);

void				quick_sort(int *array, int low, int high);
void				mappping_index_stack(t_stack *stack, int *array_temp);
void				radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif