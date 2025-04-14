NAME = cub3D
#~~~~~~ Directories ~~~~~~
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIB_DIR = ./libft/
#~~~~ Src Directories ~~~~
PARS_DIR = parse/
ERROR_DIR = error/
#~~~~~~ Src Files ~~~~~~~
SRCS = main.c\
	$(PARS_DIR)check_holes.c\
	$(PARS_DIR)init_parse.c\
	$(PARS_DIR)parse_map.c\
	$(ERROR_DIR)error.c
#~~~~~~ Obj Files ~~~~~~~
OBJ_FILES = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
#~~~~~~ Includes ~~~~~~~~
INCLUDES = $(INC_DIR)cub3d.h\
#~~~~~~ Compiling ~~~~~~~
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -O0 -fsanitize=address,leak #-Wunreachable-code -Ofast 
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
MLXLIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: libmlx obj ${NAME}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

obj:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(NAME)

clean:
	@${RM} -rf $(OBJ_DIR)
	@cd libft && $(MAKE) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@cd libft && $(MAKE) fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
