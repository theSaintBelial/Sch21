
decision_count = 0

def print_one_decision(Tab, N):
	Decision = [0] * N
	for y in range(N):
		for x in range(N):
			if (Tab[y][x]):
				print(x + 1, end=" ")
	print(end="\n")

def is_safe_diagonal(Tab, x, y, N):
	x1 = x
	y1 = y

	for x, y in zip(list(range(x, -1, -1)), list(range(y, -1, -1))):
		pass
	for x, y in zip(list(range(x, N)), list(range(y, N))):
		if (Tab[y][x]):
			return (False)
	for x1, y1 in zip(list(range(x1, -1, -1)), list(range(y1, N - 1))):
		pass
	for x1, y1 in zip(list(range(x1, N)), list(range(y1, -1, -1))):
		if (Tab[y1][x1]):
			return (False)
	return (True)

def is_safe_col(Tab, x, N):
	for y in range(N):
		if (Tab[y][x]):
			return (False)
	return (True)

def is_safe_place(Tab, x, y, N):
	if (is_safe_col(Tab, x, N)):
		if (is_safe_diagonal(Tab, x, y, N)):
			return (True)
	return (False)

def eight_queens(Tab, y, N):
	global decision_count

	if (y == N):
		return (False)
	for x in range(N):
		if (is_safe_place(Tab, x, y, N)):
			Tab[y][x] = True
			if (y == N - 1):
				# print_one_decision(Tab, N)
				decision_count += 1
			if (eight_queens(Tab, y + 1, N)):
				return (True)
			Tab[y][x] = False
	return (False)

def main():
	global decision_count

	N = 13
	Tab = [[False] * N for y in range(N)]
	# print("There are all posible solutions below:")
	eight_queens(Tab, 0, N)
	# print("\n---------------------------------------------\n")
	print("Count of all possible solutions:", decision_count)

main()