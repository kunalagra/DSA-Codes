class Graph:
	def __init__(self,vertices):
		self.V=vertices
		self.graph=[]

	def addEdge(self,u,v,w):
		self.graph.append([u,v,w])

	def printGraph(self,dist):
		print("\nDistance:")
		for i in range(self.V):
			print("%d \t\t %d "%(i,dist[i]))

	def BellmanFord(self,src):
		dist=[float("Inf")]*self.V
		dist[src]=0
		for u,v,w in self.graph:
			if dist[u] != float("Inf") and dist[u]+w<dist[v]:
				dist[v]=dist[u]+w
		for u,v,w in self.graph:
			if dist[u] != float("Inf") and dist[u]+w<dist[v]:
				print("Graph contains negative cycle!!")
				return
		self.printGraph(dist)

vertices=int(input("Enter number of vertices: "))
edges=int(input("Enter number of edges: "))
g=Graph(vertices)
print("Enter in order: Source Destination Weight")
print("S D W")
#S - Source Edge, D - Destination Edge, W - Weight
for i in range(edges):
	l=list(map(int,input().strip().split()))
	g.addEdge(l[0],l[1],l[2])
g.BellmanFord(0)


"""
5
8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
"""
