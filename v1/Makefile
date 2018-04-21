NAME = lem-in

LBMK = make -C libft/ fclean && make -C libft/

SRCS = error_check.c get_next_line.c lem_in.c atoi_lem.c way.c wave.c fin.c list_way.c \
run.c check_valid_way.c body.c strjoin_lem.c first_block.c second_block.c free.c pushback.c \
way_first.c

GCCO = gcc -Wall -Wextra -Werror -c $(SRCS) -Ilem_in.h
GCC = gcc -Wall -Wextra -Werror *.o ./libft/libft.a -o lem-in

all: $(NAME)

$(NAME): $(SRCS) lem_in.h
	$(LBMK)
	$(GCCO)
	$(GCC)
clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	/bin/rm -f lem-in
	make fclean -C libft

re: fclean all