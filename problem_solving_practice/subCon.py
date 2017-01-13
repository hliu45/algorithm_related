#32
class Solution(object):
        def findSubstring(self,s,words):
                list=[]
                le = len(s)
                i=0
                while (i < le):
                        wordlist=[]
                        if s[i:i+3] in words:
                                j=i
                        while(s[i:i+3] in words and s[i:i+3] not in wordlist):
                                wordlist.append(s[i:i+3])
                                i+=3
                        if len(wordlist)==len(words):
                                list.append(j)
                        i+=3
                return list


# test function findSubstring
s = "barfoothefoobarman"
words = ["foo","bar"]

a=Solution()
print a.findSubstring(s,words)
