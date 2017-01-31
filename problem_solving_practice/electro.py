'''
problem: 

given a array of cost and values, ex:
_____________________________________
cost	|2	|5	|7	|9	|11	|12	|16	|
-------------------------------------
values 	|3	|1	|4	|5	|1	|2	|3	|
-------------------------------------

find the combination which value is over some threshold ex: value>=7 with minimum cost	

'''


m = [[float("inf")]*20 for i in xrange(8)]
v = [3,1,4,5,1,2,3]
c = [2,5,7,9,11,12,16]



for i in xrange(8):
	m[i][0]=0

for j in xrange(20):
	m[0][j]=float("inf")


for i in xrange(1,8):
	for j in xrange(20):
		if j<=v[i-1]:
			m[i][j] = min(m[i-1][j],c[i-1])
		else:
			m[i][j] = min(m[i-1][j],m[i-1][j-v[i-1]]+c[i-1])


print m[7][8] # it return considering total n=7 items with threshold 8