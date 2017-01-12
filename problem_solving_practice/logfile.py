import os

dirs = os.listdir('.')
newInfo = open('info.log','w')
newWarn = open('warn.log','w')
newFatal = open('fatal.log','w')

info 	=	'info'
war 	=	'warning'
fat   	=	'fatal'

print dirs

for file in dirs:
	if file == 'syslog1.log' or file == 'syslog2.log' or file == 'syslog3.log' or file == 'syslog4.log':
		f = open(file)
		lines = f.readlines()
		for element in lines:
			print element
			if info in element:
				newInfo.write(element)
			elif war in element:
				newWarn.write(element)
			elif fat in element:
				newFatal.write(element)
				


inf = open('info.log')
lines = inf.readlines()
print len(lines)

