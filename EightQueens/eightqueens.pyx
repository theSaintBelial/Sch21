
cdef extern from "e_q.h":
	void ft_eight_queens_puzzle_2()

def eight_queens() -> None:
	ft_eight_queens_puzzle_2()