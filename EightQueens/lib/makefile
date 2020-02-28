NAME = libeq.a

OBJ = eightqueens.o

SRC = eightqueens.c

HDR = e_q.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC) $(HDR)
	gcc -c $<

exec:
	gcc -o eightqueens.out $(SRC)

clean:
	rm *.o *.a

clean_exec:
	rm *.out

fclean: clean clean_exec

re: clean all