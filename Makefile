# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 12:33:44 by thugo             #+#    #+#              #
#    Updated: 2016/11/07 16:21:54 by thugo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
FILE_SRC = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove

.PHONY: all

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra -c $(FILE_SRC:=.c)
	ar rc $(NAME).a $(FILE_SRC:=.o)
	ranlib $(NAME).a

clean:
	rm -rf $(FILE_SRC:=.o)

fclean: clean
	rm -rf $(NAME).a

re: fclean all
