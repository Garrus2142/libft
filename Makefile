# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 12:33:44 by thugo             #+#    #+#              #
#    Updated: 2017/02/18 12:42:25 by thugo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILE_SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
		   ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		   ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isspace.c\
		   ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strupper.c ft_strlower.c\
		   ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
		   ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_abs.c\
		   ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
		   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
		   ft_memdup.c ft_lstmap.c ft_lstinsert.c ft_is_negative.c ft_strndup.c ft_strnjoin.c ft_lstlen.c\
		   ft_tabptrlen.c ft_tabptrfree.c ft_lstrem.c ft_strfjoin.c ft_pow.c ft_atoi_base.c ft_itoa_base.c\
		   ft_to_utf8.c ft_llitoa_base.c ft_lluitoa_base.c ft_max.c ft_min.c ft_wstrlen.c ft_memjoin.c ft_printf.c\
		   buffermanager.c convert_dioux.c convert_extra.c convert_sc.c vaargs.c parsing.c ft_lstaddsort.c\
		   ft_tabfree.c ft_path_getfile.c

OBJ = $(FILE_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[34mCreation de la librairie $(NAME)...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mTermine\033[0m"

%.o: %.c
	@echo "\033[34mCompilation:\033[0m $^ \033[34m>\033[0m $@"
	@gcc -Werror -Wall -Wextra -c $^

clean:
	@echo "\033[34mSuppression des objets...\033[0m"
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "\033[34mSuppression de la librairie...\033[0m"
	@/bin/rm -f $(NAME)

re: fclean all
