# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dayun <dayun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 15:28:39 by dayun             #+#    #+#              #
#    Updated: 2022/09/02 14:38:29 by dayun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME 		= libftprintf.a
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
SRC_DIR 	= src/
OBJ_DIR 	= obj/
LIBFT 		= libft
INC 		= include
DEL 		= rm -f
ARC 		= ar rcus

#Sources
SRC_FILES	=	ft_printf_main \
				ft_printf_print ft_printf_put \
				ft_printf_ptr ft_printf_utils \
				ft_printf_format1 ft_printf_format2
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF		=	create_dir

#Rules
all : $(NAME)
bonus : $(NAME)

#Pipe : order-only prerequisite
$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAG) -c $< -o $@ -I $(INC)
	@echo "Compiling...... \t$<"

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	$(ARC) $@ $(OBJ)
	@echo "-----------------ft_printf compile finished-----------------"

clean :
	$(DEL) -r $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "ft_printf obj files has been deleted------------------------"

fclean : clean  
	$(DEL) $(NAME)
	$(DEL) $(LIBFT)/libft.a
	@echo "ft_printf archive files has been deleted" 

re : 
	make fclean
	make all

.PHONY : all clean fclean re 
