#42

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
	tank = 0
	n = len(height)
	m = max(height)
	# rev store the info. of wate up to the highest surface to the peak
	rev = [] 
	# the index of highest peak
	m_index = 0 # 
	for i in range(0,n):
		rev.append(m-height[i])
		if m==height[i]:
			m_index = i
	if m_index>0:
		for j in range(1,m_index):
			diff=rev[j]-rev[j-1]
			if diff>0:
				tank+=diff
				rev[j]=rev[j]-diff
				print diff
	if m_index<n:
		for j in range(n-1,m_index,-1):
			diff=rev[j-1]-rev[j]
			if diff>0:
				tank+=diff
				rev[j-1]-=diff
				print diff
	return tank
