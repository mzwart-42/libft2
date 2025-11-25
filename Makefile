#NOTE: UPDATE FLAGS LATER
# DEP_FLAGS = -MMD -MP
CFLAGS += -Wall -Wextra  -Werror
CC = cc
INCLUDE_DIRS = ./include

# [c] do not warn about creation of file
# [r] eplace existing or insert new file(s) into the archive
# [U] set time stamps needed for replacement using make's archive(member) function
ARFLAGS = rcU
NAME := libft.a
BUILD_DIR := ./build

SRC := \
ft_atoi.c    \
ft_strlen.c  \
ft_strchr.c  \
ft_strrchr.c \
ft_strncmp.c \
ft_strlcpy.c \
ft_strnstr.c \
ft_ctype.c   \
ft_bzero.c   \
ft_mem.c     \
ft_calloc.c  \
ft_strdup.c  \
ft_split.c   \
ft_substr.c  \
ft_strmapi.c \
ft_put.c     \

#------------------------------------------------------------#
INCLUDE_FLAGS = $(addprefix -I, $(INCLUDE_DIRS))
OBJECT := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))
# DEPS := $(OBJECT:.o=.d)

all: $(BUILD_DIR) $(OBJECT) $(NAME)($(OBJECT))

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(NAME):
	$(AR) $(ARFLAGS) $(NAME)

$(BUILD_DIR)/%.o : %.c
	$(CC) $(DEP_FLAGS) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# NOTE: assumes 'CFLAGS' is the variable name for setting compile flags
test: fclean check-comparison-libft
	$(MAKE) CFLAGS="$(CFLAGS) -g"
	cd $(libft2) && $(MAKE) re CFLAGS="$(CFLAGS) -g"

check-comparison-libft:
ifndef	libft2
	$(error LIBFT_2 is not set/exported)
endif

.PHONY: all clean fclean re test check-comparison-libft

# include $(DEPS)
