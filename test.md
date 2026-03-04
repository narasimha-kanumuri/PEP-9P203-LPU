# 📅 DAY 7 — GRAPHS I
## Traversal, Connectivity & Exploration Patterns

- Aligned with:
- 20-Day Curriculum (Graph Foundations) 
- 20 Day Data Structures and Algo…
- 9-Day Accelerated Structure — Graphs I 
- LPU REVISED 9-DAY ACCELERATED D…
- Master Engine invariant philosophy 
- DSA MASTER ENGINE v2.2

---

## 🎯 DAY 7 OBJECTIVE

- Move from:
- “Trees with one parent”
- To:
- “General networks with arbitrary connections.”
- Today is about:
- Graph modeling
- BFS and DFS mastery
- Component detection
- Cycle detection
- Visited invariant
- Grid → graph transformation

---

## 🧠 1️⃣ What Is a Graph? (Zero Knowledge Entry)

- A graph is a structure made of:
- Vertices (Nodes)
- Edges (Connections between nodes)
- Unlike trees:
- Graphs may contain cycles.
- Nodes may have multiple parents.
- Graph may be disconnected.

### Types of Graphs

- 1️⃣ Undirected Graph
- Edge (A—B) means:
- A connects to B AND B connects to A.
- 2️⃣ Directed Graph
- Edge (A → B) means:
- A connects to B only.
- 3️⃣ Weighted Graph
- Edges have cost/weight.
- 4️⃣ Unweighted Graph
- Edges have no cost.

---

## 🧠 2️⃣ Memory Representation

### 🔹 Adjacency List (Most Common)

```cpp id="w6g4kg"
vector<vector<int>> adj(n);
```

- Meaning:
- For each node, store list of neighbors.
- Space:
- O(V + E)

### 🔹 Adjacency Matrix

```cpp id="w6g4kg"
vector<vector<int>> matrix(n, vector<int>(n));
```

- Space:
- O(V²)
- Used when:
- Graph dense.

---

## 🧠 3️⃣ Core Invariant #1 — Visited Prevents Infinite Loops

- Graphs can have cycles.
- If you don't track visited:
- You loop forever.
- Invariant:
- Once a node is visited, never process it again.

```cpp id="w6g4kg"
vector<bool> visited(n, false);
```

- This invariant powers:
- BFS
- DFS
- Connected components
- Cycle detection

---

## 🧠 4️⃣ Breadth-First Search (BFS)

### ELI5
- Explore neighbors layer by layer.
- Like spreading water outward.

### BFS Algorithm

```cpp id="w6g4kg"
queue<int> q;
q.push(start);
visited[start] = true;

while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
}
```

### BFS Guarantees
- In unweighted graph:
- First time you reach a node → shortest path.
- Why?
- Because BFS explores level by level.

---

## 🧠 5️⃣ Depth-First Search (DFS)

### ELI5
- Go as deep as possible before backtracking.

### Recursive DFS

```cpp id="w6g4kg"
void dfs(int node) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
```

### DFS Characteristics
- Explores full branch
- Good for:
- Components
- Cycle detection
- Topological sort (later)
- Island counting

---

## 🧠 6️⃣ Connected Components

- If graph disconnected:
- We must start BFS/DFS from every unvisited node.

```cpp id="w6g4kg"
int components = 0;

for (int i = 0; i < n; i++) {
    if (!visited[i]) {
        dfs(i);
        components++;
    }
}
```

- Invariant:
- Each DFS marks exactly one component.
- Time:
- O(V + E)

---

## 🧠 7️⃣ Cycle Detection (Undirected Graph)

### Key Insight
- If during DFS:
- You visit a neighbor that:
- Is already visited
- And is NOT parent
- → Cycle exists.

```cpp id="w6g4kg"
bool dfs(int node, int parent) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent)
            return true;
    }
    return false;
}
```

---

## 🧠 8️⃣ Number of Islands (Grid → Graph Thinking)

- Given grid of 0s and 1s.
- Each cell is a node.
- Edges:
- Up, Down, Left, Right (if 1).
- Algorithm:
- Traverse grid.
- If cell == 1 and not visited:
- Run DFS/BFS.
- Increment island count.
- Time:
- O(rows × cols)

---

## 🧠 9️⃣ Clone Graph

- Graph node contains:

```cpp id="w6g4kg"
class Node {
public:
    int val;
    vector<Node*> neighbors;
};
```

- Use:
- HashMap to map original node → cloned node.
- Why needed?
- Because graph may have cycles.
- Invariant:
- Each original node must map to exactly one clone.

---

## 🧠 🔟 BFS vs DFS Comparison

| Feature | BFS | DFS |
| :--- | :--- | :--- |
| Data Structure | Queue | Stack/Recursion |
| Finds shortest path (unweighted) | Yes | No |
| Space usage | O(V) | O(H) |
| Good for | Level order | Deep exploration |

---

## 🧠 1️⃣1️⃣ Complexity Understanding

- Let:
- V = number of vertices
- E = number of edges
- Traversal:
- Time:
- $T(V, E) = V + E$
- Why?
- Each node visited once → V
- Each edge explored once → E
- Space:
- Visited array → O(V)
- BFS queue worst-case → O(V)
- DFS recursion stack → O(H)

---

## 🧠 1️⃣2️⃣ Core Invariants for Day 7

- From 9-day structure 
- LPU REVISED 9-DAY ACCELERATED D…
- 1️⃣ Visited prevents reprocessing.
- 2️⃣ BFS guarantees shortest path in unweighted graph.
- 3️⃣ DFS explores entire connected component.
- 4️⃣ Parent tracking required for cycle detection.
- 5️⃣ Grid problems are disguised graph problems.
- From Master Engine 
- DSA MASTER ENGINE v2.2
- Invariant must be explicitly maintained.
- No traversal without termination guarantee.
- Complexity must include V + E reasoning.

---

## ⚠️ Common Beginner Mistakes

- ❌ Forgetting visited array
- ❌ Marking visited after pushing (should mark immediately)
- ❌ Mixing directed vs undirected logic
- ❌ Forgetting parent check in cycle detection
- ❌ Not resetting visited for multi-test cases
- ❌ Using adjacency matrix unnecessarily

---

## 🧠 Mental Shift After Day 7

- Students must now:
- Convert problems into graph models.
- Recognize grids as graphs.
- Understand V + E complexity.
- Detect cycles properly.
- Identify connected components.
- Choose BFS vs DFS intentionally.

---

## 🚀 After Mastering Day 7

- They can solve:
- Number of islands
- Clone graph
- Connected components
- Cycle detection
- Shortest path (unweighted)
- Multi-source BFS
- Flood fill
- Word ladder (foundation)