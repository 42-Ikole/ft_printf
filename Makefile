# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ikole    <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/03 09:14:14 by ivan-tol      #+#    #+#                  #
#    Updated: 2019/12/05 17:13:29 by ivan-tol      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c src/ft_helpers.c src/ft_printers.c src/ft_check_flags.c \
	  src/ft_check_whitespace.c src/ft_conversions.c src/ft_print_hex.c \
	  src/ft_print_hex.c src/ft_fillvar.c src/ft_print_nbr.c \
	  src/helpers_too.c src/ft_printlen.c src/ft_wideprint.c \
	  src/helpers_aswell.c src/ft_widechar.c

OFILES = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)

%.o: %.c
	gcc -c $(CFLAGS) $? -o $@

bonus: $(NAME)

re: fclean all

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)
