from itertools import permutations

def permutation(string):
	if len(string)==1:
		return [string]

	tem = [string[0]]

	for i in xrange(1,len(string)):
		tem = [com[:j]+string[i]+com[j:] for j in xrange(i+1) for com in tem]

	return tem

def perms(s):
	if len(s)==1:
		return [s]

	res = []
	for i, c in enumerate(s):
		for per in perms(s[:i]+s[i+1:]):
			res += [c+per]

	return res



print [''.join(p) for p in permutations(['a','b','c','d'])]
print permutation('abcd')
print perms('abcd')