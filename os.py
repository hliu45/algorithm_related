import os
from datetime import datetime 

#print dir(os)
print os.getcwd()

# change to the new working directory
os.chdir('/Users/Joe_Liu/Desktop/python')

print os.getcwd()

# in the given directory list the item in the directory
print os.listdir('/Users/Joe_Liu/Desktop/python')

#os.mkdir('stuff')
#os.makedirs('stuff/test.txt')

#os.rmdir('stuff')
#os.removedirs('Desktop/stuff')


#rename file os.rename(original_file_name, new_file_name)
#os.rename('stuff/test.txt', 'stuff/practice')

#mod_time = os.stat('test.txt').st_atime

# print human readable time
#print datetime.fromtimestamp(mod_time)


# for dirpath, dirnames, filenames in os.walk('/Users/Joe_Liu/Desktop/'):
# 	print 'current path:',dirpath
# 	print 'directories:',dirnames
# 	print 'file name:',filenames
# 	print ''


# print home directory
print os.environ.get('HOME')

# join two path together
file_path = os.path.join(os.environ.get('HOME')+'/Desktop/python','p1.txt')

# get the file name from the path
print os.path.basename('/python/test.txt')

# get the path and file name
print os.path.split('/python/test.txt')

# check if file exists
print os.path.exists('/Users/Joe_Liu/Desktop/python/test.txt')

# check if directory exist
print os.path.isdir('/tmp/dff')


print os.path.splitext('python/test.txt')





