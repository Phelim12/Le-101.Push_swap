# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/08 18:11:02 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2017/12/08 18:11:02 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

NAME = checker

NAME_CHK = checker

NAME_PSW = push_swap

C_FLAGS =  

DIR_INC = Includes/

DIR_LIB = Libft/

DIR_CHK = Checker_src/

DIR_PSW = Push_swap_src/

CHK_SRC = checking_checker.c fill_checker.c main_checker.c tools_checker.c \
		  operation1_checker.c operation2_checker.c 

PSW_SRC = 	fill_pushswap.c groups_algo.c main_pushswap.c \
			operation1_pushswap.c operation2_pushswap.c tools_pushswap.c

SRC_CHK = $(addprefix $(DIR_CHK), $(CHK_SRC))

SRC_PSW = $(addprefix $(DIR_PSW), $(PSW_SRC))

SRC = $(addprefix $(DIR_CHK), $(CHK_SRC)) $(addprefix $(DIR_PSW), $(PSW_SRC))

OBJ_CHK = $(SRC_CHK:.c=.o)

OBJ_PSW = $(SRC_PSW:.c=.o) 

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(DIR_LIB)
	@$(CC) $(C_FLAGS) $(OBJ_PSW) -L $(DIR_LIB) -lft -o $(NAME_PSW) 
	@$(CC) $(C_FLAGS) $(OBJ_CHK) -L $(DIR_LIB) -lft -o $(NAME_CHK)	
	@echo "\033[0;32m✅️   make checker.\033[0m"

./%.o: ./%.c
	@$(CC) $(C_FLAGS) -I $(DIR_INC) -o $@ -c $< 
	@echo "\033[0;32m✅️   $@ created.\033[0m"

clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ)
	@echo "\033[38;5;202m🗑️   clean checker.\033[0m" 

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME_CHK)
	@rm -f $(NAME_PSW)
	@echo "\033[38;5;196m🗑️   fclean checker.\033[0m" 

re: fclean all
	