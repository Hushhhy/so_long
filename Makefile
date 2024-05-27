# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 14:48:00 by acarpent          #+#    #+#              #
#    Updated: 2024/05/27 13:36:08 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(shell find ./src -name '*.c')

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(BONUS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3

RM			=	rm -f

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

PRINTF_PATH	=	./ft_printf/

PRINTF_FILE	=	libftprintf.a

MINILIBX	=	make -C ./minilibx-linux/

MLXFLAGS	=	-Lmlx_linux -L/usr/lib -lXext -lX11 -lm -lz

MLX_EX		=	./minilibx-linux/libmlx.a

MLX_PATH	=	./minilibx-linux/

NAME		=	so_long

all: $(NAME)

lib:	@make -C $(LIBFT_FILE)

printf:	@make -C $(PRINTF_PATH)

$(NAME): $(OBJS)
		$(MINILIBX)
		$(CC) $(CLFAGS) $(OBJS) $(MLX_EX) $(MLXFLAGS) $(LIBFT_PATH) $(LIBFT_FILE) $(PRINTF_PATH) $(PRINTF_FILE) -o $(NAME)

clean:
		$(RM) $(OBJS) 
		make clean -sC $(MLX_PATH)
		make clean -sC $(LIBFT_PATH)
		make clean -sC $(PRINTF_PATH)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
