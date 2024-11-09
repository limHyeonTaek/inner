# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 11:07:06 by hylim             #+#    #+#              #
#    Updated: 2024/11/07 14:24:46 by hylim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(MLX_PATH) -I$(PRINTF_PATH)

NAME = fdf

MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)libmlx_Linux.a
MLX_LIBS = -lXext -lX11 -lm

PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)libftprintf.a
INCLUDES = ./includes

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/

SRCS = $(SRC_DIR)close.c \
       $(SRC_DIR)color.c \
       $(SRC_DIR)draw.c \
       $(SRC_DIR)error.c \
       $(SRC_DIR)init_utils.c \
       $(SRC_DIR)init.c \
       $(SRC_DIR)key_handle_bonus.c \
       $(SRC_DIR)key_handle_util_bonus.c \
       $(SRC_DIR)key_update_bonus.c \
       $(SRC_DIR)main.c \
       $(SRC_DIR)menu.c \
       $(SRC_DIR)mouse_handle.c \
       $(SRC_DIR)project_bonus.c \
       $(SRC_DIR)read.c \
       $(SRC_DIR)render.c \
       $(SRC_DIR)rotate_bonus.c \
       $(SRC_DIR)transform_bonus.c \
       $(SRC_DIR)utils.c \
       $(SRC_DIR)utils2.c

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

RM = rm -rf

LEAKS       = valgrind
LEAKS_FILE  = valgrind-out.txt
LF          = --leak-check=full \
              --show-leak-kinds=all \
              --track-origins=yes \
              --verbose \
              --log-file=$(LEAKS_FILE) \
              ./fdf maps/test_maps/42.fdf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(PRINTF_PATH) -lftprintf -L$(MLX_PATH) -lmlx $(MLX_LIBS) 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	make -C $(MLX_PATH)

$(PRINTF):
	make -C $(PRINTF_PATH)

clean:
	$(RM) $(OBJ_DIR)
	make -C $(PRINTF_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(LEAKS_FILE)

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF_PATH) fclean
	make -C $(MLX_PATH) clean

bonus: all

leaks: 
	$(LEAKS) $(LF)

re: fclean all

.PHONY: clean fclean re all leaks bonus