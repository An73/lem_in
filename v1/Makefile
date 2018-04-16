NAME = lem-in

LBMK = make -C libft/ fclean && make -C libft/

SRCS = error_check.c get_next_line.c lem-in.c atoi_lem.c way.c wave.c fin.c list_way.c

GCCO = gcc -Wall -Wextra -Werror -c $(SRCS) -Ilem-in.h
GCC = gcc -Wall -Wextra -Werror *.o ./libft/libft.a -o lem-in

all: $(NAME)

$(NAME): $(SRCS) lem-in.h
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