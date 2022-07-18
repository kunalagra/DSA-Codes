graph = {
	'A': ['B', 'D'],
	'B': ['C', 'F'],
	'C': ['E', 'G'],
	'D': ['F'],
	'E': ['B', 'F'],
	'F': ['A'],
	'G': ['E'],
}

def bfs(graph, node):
	visited ,queue = [],[]
	visited.append(node)
	queue.append(node)
	while queue:
		m = queue.pop(0) 
		print (m, end = " ") 
		for neighbour in graph[m]:
			if neighbour not in visited:
				visited.append(neighbour)
				queue.append(neighbour)

root = input("Enter the Root Node: ")
print("\nFollowing is the Breadth-First Search Result: ")
bfs(graph, root)
