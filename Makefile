# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 20:18:27 by kachiote          #+#    #+#              #
#    Updated: 2020/02/21 20:48:45 by kachiote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fillit

CFILES = tetraminos \
		 main \
		 fillit

SRCS = $(patsubst %, %.c, $(CFILES))

OUT = $(patsubst %, %.o, $(CFILES))

INCL = ./

CFLAGS = -Werror -Wall -Wextra

LIB = ./libft

all: $(NAME)

%.o:%.c -I$(INCL)
	@$(CC) $(CFLAGS) $(INCL) $< -o $@

$(NAME):
	@make -C $(LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCL) -L. libft/libft.a

clean:
	@rm -f $(OUT)
	@make -C $(LIB) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re
