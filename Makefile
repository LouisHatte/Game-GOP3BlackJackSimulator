CC		=	gcc
CFLAGS	=	-Iinclude -Iinclude/algo -g3 #-Wall -Werror -Wextra
LDFLAGS =	-lgraph
REMOVE 	=	rm -f

EXEC_DIR	=	bin/

EXEC 	=	bj
SRC 	= 	$(wildcard src/*.c) $(wildcard src/global/*.c) $(wildcard src/algo/*.c)
OBJ	=		$(SRC:.c=.o)


all: $(EXEC) clean

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC_DIR)$@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(REMOVE) $(OBJ)

fclean:
	$(REMOVE) $(EXEC_DIR)$(EXEC)

re: fclean all

.PHONY: all clean fclean re
