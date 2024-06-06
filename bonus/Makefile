CC := cc
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ~/MLX42
MLX_FLAGS = ~/MLX42/build/libmlx42.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

BONUS := ../so_long_bonus
HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS_BONUS := check_bonus.c check_map_bonus.c check_walls_bonus.c \
			so_long_bonus.c so_long_utils_bonus.c moves_bonus.c ft_putstr_fd_bonus.c \
			flood_fill_bonus.c enemy_bonus.c player_bonus.c animations_bonus.c directions_bonus.c \
			animations_bonus_2.c animations_bonus_3.c put_asset_bonus.c ft_split_bonus.c \
 			ft_strcmp_bonus.c ft_itoa_bonus.c utils_1_bonus.c utils_2_bonus.c utils_3_bonus.c \
			get_next_line_bonus.c get_next_line_utils_bonus.c keys_clicked_bonus.c \

OBJS_BONUS	:= ${SRCS_BONUS:.c=.o}

bonus: libmlx $(BONUS)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c so_long_bonus.h
	@$(CC) $(CFLAGS) -Imlx $(HEADERS) -o $@ -c $<
	@echo "$(COLOUR_GREEN) A bonus file compiled successfully$(COLOUR_END)"

$(BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(MLX_FLAGS) $(LIBS) $(HEADERS) -o $(BONUS)
	@echo "$(COLOUR_GREEN)======== So_long_bonus is ready ========$(COLOUR_END)"

clean:
	@rm -rf $(OBJS_BONUS)
	@rm -rf $(LIBMLX)/build
	@echo "$(COLOUR_RED)Cleaned up bonus object files and MLX build directory.$(COLOUR_END)"

fclean: clean
	@rm -rf $(BONUS)
	@echo "$(COLOUR_RED)======== Cleaned up bonus part ========$(COLOUR_END)"

re: clean bonus
	@echo "$(COLOUR_BLUE)Rebuild the bonus part$(COLOUR_END)"

.PHONY: bonus libmlx clean fclean re