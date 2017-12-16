MODULES += base/memory

BASE_MEM_SRC_NAMES :=	ft_bzero.c \
						ft_memalloc.c \
						ft_memccpy.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memcpy.c \
						ft_memdel.c \
						ft_memmove.c \
						ft_memset.c

BASE_MEM_OBJ_NAMES = $(BASE_MEM_SRC_NAMES:.c=.o)

SRCS += $(addprefix $(SRC_PATH)/base/memory/,$(BASE_MEM_SRC_NAMES))
OBJS += $(addprefix $(OBJ_PATH)/base/memory/,$(BASE_MEM_OBJ_NAMES))

$(OBJ_PATH)/base/memory/%.o: $(SRC_PATH)/base/memory/%.c
	$(compile_objs_cc)
