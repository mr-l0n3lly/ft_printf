NAME		=	libftprintf.a
CFLAGS	=	-Wall -Werror -Wextra -std=c99 -c

SRC			=	ft_printf.c

LIBINC	=	libft.h
LIBFT_D	=	./libft/include
LIBFT		=	./libft
INC			=	ft_printf.h
INC_DIR	=	./include
SRC_DIR	=	./src
OBJ_DIR	=	./obj

OBJ			=	$(SRC:.c=.o)
OBJS		=	$(foreach element, $(OBJ), $(OBJ_DIR)/$(element))
SRCS		=	$(foreach element, $(SRC), $(SRC_DIR)/$(element))

all: $(NAME)

$(NAME): $(SRCS) $(INC_DIR)/$(INC)
	@cd $(LIBFT) && make re
	@mv $(LIBFT)/libft.a $(NAME)
	$(info [x] Compiling src files in .o files)
	@gcc $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_D) $(SRCS)
	$(info [x] Move .o files in obj dir)
	@mv *.o $(OBJ_DIR)
	$(info [x] Compiling library)
	@ar rs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)
	@make clean -C ./libft

fclean:	clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf ./libft.a
	@make fclean -C ./libft

re: fclean all

.PHONY: all, clean, fclean, re
