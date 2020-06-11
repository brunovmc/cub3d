# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 23:52:54 by vminomiy          #+#    #+#              #
#    Updated: 2020/06/11 15:46:56 by vminomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a

INCLUDES = -I $(MLX_PATH) -I $(LIBFT_PATH)

#FRAMEWORK_MAC = -framework OpenGL -framework AppKit
FRAMEWORK_LINUX = -lXext -lX11 -lbsd -lm 

MLX = -L $(MLX_PATH) -lmlx
MLX_PATH = ./minilibx

LIBFT = -L $(LIBFT_PATH) -lft
LIBFT_PATH = ./libft

FLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS = main.c \
		checkup.c \
		init.c \
		file_management.c \
		mem_destroy.c \

OBJ = $(patsubst %.c, %.o, $(SRCS))

$(NAME) : $(OBJ)
	#Cube3D Compile
	@clang -g $(FLAGS) $(FRAMEWORK_LINUX) $(OBJ) $(INCLUDES) $(MLX) $(LIBFT) -o $(NAME)

all : $(NAME)

clean :
	rm -f ./srcs/$(OBJ) 

fclean : clean
	rm -f $(NAME)
	
re : fclean all
