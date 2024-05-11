NAME := fractol
CFLAGS := -Wextra -Wall -Werror -g3
LIBMLX := ./libs/MLX42
LIBFT  := ./libs/libft
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS := $(shell find ./src -name "*.c")
OBJ_DIR := ./obj
OBJS := $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

all: libmlx libft $(NAME)

libmlx: $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build >/dev/null 2>&1 && make -C $(LIBMLX)/build -j4 >/dev/null 2>&1

libft: $(LIBFT)/libft.a

$(LIBFT)/libft.a:
	@make -C $(LIBFT)


$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: %s\n" $<

$(NAME): $(OBJS)
	@$(CC) $^ -o $@ $(LIBS) -L$(LIBFT) -lft

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(LIBFT)/libft.a
	@$(RM) -rf $(LIBFT)/obj
fclean: clean
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx libft
