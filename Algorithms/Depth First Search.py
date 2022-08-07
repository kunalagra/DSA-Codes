# Dictionary used for the graph
graph = {}

# Keep unvisisted node
visited = set()

def dfs(visited, graph, node):
    if node not in visited:
        print(node, end=" ")
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

# Driver Code
numnode = int(input("No. Of Nodes in Graph: "))
while numnode > 0:
    key = input("Enter Key: ")
    value = input("Enter Values: ").split(" ")
    if value == [""]:
        value = []
    graph[key] = value
    numnode -= 1

root = input("Enter the Root Node: ")
print("\nFollowing is the Depth-First Search Result: ")
dfs(visited, graph, root)
