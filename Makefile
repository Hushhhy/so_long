# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 14:48:00 by acarpent          #+#    #+#              #
#    Updated: 2024/07/03 12:44:28 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	./src/main.c\
				./src/close.c\
				./src/delete.c\
				./src/ft_floodfill.c\
				./src/gaming.c\
				./src/get_image.c\
				./src/move.c\
				./src/parsing_utils.c\
				./src/parsing.c\
				./get_next_line/get_next_line.c\
				./get_next_line/get_next_line_utils.c\

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(BONUS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3

RM			=	rm -f

LIBFT_PATH	=	./libft

PRINTF_PATH	=	./ft_printf

LIBFT		=	$(LIBFT_PATH)/libft.a

PRINTF		=	$(PRINTF_PATH)/libftprintf.a

MINILIBX	=	make -C ./mlx/

MLXFLAGS	=	-Lmlx_linux -L/usr/lib -lXext -lX11 -lm -lz

MLX_EX		=	$(MLX_PATH)/libmlx.a

MLX_PATH	=	./mlx

NAME		=	so_long

all: $(NAME)

%.o:	%.c
		$(CC) $(CFLAGS) -I$(LIBFT_PATH) -I$(PRINTF_PATH) -c $? -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
		$(CC) $(CLFAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_EX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH)

$(PRINTF):
		$(MAKE) -C $(PRINTF_PATH)

clean:
		$(RM) $(OBJS) 
		make clean -sC $(LIBFT_PATH)
		make clean -sC $(PRINTF_PATH)

fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIBFT_PATH)
		$(MAKE) fclean -C $(PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re
