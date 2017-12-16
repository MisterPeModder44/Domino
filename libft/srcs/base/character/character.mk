MODULES += base/character

BASE_CHR_SRC_NAMES :=	ft_isalnum.c \
						ft_isalpha.c \
						ft_isascii.c \
						ft_isdigit.c \
						ft_isprint.c \
						ft_isspace.c \
						ft_tolower.c \
						ft_toupper.c

BASE_CHR_OBJ_NAMES = $(BASE_CHR_SRC_NAMES:.c=.o)

SRCS += $(addprefix $(SRC_PATH)/base/character/,$(BASE_CHR_SRC_NAMES))
OBJS += $(addprefix $(OBJ_PATH)/base/character/,$(BASE_CHR_OBJ_NAMES))

$(OBJ_PATH)/base/character/%.o: $(SRC_PATH)/base/character/%.c
	$(compile_objs_cc)
