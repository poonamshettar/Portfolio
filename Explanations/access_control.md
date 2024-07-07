<ol>
<li><a href="#role-based-access-controlrbac">Role based Access Control</a></li>
<li><a href="#hirearchial-access-control">Hirearchial Access Control</a></li>
</ol>

### Role Based Access Control(RBAC):

In RBAC permissions are associated with roles and roles are assigned to users.

#### Data Structures used:

- Graphs
- Hash Tables

#### Algorithms Used:

- <b>Depth-First-Search(DFS)</b> and <b>Breadth-First-Search(BFS)</b>:Traverse role hirearchies to determine effective permissions for a user.
  [click for code of dfs and bfs](codes/Graph.c)

  <b>Complexity Analysis</b>

  | **Algorithm** | **Time Complexity** | **Space Complexity** |
  | ------------- | ------------------- | -------------------- |
  | DFS           | O(V \* E)           | O(V)                 |
  | BFS           | O(V + E)            | O(V)                 |

- Djikstra's Algorithm: Shortest path in permission hirearchies for least privilege access.

  [click for code of Djikstra's](code/djikstra.cpp)

  <b>Complexity Analysis</b>

  | **Aspect**       | **Complexity**   |
  | ---------------- | ---------------- |
  | Time Complexity  | O((V + E) log V) |
  | Space Complexity | O(V)             |

- Topological Sort:To resolve conflicts in permissions.

  [click for code of Topological Sort](code/topo.cpp)

  <b>Complexity Analysis</b>

  | **Aspect**       | **Complexity** |
  | ---------------- | -------------- |
  | Time Complexity  | O(V + E)       |
  | Space Complexity | O(V+E)         |

#### Hirearchial Access Control

Subset of RBAC with roles organized in hirearchy adding an extra layer of complexity.

<b>Data Structures used:</b>

- tree
- trie
- Directed Acyclic Graphs(DAG)
