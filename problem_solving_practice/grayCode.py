iclass Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n is 0:
            return [0]
        if n is 1:
            return [0,1]
        base, table = 1, ['0','1']
        result = []
        while(base<n):
            result = []
            m=len(table)
            for i in range(0,m):
                if i%2==0:
                    result.append(table[i]+'0')
                    result.append(table[i]+'1')
                else:
                    result.append(table[i]+'1')
                    result.append(table[i]+'0')
            table = result
            base += 1
        final_result =[]
        for i in range(0,len(result)):
            final_result.append(int(result[i],2))
        return final_result
