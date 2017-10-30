import math


# def fact(n):
# 	if n == 1 or n == 0:
# 		return 1
# 	return n * fact(n-1)

# def power(a, b):
# 	ans = 1
# 	while b:
# 		ans = ans * a
# 		# print(ans)
# 		b -= 1
# 	return ans

test = input()
test = int(test)
ii = 0
while ii < test:
	values = input()
	a, b, c = values.split()
	a = int(a)
	b = int(b)
	c = int(c)
	f = math.factorial(b)
	# print(f)
	ans = pow(a, f)%c
	print("Case #{}:".format(ii+1), int(ans))
	ii += 1
