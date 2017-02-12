import heapq
smaller, bigger = [], []

heapq.heapify(smaller)
heapq.heapify(bigger)

def addNumber(number,small,bigger):
	if len(smaller)==0 or number<smaller[0]*(-1):
		heapq.heappush(smaller,number*(-1))
	else:
		heapq.heappush(bigger,number)

def balance(smaller,bigger):
	if len(smaller)>len(bigger)+1:
		n=heapq.heappop(smaller)
		heapq.heappush(bigger, n*(-1))
	if len(bigger)>len(smaller)+1:
		n = heapq.heappop(bigger)
		heapq.heappush(smaller, n*(-1))


def findMedian(arraylist, smaller, bigger):
	for e in arraylist:
		addNumber(e,smaller,bigger)
		balance(smaller,bigger)

	if len(smaller)==len(bigger):
		return float(-smaller[0]+bigger[0])/2
	else:
		if len(smaller)>len(bigger):
			return -smaller[0]
		else:
			return bigger[0]


array = [3,1,4,5,2,7,6,7]
m = findMedian(array,smaller,bigger)
print m
