NAME = cub3d

CUB = \
	srcs/cub/draw_and_search_dz.c\
	srcs/cub/free.c\
	srcs/cub/init_struct.c\
	srcs/cub/keyhook.c\
	srcs/cub/move.c\
	srcs/cub/open_txt.c\
	srcs/cub/pognali_epta.c\
	srcs/cub/rotate.c\

GNL = \
	srcs/gnl/get_next_line_utils.c\
	srcs/gnl/get_next_line.c\

PARS =  \
	srcs/parser/check_map.c\
	srcs/parser/parse_params.c\
	srcs/parser/parse_rgb.c\

UTILS = \
	srcs/utils/utils.c\
	srcs/utils/free.c\
	srcs/utils/str_arr_utils.c\
	srcs/utils/str_arr_utils2.c\
	srcs/utils/pixel.c\

SRC =	${GNL} ${PARS} ${UTILS} ${CUB}\
		srcs/main.c\

PATH_LIB = srcs/libft/

NAME_LIB = libft.a

LIB = srcs/libft/libft.a

HDRS = srcs/cub.h

OBJ = $(SRC:c=o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
	@echo "\n"
	@make -C mlx 2>/dev/null
	@make -C $(PATH_LIB)
	@echo "\033[0;32mCompiling cub3d...✅"
	@$(CC) $(FLAGS) $(MLX_FLAGS) -I mlx $(OBJ) $(LIB) -I. -o $(NAME)
	@echo "\n\033[0;33m🥂Done and ready!🥂"

%.o: %.c
	@printf "\033[0;33mGenerating cub3d objects 🔜 %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C $(PATH_LIB)
	@echo "\033[0;31mCleaning mlx..."
	@make clean -C mlx
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\n\033[0;32mCleaning process is competed!"

fclean: clean
	@echo "\033[0;31m🧹Cleaning libft🧹..."
	@make fclean -C $(PATH_LIB)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\n\033[0;32mF_cleaning process is competed!"

re:		fclean all

reclean: re
	$(RM) $(OBJ)
	make clean -C $(PATH_LIB)

.PHONY: all clean fclean