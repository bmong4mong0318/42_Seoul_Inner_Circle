# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dayun <dayun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 18:08:21 by dayun             #+#    #+#              #
#    Updated: 2023/02/01 18:43:08 by dayun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME 			= fractol
CC 				= cc
CFLAGS			= -Wall -Wextra -Werror
MFLAGS  		= -framework OpenGL -framework AppKit
SRC_DIR 		= src/
OBJ_DIR 		= obj/
INC 			= include/
MLX_DIR			= mlx/
DEL 			= rm -f

# Sources
SRC_FILES		= 	fractol \
					mandelbrot julia burning_ship \
					utils julia_arg
SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF			=	create_dir

# Rules
all : $(NAME)
bonus : all

# Pipe : order-only prerequisite
$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo "Compiling...... \t$<"

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L./mlx -lmlx $(MFLAGS)
	@echo "-----------------fractol compile finished-----------------"

clean :
	$(DEL) -r $(OBJ_DIR)
	@make clean -C $(MLX_DIR)
	@echo "fractol obj files has been deleted------------------------"

fclean : clean
	$(DEL) $(NAME)
	@echo "fractol exec file has been deleted------------------------" 

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus
