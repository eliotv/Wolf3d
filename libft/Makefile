# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 12:52:19 by evanheum          #+#    #+#              #
#    Updated: 2017/06/13 12:19:44 by evanheum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

LIBFT = ft_atoi.c \
	  ft_bzero.c \
	  ft_count_c.c \
	  ft_count_int_len.c \
	  ft_count_unint_len.c \
	  ft_count_wrd.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa_base.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putnchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstrn.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchar.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strndup.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_swap.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_count_wrd.c \
	  ft_count_c.c \
	  ft_isspace.c \
	  ft_u_itoa_bs.c \

GET_NEXT_LINE = get_next_line.c

FT_PRINTF = ft_printf.c \
			build.c \
			conversion.c \
			conversion2.c \
			flagmod.c \
			functionfinder.c \
			lengthmod.c \
			percisionmod.c \
			widthmod.c \
			print.c \
			print2.c \

FILES =		$(addprefix libft/, $(LIBFT)) \
			$(addprefix get_next_line/, $(GET_NEXT_LINE)) \
			$(addprefix ft_printf/, $(FT_PRINTF)) \

SRC = $(addprefix src/, $(FILES))

OBJ = *.o \

all:  $(NAME)

$(NAME): $(SRC)
	@gcc $(CFLAGS) -c $(SRC)
	@echo "\033[32m -- Object Files Created --\n\033][0m"

	@ar rc $(NAME) $(OBJ)
	@echo "\033[   -- Libft.a Created --"

clean:
	@rm -f $(OBJ)
	@echo "\033[31m -- Object Files Removed --\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m   -- Libft.a Removed --\033[0m"

re: fclean all
