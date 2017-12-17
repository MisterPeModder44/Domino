NAME := domino

SRC_PATH := srcs
OBJ_PATH := bin
INC_PATH := includes

SRCS_NAMES =	main.c		\
				commands_1.c\
				commands_2.c\
				domino_1.c	\
				domino_2.c	\
				output_1.c	\
				output_2.c	\
				turn.c		\
				place.c		\
				tmp.c

OBJS_NAMES = $(SRCS_NAMES:.c=.o)

SRCS = $(addprefix $(SRC_PATH)/, $(SRCS_NAMES))
OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAMES))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I$(INC_PATH) -Ilibft/includes -I/usr/local/include
RM = rm -f

LIBFT = libft/libft.a
LIBS = -Llibft -lft

NORM_LOG = norm.log
NORM_FILES =

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@tput dl; tput cub 100; printf "\033[90mCreating object files: \033[32mdone!"
	@printf "\n\033[90mCompiling \033[0m$(NAME)\033[90m: \033[0m"
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIBS)
	@printf "\033[32mdone!\n"

$(LIBFT):
	@make -C libft VERBOSE=0

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@tput dl; tput cub 100; printf "\033[90mCreating object files: \033[0m$(notdir $@)"
	@-$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(NORM_LOG)
	@$(RM) $(OBJS)
	@make -C libft fclean > /dev/null
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf "\033[33mRemoved \033[93mobject files!\033[0m\n"

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean > /dev/null
	@printf "\033[33mRemoved \033[93m$(NAME) executable!\033[0m\n\n"

re: fclean all

norm:
	@printf "\033[90mChecking \033[0mThe Norm\033[90m...\033[0m\n"
	$(eval NORM_FILES = $(SRCS) $(shell find includes -type f -name "*.h"))
	@printf "Found \033[32m%s\033[0m files!\n" $(words $(NORM_FILES))
	@$(RM) $(NORM_LOG)
	@norminette $(NORM_FILES) >> $(NORM_LOG)
	@printf "Norm Errors: "
	@cat $(NORM_LOG) | grep Error | wc -l | bc
	@printf "See \033[4m$(NORM_LOG)\033[0m for details.\n"

.PHONY: all premsg clean fclean re norm
