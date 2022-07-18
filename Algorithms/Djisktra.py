from collections import deque
from tabulate import tabulate
INFINITY = float("inf")

class Graph:
	def __init__(self):
		graph_edges = []
		size=int(input("Enter No. of Edges of Graph: "))	
		print("Enter Edges of Graphs (V1 V2 Dist)")
		while(size!=0):
			edge_from, edge_to, cost = map(str,input().strip().split(" "))
			graph_edges.append((edge_from, edge_to, float(cost)))
			size-=1
		self.nodes = set()
		for edge in graph_edges:
			self.nodes.update([edge[0], edge[1]])
		self.adjacency_list = {node: set() for node in self.nodes}
		for edge in graph_edges:
			self.adjacency_list[edge[0]].add((edge[1], edge[2]))
	def get_nodes(self):
		a= self.nodes
		b=list(a)
		b.sort()
		return b
	def shortest_path(self, start_node, end_node):
		unvisited_nodes = self.nodes.copy()
		distance_from_start = {
			node: (0 if node == start_node else INFINITY) for node in self.nodes
		}
		previous_node = {node: None for node in self.nodes}

		while unvisited_nodes:
			current_node = min(
				unvisited_nodes, key=lambda node: distance_from_start[node]
			)
			unvisited_nodes.remove(current_node)
			if distance_from_start[current_node] == INFINITY:
				break
			for neighbor, distance in self.adjacency_list[current_node]:
				new_path = distance_from_start[current_node] + distance
				if new_path < distance_from_start[neighbor]:
					distance_from_start[neighbor] = new_path
					previous_node[neighbor] = current_node

			if current_node == end_node:
				break
		path = deque()
		
		current_node = end_node
		while previous_node[current_node] is not None:
			path.appendleft(current_node)
			current_node = previous_node[current_node]
		path.appendleft(start_node)

		return path, distance_from_start[end_node]

def main():
	graph = Graph()
	a = graph.get_nodes()
	start = str(input("Enter Start Node: "))
	l = []
	for end in a:
		returned_path, returned_distance = graph.shortest_path(start, end)
		l.append([start, end,list(returned_path),float(returned_distance)])

	table = tabulate(l, headers=['Start', 'End', 'Path','Distance'], tablefmt='orgtbl',colalign=("center","center"))
	print("\n")
	print(table)
	print("\n")

if __name__ == "__main__":
	main()

#Input
"""
12
A B -1
A C 3
A D 6
B C 6
B E 4
C E 6
C D 7
D F 2
D E 2
E G 3
E F 4
F G 5
"""