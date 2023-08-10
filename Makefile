#jot -r 11 1 50 | tr '\n' ' ' | awk '!a[$0]++'   -> Crea 11 numeros random entre 1 y 50 sin repetir
#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME = push_swap

#NAME_BONUS = checker_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

PUSH_SWAP = push_swap.a

#PUSH_SWAP_BONUS = push_swap_bonus.a

LIB = ar rcs

SRCS = src/push_swap.c src/check_arg_int.c src/push_swap_utils.c src/push_swap_moves.c\
	src/push_swap_moves_1.c src/push_swap_moves_2.c src/algorithm.c src/algorithm_utils.c

OBJS = $(SRCS:.c=.o)

#SRCS_BONUS = srcb/so_long_bonus.c srcb/map_check_bonus.c srcb/map_bonus.c srcb/set_images_bonus.c srcb/player_movement_bonus.c srcb/monster_movement_bonus.c

#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) :	$(OBJS) $(LIBFT)
			@echo "$(MAGENTA)$(BOLD)Compiling push_swap...$(RESET)"
			@$(LIB) $(PUSH_SWAP) $(OBJS)
			@$(CC) $(CFLAGS) $(PUSH_SWAP) $(LIBFT) -o $(NAME)
			@echo "$(CYAN)$(BOLD)Done$(RESET)"

$(OBJS):	src/%.o : src/%.c 
			@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
			@make -s -C $(LIBFT_PATH)
			@make bonus -s -C $(LIBFT_PATH)

#$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(MLX)
#			@echo "$(YELLOW)$(BOLD)Compiling so_long_bonus...$(RESET)"
#			@$(LIB) $(SO_LONG_BONUS) $(OBJS_BONUS)
#			@$(CC) $(CFLAGS) $(SO_LONG_BONUS) $(MLX) $(LIBFT) $(LIB_SYS) -o $(NAME_BONUS)
#			@echo "$(CYAN)$(BOLD)Done$(RESET)"

#$(OBJS_BONUS):	srcb/%.o : srcb/%.c 
#			@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

#bonus : $(NAME_BONUS)

clean:
			@echo "$(RED)$(BOLD)Cleaning objects from push_swap...$(RESET)"
			@rm -f $(OBJS)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make clean -s -C $(LIBFT_PATH)

fclean:
			@echo "$(RED)$(BOLD)Cleaning all files from push_swap...$(RESET)"
			@rm -f $(NAME) $(OBJS) $(LIBFT) $(PUSH_SWAP)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make fclean -s -C $(LIBFT_PATH)

re : fclean all

ps : all clean

.PHONY : all re fclean clean bonus ps