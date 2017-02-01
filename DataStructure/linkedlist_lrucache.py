class Node(object):
	def __init__(self, key=None, value=None):
		self.key = key
		self.val = value
		self.next = None
		self.prev = None

class Linkedlist(object):
	def __init__(self):
		self.head = None
		self.tail = None

	def isEmpty(self):
   		return self.tail is None
    
	def removeLast(self):
   		self.remove(self.tail)
        
	def remove(self,node):
		if self.head == self.tail and self.head == node:
			self.head = self.tail = None
			return
		if node == self.head:
			self.head = self.head.next
			self.head.prev = None
			return

   		if node == self.tail:
   			self.tail = self.tail.prev
   			self.tail.next = None
   			return

   		node.prev.next = node.next
		node.next.prev = node.prev
		
        
	def addFirst(self,node):
		if not self.head:
			self.head = node
			self.tail = node
			node.prev = node.tail = None
			return
		else:
			self.head.prev = node
			node.next = self.head
			self.head = node
			self.head.prev = None

	def printLinkedlist(self):
		curr = self.head
		while curr:
			print curr.val,
			curr = curr.next
		print ''
        
class LRUCache(object):

    # @param capacity, an integer
    def __init__(self, capacity):
    	self.capacity = capacity
        self.size = 0
        self.cache = Linkedlist()
        self.dic = dict()
    
    def printList(self):
		curr = self.cache.head
		while curr:
			print curr.val,
			curr = curr.next
		print ''

    # @return an integer
    def get(self, key):
    	if key in self.dic and self.dic[key]:
    		self.cache.remove(self.dic[key])
    		self.cache.addFirst(self.dic[key])
    		return self.dic[key].val
    	else:
    		return -1
            
    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
		if key in self.dic and self.dic[key]:
			self.cache.remove(self.dic[key])
			self.cache.addFirst(self.dic[key])
			self.dic[key].vl = value
		else:
			node = Node(key,value)
			self.dic[key] = node
			if self.size<self.capacity:
				self.cache.addFirst(node)
				self.size+=1
			else:
				self.cache.removeLast()
				del self.dic[self.cache.tail.key]
				self.cache.addFirst(node)



lru = LRUCache(6)
lru.set('1',1)
lru.set('2',2)
lru.set('3',3)
lru.set('4',4)
lru.printList()
lru.set('5',5)
lru.printList()
lru.set('6',6)
lru.printList()
lru.set('7',7)
lru.printList()
lru.get('3')
lru.set('11',11)
lru.printList()







