#42

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
	n = len(height)
	diff_list=[]
	peak=[]
	vally=[]
	for i in range(1,n):
		diff = height[i]-height[i-1]
		diff_list.append(diff)
	if diff_list[0]<0:
		peak.append(0)
	for j in range(1,n-1):
		if diff_list[j]*diff_list[j-1]<0:
			if diff_list[j]>diff_list[j-1]:
				vally.append(j)
			else:
				peak.append(j)
	if diff_list[n-2]>0:
		peak.append(n-1)
	tank=0
	for i in range(1,len(peak)):
		line=min(height[peak[i]],height[peak[i-1]])
		for element in range(peak[i-1]+1,peak[i]):
			tank+=(line-height[element])
		
	return tank

height=[2,5,7,0,9,5,8,2,10,6,4,9,2,8]

a=Solution()
print a.trap(height)
