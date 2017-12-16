MODULES += base/io

BASE_IO_SRC_NAMES :=	ft_putchar.c \
						ft_putchar_fd.c \
						ft_putendl.c \
						ft_putendl_fd.c \
						ft_putnbr.c \
						ft_putnbr_fd.c \
						ft_putstr.c \
						ft_putstr_fd.c

BASE_IO_OBJ_NAMES = $(BASE_IO_SRC_NAMES:.c=.o)

SRCS += $(addprefix $(SRC_PATH)/base/io/,$(BASE_IO_SRC_NAMES))
OBJS += $(addprefix $(OBJ_PATH)/base/io/,$(BASE_IO_OBJ_NAMES))

$(OBJ_PATH)/base/io/%.o: $(SRC_PATH)/base/io/%.c
	$(compile_objs_cc)
