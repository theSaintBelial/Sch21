NAME = libeq.a

OBJ = eightqueens.o

SRC = eightqueens.c

HDR = e_q.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC) $(HDR)
	gcc -c $<

clean:
	rm *.o *.a

re: clean all