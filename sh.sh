make -C libft/ fclean && make -C libft/
#clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test main.o -I libft/includes -L libft/ -lft