CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRC = push_swap.c\
	add_to_list.c\
	case2.c\
	case3.c\
	case4to45.c\
	caseover45.c\
	cost_calculation.c\
	create_lis.c\
	ft_atoi.c\
	ft_atol.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isdigit.c\
	ft_strlen.c\
	get_a_movements.c\
	get_lower_cost_index.c\
	is_sorted.c\
	lis_and_push.c\
	min_max.c\
	my_ternarie.c\
	optimizing_cost.c\
	push_px.c\
	push_rrx.c\
	push_rx.c\
	push_sx.c\
	recalculate_index.c\
	verification.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -fsanitize=address -g3

all: $(NAME)

.o: .c
	$(CC) -o $@ -c $< $(CFLAGS)

fclean: clean
	rm -f $(NAME)
clean:
	rm -f $(OBJ)

re : fclean all
