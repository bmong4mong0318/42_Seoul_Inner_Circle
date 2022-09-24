# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dayun <dayun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 15:28:39 by dayun             #+#    #+#              #
#    Updated: 2022/09/24 09:21:21 by dayun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME 			= libftprintf.a
CC 				= cc
CFLAGS			= -Wall -Wextra -Werror
SRC_DIR 		= printf_mandatory/src/
OBJ_DIR 		= printf_mandatory/obj/
SRC_BONUS_DIR 	= printf_bonus/src/
OBJ_BONUS_DIR 	= printf_bonus/obj/
LIBFT 			= libft
INC 			= include
DEL 			= rm -f
ARC 			= ar rcus

#Sources
SRC_FILES		=	ft_printf_main \
					ft_printf_format1 ft_printf_format2 ft_printf_format3\
					ft_printf_print ft_printf_hex ft_printf_utils ft_printf_utils2
SRC_BONUS_FILES	=	ft_printf_main_bonus \
					ft_printf_format1_bonus ft_printf_format2_bonus ft_printf_format3_bonus\
					ft_printf_print_bonus ft_printf_hex_bonus ft_printf_utils1_bonus ft_printf_utils2_bonus
SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC_BONUS 		= 	$(addprefix $(SRC_BONUS_DIR), $(addsuffix .c, $(SRC_BONUS_FILES)))
OBJ_BONUS		= 	$(addprefix $(OBJ_BONUS_DIR), $(addsuffix .o, $(SRC_BONUS_FILES)))
OBJF			=	create_dir

ifdef	BONUS_OPT
	OBJ_TOTAL = $(OBJ_BONUS)
	O_DIR = $(OBJ_BONUS_DIR)
	S_DIR = $(SRC_BONUS_DIR)
else
	OBJ_TOTAL = $(OBJ)
	O_DIR = $(OBJ_DIR)
	S_DIR = $(SRC_DIR)
endif

#Rules
all : $(NAME)
bonus : 
	@make BONUS_OPT=1 $(NAME)

#Pipe : order-only prerequisite
$(O_DIR)%.o : $(S_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)
	@echo "Compiling...... \t$<"

$(OBJF)	:
	@mkdir -p $(O_DIR)

$(NAME) : $(OBJ_TOTAL)
	@rm -f $(NAME)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	$(ARC) $@ $(OBJ_TOTAL)
	@echo "-----------------ft_printf compile finished-----------------"

clean :
	$(DEL) -r $(O_DIR) $(OBJ_BONUS_DIR)
	@make clean -C $(LIBFT)
	@echo "ft_printf obj files has been deleted------------------------"

fclean : clean
	$(DEL) $(NAME)
	$(DEL) $(LIBFT)/libft.a
	@echo "ft_printf archive files has been deleted" 

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus
