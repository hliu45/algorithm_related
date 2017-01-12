class Solution(object):
    a = [0,[0],[0]]
    def median(self,nums):
        if (len(nums)%2 is 0):
            m1= (nums[len(nums)/2 -1] + nums[len(nums)/2])/2
            ms= nums[0:len(nums)/2]
            mb= nums[len(nums)/2:len(nums)]
        else:
            m1 = nums[(len(nums)-1)/2]
            ms = nums[0:(len(nums)-1)/2]
            mb = nums[(len(nums)+1)/2:len(nums)]
        self.a = [m1,ms,mb]
        return self.a
    
    
    def findMedianSortedArrays(self, nums1, nums2):
        m1 = self.median(nums1)
        m2 = self.median(nums2)
        if m1[0] is m2[0]:
            return m1[0]
        elif m1[0] < m2[0]:
            return self.findMedianSortedArrays(m1[2],m2[1])
        else:
            return self.findMedianSortedArrays(m1[1],m2[2])


list1 = [2,4,6,9]
list2 = [3,3,5,7,8]
sol = Solution()
print sol.findMedianSortedArrays(list1,list2)