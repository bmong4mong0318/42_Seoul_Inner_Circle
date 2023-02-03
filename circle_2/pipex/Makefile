# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dayun <dayun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 15:03:48 by dayun             #+#    #+#              #
#    Updated: 2023/02/03 16:37:47 by dayun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME 			= pipex
CC 				= cc
CFLAGS			= -Wall -Wextra -Werror
DEL 			= rm -f

INC 			= mandatory/include
SRC_DIR 		= mandatory/src/
OBJ_DIR 		= mandatory/obj/

INC_BONUS		= bonus/include
SRC_BONUS_DIR 	= bonus/src/
OBJ_BONUS_DIR 	= bonus/obj/

LIBFT 			= libft

# Sources
SRC_FILES		= 	pipex parse fd utils \
					get_next_line get_next_line_utils
SRC_BONUS_FILES =	pipex_bonus parse_bonus fd_bonus utils_bonus \
					get_next_line_bonus get_next_line_utils_bonus
SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC_BONUS 		= 	$(addprefix $(SRC_BONUS_DIR), $(addsuffix .c, $(SRC_BONUS_FILES)))
OBJ_BONUS		= 	$(addprefix $(OBJ_BONUS_DIR), $(addsuffix .o, $(SRC_BONUS_FILES)))
OBJF			=	create_dir

ifdef	BONUS_OPT
	OBJ_TOTAL = $(OBJ_BONUS)
	O_DIR = $(OBJ_BONUS_DIR)
	S_DIR = $(SRC_BONUS_DIR)
	INC_FINAL = $(INC_BONUS)
else
	OBJ_TOTAL = $(OBJ)
	O_DIR = $(OBJ_DIR)
	S_DIR = $(SRC_DIR)
	INC_FINAL = $(INC)
endif

# Rules
all : $(NAME)
bonus : 
	@make BONUS_OPT=1 $(BONUS)

# Pipe : order-only prerequisite
$(O_DIR)%.o : $(S_DIR)%.c | $(OBJF) 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_FINAL) $(GNL)
	@echo "Compiling...... \t$<"

$(OBJF)	:
	@mkdir -p $(O_DIR)

$(NAME) : $(OBJ_TOTAL)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) ./libft/libft.a -o $@ $^ 
	@echo "-----------------pipex compile finished-----------------"

clean :
	$(DEL) -r $(O_DIR) $(OBJ_BONUS_DIR)
	@make clean -C $(LIBFT)
	@echo "pipex obj files has been deleted------------------------"

fclean : clean
	$(DEL) $(NAME)
	$(DEL) $(BONUS)
	$(DEL) $(LIBFT)/libft.a
	@echo "pipex exec file has been deleted------------------------" 

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus
