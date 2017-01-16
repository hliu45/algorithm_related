class Node:

	def __init__(self,value):
		self.value = value
		self.next = None

class Linkedlist:
	def __init__(self,head=None,tail=None):
		self.head = head
		self.tail = head
		self.tailnumber = 0

	def getTailNumber(self):
		self.tailnumber = 0
		curr = self.head
		while curr:
			self.tailnumber +=1
			curr = curr.next

		return self.tailnumber

	def printList(self):
		curr = self.head
		while curr:
			if curr.next:
				print curr.value,'->',
			else: print curr.value
			curr = curr.next

	def insertBeforeHead(self,newhead):
		if self.head is None:
			self.head = Node(newhead)
		else:
			tem = Node(newhead)	
			tem.next = self.head
			self.head = tem
		self.tailnumber+=1

	def insertAfterTail(self,aftertail):
		self.tail.next = aftertail
		self.tail = aftertail
		self.tailnumber+=1

	def valueAt(self,x):
		vth = 0
		curr = self.head
		while curr:
			if vth is x:
				return curr.value
			curr = curr.next
			vth+=1
		return -1

	def deleteFirstNode(self):
		self.head = self.head.next

	def deleteTailNode(self):
		curr = self.head
		prev = Node(0)
		prev.next = self.head
		while curr:
			if curr == self.tail:
				prev.next = None
				self.tail = prev
				break
			prev = curr
			curr = curr.next


	def deleteNthNode(self,n):
		if n==0:
			self.deleteFirstNode()
		elif n==self.tailnumber-1:
			self.deleteTailNode()
		else:
			vth = 0
			prev = Node(0)
			prev.next = self.head
			curr = self.head
			while curr:
				if vth is n: 
					prev.next = curr.next
					break
				prev = curr
				curr = curr.next
				vth+=1

		self.tailnumber-=1

	def isCyclePresent(self):
		tank = dict()
		curr = self.head
		while curr:
			if curr not in tank:
				tank[curr]=True
			else: return True
			curr = curr.next
		return False

	def _isCyclePresent(self):
		slow = self.head
		fast = self.head.next

		while slow and fast and fast.next:
			if slow.value==fast.value:
				return True
			
			slow = slow.next
			fast = fast.next.next
		return False







# create a node object as head
head = Node('a')

# construct linkedlist class
linkedlist = Linkedlist(head)
node = Node('b')
linkedlist.insertAfterTail(node)
node = Node('c')
linkedlist.insertAfterTail(node)
node = Node('d')
linkedlist.insertAfterTail(node)
node = Node('e')
linkedlist.insertAfterTail(node)


# print linkedlist
linkedlist.printList()

# get tail nummber
print linkedlist.getTailNumber()

# print linkedlist
linkedlist.printList()

# insert letter z before head
linkedlist.insertBeforeHead('z')

# print linkedlist
linkedlist.printList() 

# access to 3th node
print linkedlist.valueAt(3)

# delete 2th node
linkedlist.deleteNthNode(2)
linkedlist.printList()

# delete tail
linkedlist.deleteTailNode()
linkedlist.printList()

# insert z node after the tail
node = Node('z')
linkedlist.insertAfterTail(node)

# print linkedlist
linkedlist.printList()

# print check if cycle exist
print 'isCyclePresent() check:',linkedlist.isCyclePresent()

# print check if cycle exist
print '_isCyclePresent() check:',linkedlist._isCyclePresent()






