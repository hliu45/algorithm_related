class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        N= len(gas)
        
        for i in range(0,N):
            gastank = 0
            current = i # start from index i
            while current <N and gastank >=0:
                gastank += (gas[current]-cost[current])
                current += 1
            current =0  
            while current<i and gastank >=0:
                gastank += (gas[current]-cost[current])
                current += 1
            if gastank >= 0:
                return i
        return -1
