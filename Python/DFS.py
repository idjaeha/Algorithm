class Tree:
    def __init__(self, root, node):
        self.tree = {}
        self.root = root

    def make_node(self, parent, child):
        if parent not in self.tree:
            self.tree[parent] = []
        if child not in self.tree:
            self.tree[child] = []

        self.tree[parent].append(child)
        self.tree[child].append(parent)

    def dfs(self):
        visit = []
        stack = []

        stack.append(self.root)
        while stack:
            node = stack.pop()
            if node not in visit:
                visit.append(node)
                sub_tree = self.tree[node]
                if sub_tree:
                    sub_tree.sort(reverse=True)
                    stack.extend(sub_tree)

        if visit:
            for idx, node in enumerate(visit):
                print(node, end="")
                if idx == len(visit) - 1:
                    print()
                else:
                    print(end=" ")

    def bfs(self):
        visit = []
        queue = []

        queue.append(self.root)
        while queue:
            node = queue[0]
            del queue[0]
            if node not in visit:
                visit.append(node)
                sub_tree = self.tree[node]
                if sub_tree:
                    sub_tree.sort()
                    queue.extend(sub_tree)

        if visit:
            for idx, node in enumerate(visit):
                print(node, end="")
                if idx == len(visit) - 1:
                    print()
                else:
                    print(end=" ")


node, link, root = list(map(int, input().split()))
my_tree = Tree(root, node)
for _ in range(link):
    my_tree.make_node(*list(map(int, input().split())))

my_tree.dfs()
my_tree.bfs()
