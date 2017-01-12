class Solution(object): 
    def findStrobogrammatic(self, n): 
        if n==0:
            return [""]
        elif n==1:
            return ["0","1","8"]
        
        result=[]
        mask1=[["1","1"],["6","9"],["8","8"],["9","6"]]
        mask2=[["0","0"],["1","1"],["6","9"],["8","8"],["9","6"]]
        mask3=["0","1","8"]
        wordcount={}
        wordcount[0]=4
        for i in range(1,n/2):
            wordcount[i]=5
        if n%2==1:wordcount[n/2]=3
        
        if n%2==0:
            count=[0 for i in range(n/2)]
        else:
            count=[0 for i in range(n/2+1)]
        word=["x"]*n
        
        
        result=[]
    
        while n%2==0 and n>1:
            
            for i in range(n/2):
                if i==0:
                    word[i], word[n-1-i]= mask1[count[i]][0], mask1[count[i]][1]
                else:
                    word[i], word[n-1-i]= mask2[count[i]][0], mask2[count[i]][1]
            
            tmp=""
            for i in range(n):
                tmp+=word[i]
            result.append(tmp)
            
            
            
            count[n/2-1]+=1 
            for i in range(n/2-1): 
                if(count[n/2-1-i]==wordcount[n/2-1-i]): 
                    count[n/2-2-i]+=1 
                    count[n/2-1-i]=0 
            if count[0]==wordcount[0]: 
                break 
        
            
        while n%2==1 and n>1:
            
            for i in range(n/2+1):
                if i==0:
                    word[i], word[n-1-i]= mask1[count[i]][0], mask1[count[i]][1]
                elif i==n/2:
                    word[i]=mask3[count[i]]
                else:
                    word[i], word[n-1-i]= mask2[count[i]][0], mask2[count[i]][1]
            
            tmp=""
            for i in range(n):
                tmp+=word[i]
            result.append(tmp)
            
            
            count[n/2]+=1 
            for i in range(n/2): 
                if(count[n/2-i]==wordcount[n/2-i]): 
                    count[n/2-1-i]+=1 
                    count[n/2-i]=0 
            if count[0]==wordcount[0]: 
                break 
        
        
        
        
        
        
        
        
        return result
