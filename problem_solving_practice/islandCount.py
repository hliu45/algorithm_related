class Solution(object):
    def numIslands(self, grid):
        yellow, golden = [], []
        grey = {}
        
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        if m==0:
            on, off = False, False
            count = 0
            for i in range(n):
                if grid[i]=='1': on=True
                if grid[i]=='0': 
                    if on==True: on =False; count += 1
            return count
        
        count = 0
        
        for i in range(n):
            for j in range(m):
                grey[(i,j)]=False
        
        for i in range(n):
            for j in range(m):
                if grid[i][j]=='1' and grey[(i,j)]==False:
                    yellow.append([i,j])
                    while len(yellow) > 0:
                        for p in yellow:
                            if p[1]>0:
                                if grey[(p[0],p[1]-1)]==False and [p[0],p[1]-1] not in yellow and [p[0],p[1]-1] not in golden and grid[p[0]][p[1]-1] == '1':
                                    golden.append([p[0],p[1]-1])
                            if p[0]>0:
                                if grey[(p[0]-1,p[1])]==False and [p[0]-1,p[1]] not in yellow and [p[0]-1,p[1]] not in golden and grid[p[0]-1][p[1]] == '1':
                                    golden.append([p[0]-1,p[1]])
                            if p[1]<m-1:
                                if grey[(p[0],p[1]+1)]==False and [p[0],p[1]+1] not in yellow and [p[0],p[1]+1] not in golden and grid[p[0]][p[1]+1] == '1':
                                    golden.append([p[0],p[1]+1])
                            if p[0]<n-1:
                                if grey[(p[0]+1,p[1])]==False and [p[0]+1,p[1]] not in yellow and [p[0]+1,p[1]] not in golden and grid[p[0]+1][p[1]] == '1':
                                    golden.append([p[0]+1,p[1]])
                        
                        for ye in yellow:
                            grey[(ye[0],ye[1])]=True
                            yellow.remove(ye)
                        for ge in golden:
                            yellow.append(ge)
                            golden.remove(ge)
                    count += 1
                
                
        return count
