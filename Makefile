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
pf_p.c ft_atoi.c ft_strchr.c ft_memset.c ft_strlen.c

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
