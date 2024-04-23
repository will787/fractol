NAME := fractol
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX := ./libs/MLX42
LIBFT  := ./libs/libft
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS := $(shell find ./src -iname "*.c")
OBJ_DIR := ./obj
OBJS := $(patsubst ./src/%.c,$(OBJ_DIR)/%.o,$(SRCS))
LIBFT_OBJS := $(wildcard $(LIBFT)/*.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS) $(LIBFT_OBJS)
	@$(CC) $(OBJS) $(LIBFT_OBJS) $(LIBS) -L$(LIBFT) -o -lft $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
