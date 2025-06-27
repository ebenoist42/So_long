# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 10:00:22 by ebenoist          #+#    #+#              #
#    Updated: 2025/06/27 11:07:21 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc -g

CFLAGS	= -Wall -Werror -Wextra -g -Ilibft/includes -Iincludes

SRC		=	srcs/so_long.c\
			srcs/error.c\
			srcs/maps.c\
	
OBJ		= $(SRC:.c=.o)

LIBFT_PATH	= ./libft
LIBFT_H		= $(LIBFT_PATH)/libft.h
LIBFT		= $(LIBFT_PATH)/libft.a
MLX_DIR		= ./minilibx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd
MLX_MAKE	= $(MAKE) -C $(MLX_DIR)

all : $(NAME) 

$(NAME): $(OBJ) $(LIBFT) $(LIBFT_H)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_PATH) clean
	
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re