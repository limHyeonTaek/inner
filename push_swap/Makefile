# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 15:21:48 by hylim             #+#    #+#              #
#    Updated: 2024/10/29 15:35:02 by hylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)
INCLUDES = -I.

MAN_DIR = mandatory/
BNS_DIR = bonus/


MAN_SRCS = $(MAN_DIR)push_swap.c \
		$(MAN_DIR)ps_location.c \
		$(MAN_DIR)ps_operation.c \
		$(MAN_DIR)ps_operation2.c \
		$(MAN_DIR)ps_operation3.c \
		$(MAN_DIR)ps_sort.c \
		$(MAN_DIR)ps_stack.c \
		$(MAN_DIR)ps_stack2.c \
		$(MAN_DIR)ps_utils.c \
		$(MAN_DIR)ps_utils2.c \
		$(MAN_DIR)ps_validate.c \
		$(MAN_DIR)ps_rotate.c

BNS_SRCS = $(BNS_DIR)checker_bonus.c \
		$(BNS_DIR)ps_operation_bonus.c \
		$(BNS_DIR)ps_operation2_bonus.c \
		$(BNS_DIR)ps_operation3_bonus.c \
		$(BNS_DIR)ps_stack_bonus.c \
		$(BNS_DIR)ps_stack2_bonus.c \
		$(BNS_DIR)ps_utils_bonus.c \
		$(BNS_DIR)ps_utils2_bonus.c \
		$(BNS_DIR)ps_validate_bonus.c

OBJS = $(MAN_SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

BONUS = checker
MANDATORY = push_swap

LIB_DIR = ./ft_printf
LIB = ftprintf

RM = rm -rf

%.o 			: %c
		$(CC) $(CFLAGS) $(MAN_INCLUDES) -c $< -o $@

$(MANDATORY) 	: $(OBJS)
			make -C $(LIB_DIR)
			$(CC) -g $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -l$(LIB)

bonus			: $(BONUS)

$(BONUS)		: $(BNS_OBJS)
			make -C $(LIB_DIR)
			$(CC) -g $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -l$(LIB)

all 			: $(MANDATORY)

clean			:
			make -C $(LIB_DIR) clean
			$(RM) $(OBJS)
			$(RM) $(BNS_OBJS)

fclean 			: clean
			make -C $(LIB_DIR) fclean
			$(RM) $(MANDATORY)
			$(RM) $(BONUS)

re 				:
			make fclean
			make all

.PHONY			: all clean fclean re bonus
