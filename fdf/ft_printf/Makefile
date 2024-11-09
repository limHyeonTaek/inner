# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 19:28:32 by hylim             #+#    #+#              #
#    Updated: 2024/11/09 14:23:31 by hylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)

SRCS = 		ft_printf.c \
			print_hex.c \
			print_nbr.c \
			print_str.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT_FILE = libft.a

AR = ar
ARFLAGS = rcs
RM = rm -rf

all		: $(NAME)

$(NAME) : $(OBJS)
		make -C $(LIBFT_DIR)
		make -C $(LIBFT_DIR) bonus
		cp $(LIBFT_DIR)/$(LIBFT_FILE) $(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o 	: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean 	:
		make -C $(LIBFT_DIR) clean
		$(RM) $(OBJS)

fclean 	: clean
		make -C $(LIBFT_DIR) fclean
		$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re