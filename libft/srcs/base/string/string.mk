MODULES += base/string

BASE_STR_SRC_NAMES :=	ft_atoi.c \
						ft_itoa.c \
						ft_strcat.c \
						ft_strchr.c \
						ft_strclr.c \
						ft_strcmp.c \
						ft_strcpy.c \
						ft_strdel.c \
						ft_strdup.c \
						ft_strequ.c \
						ft_striter.c \
						ft_striteri.c \
						ft_strjoin.c \
						ft_strlcat.c \
						ft_strlen.c \
						ft_strlowcase.c \
						ft_strmap.c \
						ft_strmapi.c \
						ft_strncat.c \
						ft_strncmp.c \
						ft_strncpy.c \
						ft_strnequ.c \
						ft_strnew.c \
						ft_strnstr.c \
						ft_strrchr.c \
						ft_strsplit.c \
						ft_strstr.c \
						ft_strsub.c \
						ft_strtabdel.c \
						ft_strtrim.c \
						ft_strupcase.c

BASE_STR_OBJ_NAMES = $(BASE_STR_SRC_NAMES:.c=.o)

SRCS += $(addprefix $(SRC_PATH)/base/string/,$(BASE_STR_SRC_NAMES))
OBJS += $(addprefix $(OBJ_PATH)/base/string/,$(BASE_STR_OBJ_NAMES))

$(OBJ_PATH)/base/string/%.o: $(SRC_PATH)/base/string/%.c
	$(compile_objs_cc)
