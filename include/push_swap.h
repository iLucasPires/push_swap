#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define A 0
# define B 1
# define MAX_INT "2147483647"
# define MIN_INT "-2147483648"

enum				e_bool
{
	false,
	true
};

typedef struct s_node
{
	int				item;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*head;
	t_node			*tail;
}					t_stack;

t_node				*get_new_node(int value);
void				insert_at_head(int value, t_stack *stack);
void				insert_at_tail(int value, t_stack *stack);
void				delete_at_head(t_stack *stack);
void				delete_at_tail(t_stack *stack);
void				delete_all(t_stack *stack);
void				display_all(t_stack *stack_a, t_stack *stack_b);
void				display_all_reverse(t_stack *stack);

void				two_elements(t_stack *stack);
void				three_elements(t_stack *stack);
void				four_elements(t_stack *stack_a, t_stack *stack_b);
void				five_elements(t_stack *stack_a, t_stack *stack_b);

//movements a
void				display_stack(t_stack *stack);
void				swap_b(t_stack *stack_b);
void				swap_a(t_stack *stack_a);
void				push_a(t_stack *stack_a, t_stack *stack_b);
void				push_b(t_stack *stack_a, t_stack *stack_b);
void				rotate_a(t_stack *stack_a);
void				rotate_b(t_stack *stack_b);
void				rotate_reverse_a(t_stack *stack_a);
void				rotate_reverse_b(t_stack *stack_b);
void				same_swap(t_stack *stack_a, t_stack *stack_b);
void				same_rotate(t_stack *stack_a, t_stack *stack_b);
void				same_rotate_reverse(t_stack *stack_a, t_stack *stack_b);

//handle error
int					get_postion_lower_number(t_stack *stack);
int					get_postion_bigger_number(t_stack *stack);
void				add_argv_to_stack(char **argv, t_stack *stack);
void				check_is_sorting(char **argv);
void				check_duplicate(char **argv);
void				check_overflow(char **argv);
int					check_is_stack_sorting(t_stack *stack);
void				six_elements(t_stack *stack_a, t_stack *stack_b);
void				quick_sort(int *array, int low, int high);
void				radix_sort(t_stack *stack_a, t_stack *stack_b);

void				normalize(int argc, t_stack *stack);
#endif