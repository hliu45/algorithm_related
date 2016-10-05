#42

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
	tank = 0
	n = len(height)
	if n > 0:
		# m: the peak of tank, m_index: index of that peak
		(m,m_index) = max((v,i) for i,v in enumerate(height))
		# rev store the info. of wate up to the highest surface to the peak
		rev = [] 
		for i in range(0,n):
			rev.append(m-height[i])
		if m_index>0:
			for j in range(1,m_index):
				if rev[j]-rev[j-1]>0:
					tank+=(rev[j]-rev[j-1])
					rev[j]=rev[j-1]
		if m_index<n:
			for j in range(n-1,m_index,-1):
				if rev[j-1]-rev[j]>0:
					tank+=(rev[j-1]-rev[j])
					rev[j-1]=rev[j]
	return tank
