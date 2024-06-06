CC := cc
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ~/MLX42
MLX_FLAGS = ~/MLX42/build/libmlx42.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

MANDATORY := ../so_long
HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS_MANDATORY := so_long_utils.c utils_1.c ft_strcmp.c utils_2.c \
									player.c moves.c get_next_line.c get_next_line_utils.c \
									ft_split.c so_long.c ft_putstr_fd.c ft_itoa.c flood_fill.c directions.c \
									coins.c check.c check_walls.c check_map.c


OBJS_MANDATORY	:= ${SRCS_MANDATORY:.c=.o}

all: libmlx $(MANDATORY)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -Imlx $(HEADERS) -o $@ -c $< 
	@echo "$(COLOUR_GREEN)A mandatory file compiled successfully.$(COLOUR_END)"

$(MANDATORY): $(OBJS_MANDATORY)
	$(CC) $(OBJS_MANDATORY) $(MLX_FLAGS) $(LIBS) $(HEADERS) -o $(MANDATORY)
	@echo "$(COLOUR_GREEN) ======== So_long is ready ========$(COLOUR_END)"

clean:
	@rm -rf $(OBJS_MANDATORY)
	@rm -rf $(LIBMLX)/build
	@echo "$(COLOUR_RED)Cleaned up mandatory object files and MLX build directory.$(COLOUR_END)"

fclean: clean
	@rm -rf $(MANDATORY)
	@echo "$(COLOUR_RED)======== Cleaned up mandatory part ========$(COLOUR_END)"

re: clean all
	@echo "$(COLOUR_BLUE)Rebuild the mandatory part$(COLOUR_END)"

.PHONY: all libmlx clean fclean re