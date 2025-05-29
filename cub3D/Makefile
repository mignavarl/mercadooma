NAME = cub3D
#~~~~~~ Directories ~~~~~~
INC_DIR = ./includes/
LIB_DIR = ./libft/
OBJ_DIR = ./obj/
SRC_DIR = ./src/
#~~~~ Src Directories ~~~~
ERROR_DIR = error/
GAME_DIR = game/
PARS_DIR = parse/
REND_DIR = render/
#~~~~~~ Src Files ~~~~~~~
SRCS = main.c\
	$(ERROR_DIR)error.c\
	$(GAME_DIR)init_game.c\
	$(GAME_DIR)images.c\
	$(GAME_DIR)textures.c\
	$(GAME_DIR)player_dir.c\
	$(GAME_DIR)player_rotate.c\
	$(GAME_DIR)player_move.c\
	$(PARS_DIR)check_holes.c\
	$(PARS_DIR)extract_colors.c\
	$(PARS_DIR)extract_rgba.c\
	$(PARS_DIR)extract_textures.c\
	$(PARS_DIR)find_rgb.c\
	$(PARS_DIR)init_parse.c\
	$(PARS_DIR)parse_map.c\
	$(REND_DIR)render.c\
	$(REND_DIR)raycast.c
#~~~~~~ Obj Files ~~~~~~~
OBJ_FILES = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
#~~~~~~ Includes ~~~~~~~~
INCLUDES =	$(INC_DIR)cub3d.h

#~~~~~~ Compiling ~~~~~~~
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=leak #-Wunreachable-code -Ofast 
MAKEFLAGS = --no-print-directory
LFLAGS = -L libft -lft
RM = rm -f
#~~~~~~~ Dir Obj ~~~~~~~~
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIB_DIR) -c $< -o $@
#~~~~~~~ MLX42 ~~~~~~~~
LIBMLX	= ./MLX42
HEADERS	= -I ./include -I $(LIBMLX)/include
MLXLIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: libmlx obj ${NAME}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

obj:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) $(OBJS) $(CFLAGS) $(MLXLIBS) $(LFLAGS) -o $(NAME)

clean:
	@${RM} -rf $(OBJ_DIR)
	@cd libft && $(MAKE) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@cd libft && $(MAKE) fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libmlx
