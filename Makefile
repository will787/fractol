NAME := Game
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX := ./libs/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS := $(shell find ./src -iname "*.c")
OBJ_DIR := ./obj
OBJS := $(patsubst ./src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
