class Solution(object):
    def getHint(self, secret, guess):
        bull = 0
        cow = 0
        secdic = dict()
        guesdic = dict()
        for i in range(len(secret)):
            if secret[i]==guess[i]:
                bull+=1
            secdic[secret[i]]=secdic.get(secret[i],0)+1   
            guesdic[guess[i]]=guesdic.get(guess[i],0)+1
            
        for key, value in guesdic.items():
            if key in secdic.keys():
                cow+=min(guesdic[key],secdic[key])
        cow-=bull
        
        return str(bull)+'A'+str(cow)+'B'
