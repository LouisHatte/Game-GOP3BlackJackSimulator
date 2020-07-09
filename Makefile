CC		=	gcc
CFLAGS	=	-Iinclude -Iinclude/algo -g3 #-Wall -Werror -Wextra
REMOVE 	=	rm -f

EXEC_DIR	=	bin/

EXEC 	=	bj
SRC 	= 	$(wildcard src/*.c) $(wildcard src/global/*.c) $(wildcard src/algo/*.c) $(wildcard src/algo/global/*.c)
OBJ	=		$(SRC:.c=.o)


all: $(EXEC) clean

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC_DIR)$@ $^

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(REMOVE) $(OBJ)

fclean:
	$(REMOVE) $(EXEC_DIR)$(EXEC)

re: fclean all

.PHONY: all clean fclean re
