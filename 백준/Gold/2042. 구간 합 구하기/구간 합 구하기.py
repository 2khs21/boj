import sys
input = sys.stdin.readline

class SegTree:
    def __init__(self, arr : list[int]):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.build(arr, 1, 0, self.n - 1)
        
    def build(self, arr, node, start, end):
        if start == end:
            self.tree[node] = arr[start]
        else:
            mid = (start + end) // 2
            self.build(arr, node * 2, start, mid)
            self.build(arr, node * 2 + 1, mid + 1, end)
            self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]
    
    def update(self, node, start, end, idx, diff):
        if idx < start or idx > end:
            return
        
        self.tree[node] += diff

        if start != end:
            mid = (start + end) // 2
            self.update(node*2, start, mid, idx, diff)
            self.update(node*2+1, mid+1, end, idx, diff)
    
    def query(self, node, start, end, left, right):
        if right < start or end < left:
            return 0
        
        if left <= start and end <= right:
            return self.tree[node]
        
        mid = (start + end) // 2
        left_sum = self.query(node*2, start, mid, left, right)
        right_sum = self.query(node*2+1, mid+1, end, left, right)
        return left_sum + right_sum

n, m, k = map(int, input().split())

arr = [int(input()) for _ in range(n)]

seg_tree = SegTree(arr)

for _ in range(m + k):
    a, b, c = map(int, input().split())
    
    if a == 1:
        idx = b - 1
        diff = c - arr[idx]
        arr[idx] = c
        seg_tree.update(1, 0, n - 1, idx, diff)
    else:
        left = b - 1
        right = c - 1
        result = seg_tree.query(1, 0, n - 1, left, right)
        print(result)