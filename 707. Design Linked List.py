class Node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None



class MyLinkedList:
	
	def __init__(self):
		self._head = Node(0)
		self._tail = Node(0)
		
		self._head.next = self._tail
		self._tail.prev = self._head
		self.length = 0
		
	def get_node(self, index: int):
		if index < self.length // 2:
			cur = self._head
			for i in range(index + 1):
				cur = cur.next
		else:
			cur = self._tail
			for i in range(self.length - index):
				cur = cur.prev
		return cur
	
	def get(self, index: int) -> int:
		if 0 <= index < self.length:
			return self.get_node(index).val
		else: 
			return -1
		
		
		
	def addAtHead(self, val: int) -> None:
		new = Node(val)
		self._head.next.prev = new
		new.next = self._head.next
		new.prev = self._head
		self._head.next = new
		self.length += 1
		
	def addAtTail(self, val: int) -> None:
		new = Node(val)
		self._tail.prev.next = new
		new.prev = self._tail.prev
		new.next = self._tail
		self._tail.prev = new
		self.length += 1
		
	def addAtIndex(self, index: int, val: int) -> None:
		if index > self.length:
			return 0
		cur = self.get_node(index)
		new = Node(val)
		cur.prev.next = new
		new.prev = cur.prev
		new.next = cur
		cur.prev = new
		self.length += 1
	
	def deleteAtIndex(self, index: int) -> None:
		if 0 <= index < self.length:
			cur = self.get_node(index)
			cur.prev.next = cur.next
			cur.next.prev = cur.prev
			self.length -= 1
            


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)