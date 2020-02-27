LIB_DIR = lib

NAME = eightqueens

all: $(NAME)

$(NAME): setup.py eightqueens.pyx $(LIB_DIR)/libeq.a
	python3 setup.py build_ext --inplace && rm -f eightqueens.c && rm -Rf build

$(LIB_DIR)/libeq.a:
	make -C $(LIB_DIR) libeq.a

clean: $(LIB_DIR)/clean
	rm *.so

$(LIB_DIR)/clean:
	make -C $(LIB_DIR) clean

make fclean: clean libclean

re: fclean all