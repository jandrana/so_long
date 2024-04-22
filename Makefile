# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 12:13:57 by ana-cast          #+#    #+#              #
#    Updated: 2024/04/22 21:53:09 by ana-cast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = so_long
LIBFT = lib/libft/
LIBMLX = lib/MLX42
SO_LONG = include/
CC_FLAGS = gcc -Wall -Wextra -Werror
RM = rm -rf
INCLUDE = -L ./lib/libft -lft

DEPS = -I include -I $(LIBFT)/include -I $(LIBMLX)/include
LIBGL = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
LIBS =  $(LIBGL) $(LIBMLX)/build/libmlx42.a

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRCS = src/main.c src/utils/utils.c src/parse/valid_map.c src/parse/valid_path.c \
	src/game/call_mlx.c src/game/fill_map.c src/game/load_char.c \
	src/game/load_images.c src/game/load_objects.c src/game/move_player.c \
	src/game/redraw_map.c src/game/sprites.c 

OBJECTS = $(SRCS:.c=.o)

################################################################################
##                                    COLOURS                                 ##
################################################################################

WHITE=\033[0m
BOLD=\033[1m
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[33m
MAGENTA=\033[35m
TURQUOISE=\033[36m

################################################################################
##                                     RULES                                  ##
################################################################################

all : head libmlx libft $(NAME)

head : 
	@echo "$(MAGENTA)"
	@echo "\t              _                   "
	@echo "\t             | |                  "
	@echo "\t  ___  ___   | | ___  _ __   __ _ "
	@echo "\t / __|/ _ \  | |/ _ \| '_ \ / _\` |"
	@echo "\t \__ \ (_) | | | (_) | | | | (_| |"
	@echo "\t |___/\___/  |_|\___/|_| |_|\__, |"
	@echo "\t        ______              __/ |"
	@echo "\t       |______|            |___/ "
	@echo ""
	@echo "\t        42MLG: by ana-cast"
	@echo "\tProyect: \033[36m so_long $(MAGENTA)"
	@echo "\tCommands:\033[36m all clean fclean re $(WHITE)\n"

libft :
	@make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "$(TURQUOISE)"
	@echo "✦ --------------- ✦"
	@echo "|  Created MLX42  |"
	@echo "✦ --------------- ✦$(WHITE)"

$(NAME) : line $(OBJECTS)
	@echo "✦ ---------------------- ✦$(WHITE)"
	@$(CC_FLAGS) $(OBJECTS) $(LIBS) $(INCLUDE) -o $(NAME)
	@echo "$(TURQUOISE)"
	@echo "✦ ----------------- ✦"
	@echo "|  Created $(basename $(NAME))  |"
	@echo "✦ ----------------- ✦$(WHITE)\n"

%.o : %.c $(SO_LONG)
	@$(CC_FLAGS) -c $< -o $@ $(DEPS)
	@echo "  ✓ Compiled: $(notdir $<)"

line :
	@echo "$(GREEN) $(BOLD)"
	@echo "    COMPILING SO_LONG...$(WHITE) $(GREEN)"
	@echo "✦ ---------------------- ✦"

clean :
	@$(RM) $(OBJECTS)
	@$(RM) $(LIBMLX)/build
	@make clean -C $(LIBFT)
	@echo "\n$(GREEN) ✓  $(RED)Removed  objects $(WHITE)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(GREEN) ✓  $(RED)Removed  $(NAME) and libft $(WHITE)\n"

re :
	@$(MAKE) fclean
	@clear
	@$(MAKE) all

.PHONY: all clean fclean re