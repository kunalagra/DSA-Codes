def edge_cost(graph):
  l = []
  for node in list(graph.keys()):
    if graph[node]==None:
        continue
    for neigh in graph[node]:
      l.append(((node,neigh[0]),neigh[1]))
  
  l = sorted(l,key = lambda x:x[1])
  return l    

def mst(graph):
    v_edges = []
    all_nodes = set()
    nodes = set(list(graph.keys()))
    cost = 0
    edges = edge_cost(graph)
    res = []
    for edge in edges:
        if all_nodes==nodes:
            break

        if v_edges==[]:
            v_edges.append(set(edge[0]))
            all_nodes.add(edge[0][1])
            all_nodes.add(edge[0][0])
            cost += edge[1]
            res.append('accepted')
           
        else:
            a = 0
            b = 0
            u = edge[0][0]
            v = edge[0][1]
            for v_edge in v_edges:
                if (u in v_edge) or (v in v_edge):
                    for ve in v_edges:
                        if ((v in ve) and (ve==v_edge) and u in v_edge) or ((u in ve) and (ve==v_edge) and  v in v_edge):
                            a = 1
                            res.append('rejected')
                            break
                        
                        elif ((v in ve) and (u in v_edge)) or ((u in ve) and (v in v_edge)):
                            s = set.union(v_edge,ve)
                            v_edges.remove(v_edge)
                            v_edges.remove(ve)
                            v_edges.append(set(s))
                            cost += edge[1]
                            all_nodes.add(u)
                            all_nodes.add(v)
                            a = 1
                            res.append('accepted')
                            break
                            
                    if a==0:
                        s = set.union(set(edge[0]),v_edge)
                        v_edges.remove(v_edge)
                        v_edges.append(set(s))
                        all_nodes.add(u)
                        all_nodes.add(v)
                        cost += edge[1] 
                        res.append('accepted')       
                    b = 1

            if b==0:
                all_nodes.add(u)
                all_nodes.add(v)
                v_edges.append(set(edge[0]))
                cost += edge[1]
                res.append('accepted')
    
    while len(res)<len(edges):
        res.append('rejected')                         
    return res,cost
                       

if __name__ == "__main__":
    graph = {
       'A' : [('B',10),('D',30),('E',45)],
       'B' : [('C',50),('E',40),('F',25)],
       'C' : [('E',35),('F',15)],
       'D' : [('F',20)],
       'E' : [('F',55)],
       'F' : None
    }
    
    result,min_cost = mst(graph)
    print("   Edge\t \tCost\tSelection")
    i = 0
    for edge,cost in edge_cost(graph):
        print(f"{edge}\t{cost}\t{result[i]}")
        i += 1
    
    print(f"\nThe Minimum cost will be {min_cost}")