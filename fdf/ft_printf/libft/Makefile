# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 10:20:06 by hylim             #+#    #+#              #
#    Updated: 2024/11/04 20:15:34 by hylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libft.a

SRCS					= ft_atoi.c \
						ft_bzero.c \
						ft_calloc.c \
						ft_isalnum.c \
						ft_isalpha.c \
						ft_isascii.c \
						ft_isdigit.c \
						ft_isprint.c \
						ft_itoa.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_memset.c \
						ft_putchar_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_putstr_fd.c \
						ft_split.c \
						ft_strcat.c \
						ft_strchr.c \
						ft_strcpy.c \
						ft_strdup.c \
						ft_striteri.c \
						ft_strjoin.c \
						ft_strlcat.c \
						ft_strlcpy.c \
						ft_strlen.c \
						ft_strmapi.c \
						ft_strncmp.c \
						ft_strncpy.c \
						ft_strnstr.c \
						ft_strrchr.c \
						ft_strtrim.c \
						ft_substr.c \
						ft_tolower.c \
						ft_toupper.c \
						get_next_line.c

BNS_SRCS				= ft_lstadd_back_bonus.c \
						ft_lstadd_front_bonus.c \
						ft_lstclear_bonus.c \
						ft_lstdelone_bonus.c \
						ft_lstiter_bonus.c \
						ft_lstlast_bonus.c \
						ft_lstmap_bonus.c \
						ft_lstnew_bonus.c \
						ft_lstsize_bonus.c

OBJS					= $(SRCS:%.c=%.o)
BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

CC						= cc
CFLAGS					= -Wall -Wextra -Werror

AR						= ar
ARFLAGS					= rcs

RM						= rm -f

$(NAME)		: $(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o			: %.c
			$(CC) $(CFLAGS) -c $< -o $@

make_bonus	: $(BNS_OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(BNS_OBJS)
			touch $@

bonus		: make_bonus
		
all			: $(NAME)

clean		:
			$(RM) $(OBJS) $(BNS_OBJS)
			$(RM) make_bonus

fclean		: clean
			$(RM) $(NAME)

re			: fclean all

.PHONY: all clean fclean re bonus
