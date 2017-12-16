MODULES += base/list

BASE_LST_SRC_NAMES :=	ft_array_to_lst.c \
						ft_lst_to_array.c \
						ft_lstdel.c \
						ft_lstiter.c \
						ft_lstmap.c \
						ft_lst_pushback.c \
						ft_lstadd.c \
						ft_lstdelone.c \
						ft_lstlen.c \
						ft_lstnew.c

BASE_LST_OBJ_NAMES = $(BASE_LST_SRC_NAMES:.c=.o)

SRCS += $(addprefix $(SRC_PATH)/base/list/,$(BASE_LST_SRC_NAMES))
OBJS += $(addprefix $(OBJ_PATH)/base/list/,$(BASE_LST_OBJ_NAMES))

$(OBJ_PATH)/base/list/%.o: $(SRC_PATH)/base/list/%.c
	$(compile_objs_cc)
