# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 12:33:44 by thugo             #+#    #+#              #
#    Updated: 2016/11/14 11:07:49 by thugo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILE_SRC = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen\
		   ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr\
		   ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isspace\
		   ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strupper ft_strlower\
		   ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap\
		   ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_abs\
		   ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd\
		   ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter\
		   ft_memdup ft_lstmap ft_lstinsert ft_is_negative

all: $(NAME)

$(NAME):
	@echo "\033[34mCreation de la librairie $(NAME)...\033[0m"
	@gcc -Werror -Wall -Wextra -c $(FILE_SRC:=.c)
	@ar rc $(NAME) $(FILE_SRC:=.o)
	@ranlib $(NAME)
	@echo "\033[32mTermine\033[0m"

clean:
	@echo "\033[34mSuppression des objets...\033[0m"
	@/bin/rm -f $(FILE_SRC:=.o)

fclean: clean
	@echo "\033[34mSuppression de la librairie...\033[0m"
	@/bin/rm -f $(NAME)

re: fclean all
