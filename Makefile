# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/27 13:16:22 by seruiz       #+#   ##    ##    #+#        #
#    Updated: 2019/12/31 13:38:59 by seruiz      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = ft_printf.h

SRC = ft_printf.c\
	  ft_printf_str.c\
	  ft_prec_width_itoa.c\
	  ft_print_base.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

bonus : $(NAME)

re : fclean all

%.o : %.c $(LIB)
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME) : $(OBJ) $(LIB)
	ar rcs $(NAME) $(OBJ) $(LIB)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

.PHONY : clean all re fclean
