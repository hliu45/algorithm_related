def minEdit(str1, str2):
	n, m = len(str1), len(str2)
	dp = [[0]*(m+1) for i in xrange(n+1)]

	for i in xrange(n+1):
		dp[i][0] = i

	for i in xrange(m+1):
		dp[0][i] = i

	for i in xrange(1,n):
		for j in xrange(1,m):
			if str1[i]==str2[j]:
				dp[i][j]= dp[i-1][j-1]
			else:
				dp[i][j] = min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) + 1

	
	return dp[n-1][m-1]


print minEdit('thadfadfin', 'thinpnnnnn')


def maxProfit(array):
	minvalue = float('inf')
	ans = 0
	for i in xrange(len(array)):
		minvalue = min(array[i],minvalue)
		ans = max(ans,array[i]-minvalue)


	print ans

array = [7,1,5,3,6,4]


def maxProfit_(array):
	n = len(array)
	if n<2: return 0 

	array = array + [0]
	buy = array[0] if array[1]>array[0] else None
	profit = 0

	for i in xrange(1,n):

		if array[i]<array[i-1]: 
			if buy is None:
				buy = array[i]
			else:
				profit += array[i-1]-buy
				buy = array[i]


	print profit


print maxProfit_(array)

