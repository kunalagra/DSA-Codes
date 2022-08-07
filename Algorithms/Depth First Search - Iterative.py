def dfs_iter(graph, start, path=[]):
    q=[start]
    while q:
        v = q.pop()
        if v not in path:
            path += [v]
            q += graph[v]
    return path


if __name__ == '__main__':
    graph = {}
    numnode = int(input("No. Of Nodes in Graph: "))
    while numnode > 0:
        key = input("Enter Kesy: ")
        value = input("Enter Values: ").split(" ")
        if value == [""]:
            value = []
        graph[key] = value
        numnode -= 1
    root = input("Enter the Root Node: ")
    print(dfs_iter(graph, root))