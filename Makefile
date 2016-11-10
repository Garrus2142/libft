# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 12:33:44 by thugo             #+#    #+#              #
#    Updated: 2016/11/10 19:26:47 by thugo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
FILE_SRC = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen\
		   ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr\
		   ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isspace\
		   ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strupper ft_strlower\
		   ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap\
		   ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_abs\
		   ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd\
		   ft_putendl_fd ft_putnbr_fd

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
