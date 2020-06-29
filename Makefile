CC		=	gcc
CFLAGS	=	-Iinclude -g3 #-Wall -Werror -Wextra
REMOVE 	=	rm -f

EXEC_DIR	=	bin/

EXEC 	=	bj
SRC 	= 	$(wildcard src/*.c)
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
