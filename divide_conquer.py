
##
# these functions are designed using divide and conquer
##

# summing the array: ex: [1,2,3] ->6
def sumarray(array):
	length = len(array)
	if len(array)<=1:
		return array[0]

	left = array[:length/2]
	right = array[length/2:]

	return sumarray(left) + sumarray(right)


# find the average, the function is mean to avoid int overflow using divide & conquer
# ex: [3,4] -> 3.5
def average(somelist):
	def average_(array, l ,r):
		if r==l:
			return (float(array[r]),1)
		if r==l+1:
			return (float(array[l])/2 + float(array[l+1])/2,2)

		middle = (l+r)/2
		left, leftmount = average_(array, l, middle)
		right, rightmount = average_(array, middle+1, r)

		return left*leftmount/(leftmount+rightmount)+right*rightmount/(leftmount+rightmount), leftmount+rightmount
	
	return average_(somelist, 0, len(somelist)-1)[0]

# calcaute the x to power of n
# ex: power(2,3) ->
def power(x,n):
	if n==0: return 1

	tem = power(x,n/2)
	if n%2==0:
		return tem*tem
	else:
		return x*tem*tem

# sort the array using divide and conquer
def mergeSort(array):
	def merge(arrA, arrB):
		newArr = []
		ia = ib = 0
		while ia<len(arrA) and ib<len(arrB):
			if arrA[ia]<arrB[ib]:
				newArr.append(arrA[ia])
				ia+=1
			else:
				newArr.append(arrB[ib])
				ib+=1
		if ia<len(arrA):
			newArr.extend(arrA[ia:])
		if ib<len(arrB):
			newArr.extend(arrB[ib:])

		return newArr

	length = len(array)
	if length<=1:
		return array
	left = mergeSort(array[:length/2])
	right = mergeSort(array[length/2:])

	print left
	print right

	return merge(left,right)

# give a list of string find the common prefix
# ex: ['cat', 'cats'] -> 'cat'
def findCommonPrefix(wordarray):
	def merge(wA, wB):
		i, nA, nB =0, len(wA), len(wB)
		
		while i<min(nA,nB):
			if wA[i]!=wB[i]: break
			i+=1

		return wA[:i]

	length = len(wordarray)
	if length ==1 : return wordarray[0]

	left = findCommonPrefix(wordarray[:length/2])
	right = findCommonPrefix(wordarray[length/2:])

	return merge(left, right)


