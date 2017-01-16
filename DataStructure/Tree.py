class TreeNode:
	def __init__(self,val):
		self.val = val
		self.left = None
		self.right = None

	
	def printNode(self):
		print self.val,
	
	def debug(self):
		print ""+self.left.val+"-"+self.val+"-"+self.right.val



def InOrderTraveral(root):
	if not root: return

	InOrderTraveral(root.left)
	root.printNode()
	InOrderTraveral(root.right)

def PreOrderTraveral(root):
	if not root: return

	root.printNode()
	PreOrderTraveral(root.left)
	PreOrderTraveral(root.right)

def PostOrderTraveral(root):
	if not root: return

	PostOrderTraveral(root.left)
	PostOrderTraveral(root.right)
	root.printNode()

def LevelOrderTraveral(root):
	node = [root] if root else []
	while node:
		for ele in node:
			ele.printNode()
		node = filter(lambda x: x, [i for j in node if j for i in [j.left,j.right]])
		


root = TreeNode("Les")
root.left = TreeNode("Cathy")
root.right = TreeNode("Sam")
root.left.left = TreeNode("Alex")
root.left.right = TreeNode("Frank")
root.right.left = TreeNode("Nancy")
root.right.right = TreeNode("Violet")
root.right.right.left = TreeNode("Tony")
root.right.right.right = TreeNode("Wendy")





print "InOrder:",
InOrderTraveral(root)

print ""
print "PreOrder:",
PreOrderTraveral(root)
print ""
print "PostOrder:",
PostOrderTraveral(root)
print ""
print "levelOrder:",
LevelOrderTraveral(root)