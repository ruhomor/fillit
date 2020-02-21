# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 20:18:27 by kachiote          #+#    #+#              #
#    Updated: 2020/02/21 20:33:06 by kachiote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFILES = tetraminos \
		 main \
		 fillit

SRCS = $(patsubst %, %.c, $(CFILES))

OUT = $(patsubst %, %.o, $(CFILES))

INCL = ./

FLAGS = -Werror -Wall -Wextra

LIB = ./libft

all: $(NAME)

%.o:%.c -I$(INCL)
	@gcc $(FLAGS) $(INCL) $< -o $@

$(NAME):
	@make -C $(LIB)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(INCL) -L. libft/libft.a

clean:
	@rm -f $(OUT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
