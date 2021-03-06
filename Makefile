NAME = lem-in
INCLUDES=./includes
INCLUDES_FT_PRINTF=./ft_printf/includes
COMPILER = gcc
LIB=./ft_printf/
SRCS=main.c app.c mtrx.c identity.c find_link.c compare.c path.c path2.c \
	print_data.c operation.c parsing.c get_next_line.c block.c verif.c \
	calc_f_num.c choose_paths.c parsing2.c parsing3.c ant.c end_path.c \
	other.c put_error.c util.c
SRC_PATH=./srcs/
OBJ=$(SRCS:.c=.o)
FLAG=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIB)libftprintf.a $(OBJ) $(INCLUDES)/get_next_line.h $(INCLUDES_FT_PRINTF)/ft_printf.h \
	$(INCLUDES)/lem_in.h
	$(COMPILER) -o $(NAME) -I$(INCLUDES_FT_PRINTF) -I$(INCLUDES) $(OBJ) -L$(LIB) -lftprintf

%.o: $(SRC_PATH)%.c $(INCLUDES)/lem_in.h
	$(COMPILER) -c $(FLAG) $< -I$(INCLUDES_FT_PRINTF) -I$(INCLUDES)

$(LIB)libftprintf.a:
	make -C $(LIB)
	make clean -C $(LIB)

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean $(NAME)
