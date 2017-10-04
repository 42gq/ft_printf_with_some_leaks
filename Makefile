# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gquerre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 05:42:43 by gquerre           #+#    #+#              #
#    Updated: 2017/10/02 00:49:06 by gquerre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC  = ./*.c ./handlers/*.c ./apply/*.c ./SRC/libft/SRC/*.c

FLAG = -Wextra -Wall -Werror

SUPP = ./ft_printf.h ./SRC/libft/SRC/libft.h

OBJ = ./*.o

# -fsanitize=address after -c #

all: $(NAME)

$(NAME): $(SRC)
	gcc -I $(SUPP) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.Phony: clean all fclean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
