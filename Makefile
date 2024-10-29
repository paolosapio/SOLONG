MAKEFLAGS	= --no-print-directory --silent

NAME	 = so_long

CC = cc

CFLAGS	 =	-Wextra -Wall -Werror -Wunreachable-code
CFLAGS	 += -I includes
CFLAGS	 += -I libft
CFLAGS	 += -I GNL
CFLAGS	 += -O3

DEBUG	 =	-g3 -fsanitize=address

CPPFLAGS =	-MMD

LIBMLX	= ./libs/MLX42
LIBFT	= ./libs/libft

HEADERS = -I ./includes -I $(LIBMLX)/include -I $(LIBFT)

LIBS	=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBS	+=	$(LIBFT)/libft.a


SRCS =						\
		srcs/main.c			\
		srcs/animation_next_texture.c \
		srcs/animations_player.c \
		srcs/animation_update.c \
		srcs/check_map.c \
		srcs/check_res.c \
		srcs/collisions.c \
		srcs/destroy_all.c \
		srcs/destroy_animation.c \
		srcs/destroy_map.c \
		srcs/destroy_player.c \
		srcs/if_colectable.c \
		srcs/init_animation.c \
		srcs/init_map.c \
		srcs/init_player.c \
		srcs/keys.c \
		srcs/movements.c \
		srcs/paint_map.c \
		srcs/parser_map.c \
		srcs/paths_breath.c \
		srcs/print_error.c \
		srcs/query_map_coordinate.c \
		srcs/speed_movements.c \
		srcs/update_game.c \
		srcs/update_player.c \



OBJS = $(patsubst srcs/%.c, objs/srcs/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: libmlx libft $(NAME)

libmlx:
	@cmake -DDEBUG=0 $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(DEBUG) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) && printf "Linking: $(NAME)\n"

objs/srcs/%.o: ./srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf objs
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libmlx libft
