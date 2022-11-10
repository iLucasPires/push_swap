NAME =		push_swap
HEADER =	-I ./include
OBJ_DIR =	./objects
LIBFT =	./libft/libft.a

SOURCES  =	main.c movements.c sort_stack.c check_arguments.c check_stack.c
SOURCES +=	create_node.c delete_node.c double_movements.c quick_sort.c radix_sort.c
OBJ		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))
CFLAGS =	cc -g3 -O3 
VPATH = ./sources ./sources/linked_list ./sources/operations ./sources/sort ./sources/check ./sources/aux

NUMBERS = 0 1 2 3 2147483649 5 6 7 8 9
all: $(NAME)

run: re $(NAME)
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
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus