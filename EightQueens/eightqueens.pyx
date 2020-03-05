
cdef extern from "e_q.h":
	void ft_eight_queens_puzzle_2(int N)

def eight_queens(N: int):
	ft_eight_queens_puzzle_2(N)