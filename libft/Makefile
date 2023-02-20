CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ../include


NAME = libft.a

SRC =	ft_bzero.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strncpy.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strmapi.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		
SRC_BONUS =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(OBJ) $(SRC_BONUS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

$(NAME): $(OBJ) $(HDRS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Libft.\033[0m"

so:
	$(CC) -nostartfiles -shared -o libft.so $(OBJ)

bonus: $(OBJ_BONUS) $(HDRS)
	@ar r $(NAME) $(OBJ_BONUS)
	@ranlib $(NAME)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Libft with Bonus.\033[0m"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.so
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Libft.a deleted.\033[0m"

re: fclean all

.PHONY: clean fclean re