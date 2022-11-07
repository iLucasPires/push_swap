NAME =		push_swap
HEADER =	-I ./include
OBJ_DIR =	./objects
LIBFT =	./libft/libft.a

SOURCES  =	main.c movements_a.c movements_b.c sort_stack.c check_arguments.c check_stack.c 
SOURCES +=	create_node.c delete_node.c display_node.c double_movements.c normalize.c quick_sort.c
OBJ		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))
CFLAGS =	cc -g3 -O3 
VPATH = ./sources ./sources/linked_list ./sources/operations ./sources/sort 

NUMBERS =  6 5 3 1 9 7 45 12 54 65
all: $(NAME)

run: $(NAME)
	./push_swap $(NUMBERS)

test: $(NAME)
	./push_swap $(NUMBERS) | ./checker_linux $(NUMBERS)

valgrind: $(NAME)
	valgrind --leak-check=full ./$(NAME) $(NUMBERS)

$(NAME): $(OBJ) $(LIBFT)  
	$(CFLAGS) $(HEADER) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

$(OBJ_DIR)/%.o: %.c 
	@mkdir -p $(OBJ_DIR)
	$(CFLAGS) -c $< -o $@ $(HEADER)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus