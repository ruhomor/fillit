make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o tetraminos.o -c tetraminos.c
clang -Wall -Wextra -Werror -I libft/includes -o fillit.o -c fillit.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test main.o fillit.o tetraminos.o -I libft/includes -L libft/ -lft