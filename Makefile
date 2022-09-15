NAME	= libftprintf.a
CFLAGS	= -Wall -Werror -Wextra -std=c99 -g

SRC		= ft_printf.c ft_utils.c ft_print_char.c ft_print_str.c \
			ft_print_number.c

LIBINC	= libft.h
LIBFT_I = ./libft/include
LIBFT_D	= ./libft/
LIBFT	= $(addprefix $(LIBFT_D), libft.a)
INC		= ft_printf.h
INC_DIR	= ./include/
SRC_DIR	= ./src/
OBJ_DIR	= ./obj/

OBJ		= $(SRC:.c=.o)
OBJS	= $(foreach element, $(OBJ), $(OBJ_DIR)$(element))
SRCS	= $(foreach element, $(SRC), $(SRC_DIR)$(element))

all: obj $(LIBFT) $(NAME)

obj:
	$(info [+] Creating $(OBJ_DIR) folder)
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(info [+] Compiling libft library)
	@make -C $(LIBFT_D)

$(OBJS): %.o: $(SRCS)
	$(info [+] Compiling src files in .o files)
	@gcc $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_I) -c $^
	@mv $(OBJ) $(OBJ_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(info [+] Moving libft to add printf to it)
	@mv $(LIBFT) $(NAME)

	$(info [+] Compiling ft_printf library)
	@ar rs $(NAME) $(OBJS)

	$(info [+] Ranlib over ft_printf library)
	@ranlib $(NAME)

clean:
	$(info [+] Removing objects file)
	@/bin/rm -f $(OBJS)

	$(info [+] Cleaning libft)
	@make clean -C $(LIBFT_D)

fclean:	clean
	$(info [+] Removing $(NAME))
	@/bin/rm -f $(NAME)

	$(info [+] Fclean libft)
	@make fclean -C $(LIBFT_D)

re: fclean all

main: main.c
	gcc -I$(INC_DIR) -I$(LIBFT_I) -c $<
	gcc $@.o -L . -lftprintf -o $@
	rm -f $@.o

.PHONY: all, clean, fclean, re, obj, main
