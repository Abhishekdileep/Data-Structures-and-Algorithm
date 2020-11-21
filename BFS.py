def BFS( S  , Adj ):
    level = { S : 0 }
    parent = { S : None }
    i = 1
    frontier = [ S ]
    while frontier : 
        next = [] 
        for u in frontier : 
            for v in Adj[u]:
                if v not in level :
                    level[v] = i
                    parent[v] = u
                    next.append(v)
        frontier = next
        i+=1
    print (level) 
    print (parent)

S = "A"
graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}

BFS(S , graph)
print ('Hello')