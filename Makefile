NAME = ft_select

SRC = srcs/main.c ./lib/libft.a srcs/signial.c srcs/ft_print.c srcs/tools.c srcs/tools2.c srcs/lateral_cursor.c srcs/vertical_cursor.c srcs/key.c

FLAGS = -Wall -Wextra -Werror

SRC2 = test.o

all: $(NAME)

%.o : %.c
	gcc -c -o $@ $^

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc  -I include  -lncurses  $(SRC) -o $(NAME)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all