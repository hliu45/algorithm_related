# for practicing log parser
number = 1234 # integer
floatNum = 123.456 # Decimal/floating
string = 'howareyou' # string
isPresent = True #could be false too Boolean

print string
print number
print number, floatNum
print isPresent, floatNum
'''
age = 8
def ageChecking(age):
	if age < 10:
		print "you age is ",age," Too young"
	elif age <20:
		print "still younger than 20"
	elif age < 30:
		print "You are an adult"
	elif age> 70:
		print "you are very old"
	else:
		print "hello adult"

ageChecking(age)
'''
'''
number = 3
for i in range(1,10):
	print i*number

'''	

'''
maxLim = input('Enter any number: ')
print maxLim

for num in range(1,maxLim):
	print num
'''


# List 
# A collection of data types

list1 = [1, 20, 3, 4,'ASHA',34.99]
for i in list1:
	print i

list1.append("k")

print list1

#print list1[4]
list1.remove(4)
print list1
'''
if 'asha' in list1:
	print 'hello asha'
'''
name = 'AshA'
for i in list1:
	if name.upper() == i:
		print 'Asha is present'	

# Dictionary
# Key => Value
#list2 = [44,55] 
employeeDict = {'101':'abcd'}
employeeDict['a'] = 11
employeeDict['b'] = 22


print employeeDict['101']

for k in employeeDict.keys():
	print k
print "-------- ## ----------- ## ------"
for v in employeeDict.values():
	print v

print "-------- ## ----------- ## ------"

if 'a' in employeeDict.keys():
	print employeeDict['a']
print '----------------------'
for k,v in employeeDict.items():
	print k,v

lis=[1,2,3]
print lis[0]

