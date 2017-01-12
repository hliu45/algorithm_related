class Solution(object):
    def maxKilledEnemies(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        
        '''
        Scan each row to find the numbers bomb in i direction for each '0' and for each row, 
        then scan each column to find the number of bombs for each column for each '0' 
        
        Using dictionary to map each '0' to the number of bomb, and find the largest possible bomb in both i and j direction
        '''
        
        n=len(grid)
        if n==0:
            return 0
        m = len(grid[0])
        
        zdic={}
        
        for i in range(n):
            bomb = 0
            start= -1
            tmp=[] #tmp is the collection of bomb between 'W'
            for j in range(m):
                if grid[i][j]=='0': 
                    zdic[(i,j)]=0
                    tmp.append((i,j))
                        
                if grid[i][j]=='E': bomb+=1
                if grid[i][j]=='W':
                    for ele in tmp:
                        zdic[ele]=bomb
                    start = j
                    tmp=[]
                    bomb = 0
                    
            # assume at the end of each row there also a wall 'W'
            for ele in tmp:
                zdic[ele]=bomb
        
        largest = 0 #largest number of bomb
        
        for j in range(m):
            bomb = 0
            start= -1
            tmp=[]
            for i in range(n):
                if grid[i][j]=='0':
                    tmp.append((i,j))
                    
                if grid[i][j]=='E': bomb+=1
                if grid[i][j]=='W':
                    for ele in tmp:
                        zdic[ele]+=bomb
                        if zdic[ele] > largest: largest = zdic[ele]
                    start = i
                    tmp=[]
                    bomb = 0

            for ele in tmp:
                zdic[ele]+=bomb
                if zdic[ele] > largest: largest = zdic[ele]
                    
        
        return largest
