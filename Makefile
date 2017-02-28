# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 14:50:07 by dkosolap          #+#    #+#              #
#    Updated: 2017/02/16 14:50:37 by dkosolap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -g

LIBR = -L./ -lftprintf

SRC = ft_printf.c pf_itoa.c pf_pars.c pf_int.c pf_char.c pf_string.c\
pf_u.c pf_ubig.c pf_und.c pf_itoa_u.c pf_x.c pf_o.c pf_dbig.c pf_obig.c\
pf_p.c\
ft_atoi.c ft_putchar.c ft_putstr.c ft_strlen.c ft_tolower.c ft_toupper.c\
ft_strdup.c ft_strcpy.c ft_strcmp.c ft_putnbr.c ft_strncpy.c ft_putendl.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c\
ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
ft_memcmp.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
ft_strstr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
ft_isascii.c ft_isprint.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_lstnew.c\
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstaddback.c ft_lstiter.c ft_lstmap.c\
ft_lstsize.c ft_lstlast.c ft_lstinsert.c ft_lstprint.c get_next_line.c\
ft_atoi_base.c ft_arrlen.c ft_lstdel2.c

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	ar rc $(NAME) $(BINS)
	ranlib $(NAME)

%.o: %.c
	gcc -c -o $@ $<

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

re: fclean all
