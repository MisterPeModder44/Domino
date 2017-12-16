MODULES += gnl

GNL_SRC_NAMES :=	get_next_line.c \

GNL_OBJ_NAMES = $(GNL_SRC_NAMES:.c=.o)

SRCS += $(addprefix $(SRC_PATH)/gnl/,$(GNL_SRC_NAMES))
OBJS += $(addprefix $(OBJ_PATH)/gnl/,$(GNL_OBJ_NAMES))

$(OBJ_PATH)/gnl/%.o: $(SRC_PATH)/gnl/%.c
	$(compile_objs_cc)
