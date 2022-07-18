graph = {
	'A': ['B', 'D'],
	'B': ['C', 'F'],
	'C': ['E', 'G', 'H'],
	'D': ['F'],
	'E': ['B', 'F'],
	'F': ['A'],
	'G': ['E', 'H'],
	'H': ['A'],
}
visited = []


def dfs(visited, graph, node):
	if node not in visited:
		print(node, end=" ")
		visited.append(node)
		for neighbour in graph[node]:
			dfs(visited, graph, neighbour)


root = input("Enter the Root Node: ")
print("\nFollowing is the Depth-First Search Result: ")
dfs(visited, graph, root)
