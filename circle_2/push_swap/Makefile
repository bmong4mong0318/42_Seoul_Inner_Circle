# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dayun <dayun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 09:34:54 by dayun             #+#    #+#              #
#    Updated: 2023/01/02 15:07:08 by dayun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME 			= push_swap
BONUS			= checker
CC 				= cc
CFLAGS			= -Wall -Wextra -Werror
SRC_DIR 		= mandatory/src/
OBJ_DIR 		= mandatory/obj/
SRC_BONUS_DIR 	= bonus/src/
OBJ_BONUS_DIR 	= bonus/obj/
INC 			= mandatory/include
INC_BONUS		= bonus/include
DEL 			= rm -f
ARC 			= ar rcus

# Sources
SRC_FILES		= 	push_swap \
					doubly_linked_list stack_utils validate_param \
					operator1 operator2 operator3 \
					sort sort_sandglass \
					ft_split utils
SRC_BONUS_FILES  =	checker \
					doubly_linked_list stack_utils validate_param \
					operator1 operator2 operator3 \
					check_op \
					ft_split utils \
					get_next_line get_next_line_utils
SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC_BONUS 		= 	$(addprefix $(SRC_BONUS_DIR), $(addsuffix .c, $(SRC_BONUS_FILES)))
OBJ_BONUS		= 	$(addprefix $(OBJ_BONUS_DIR), $(addsuffix .o, $(SRC_BONUS_FILES)))
OBJF			=	create_dir

ifdef	BONUS_OPT
	O_DIR = $(OBJ_BONUS_DIR)
	S_DIR = $(SRC_BONUS_DIR)
	INC_FINAL = $(INC_BONUS)
else
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
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_FINAL)
	@echo "Compiling...... \t$<"

$(OBJF)	:
	@mkdir -p $(O_DIR)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $@ -I $(INC_FINAL)
	@echo "-----------------push_swap compile finished-----------------"

$(BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $@ -I $(INC_FINAL)
	@echo "-----------------checker compile finished-----------------"

clean :
	$(DEL) -r $(O_DIR) $(OBJ_BONUS_DIR)
	@echo "push_swap obj files has been deleted------------------------"

fclean : clean
	$(DEL) $(NAME)
	$(DEL) $(BONUS)
	@echo "push_swap exec file has been deleted------------------------" 

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus


