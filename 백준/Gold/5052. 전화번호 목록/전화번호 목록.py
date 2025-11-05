class TrieNode:
	def __init__(self, val = None):
		self.val = val
		self.children = {}
		self.is_end = False

class Trie:
	def __init__(self):
		self.root = TrieNode()

	def insert(self, str):
		node = self.root
		for c in str:
			if node.is_end:
				return False
			if c not in node.children:
				node.children[c] = TrieNode(c)
			node = node.children[c]

		node.is_end = True

		if len(node.children) > 0:
			return False
		
		return True

def solution():	
    T = int(input())
    
    for _ in range(T):
        N = int(input())
        trie = Trie()
        is_consistent = True
        
        numbers = []
        for _ in range(N):
            numbers.append(input().strip())
        
        numbers.sort()
        
        for number in numbers:
            if not trie.insert(number):
                is_consistent = False
                break
        
        print("YES" if is_consistent else "NO")
solution()