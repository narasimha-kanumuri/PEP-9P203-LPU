# 📅 DAY 7 — GRAPHS I

## Traversal, Connectivity & Exploration Patterns

- Aligned with:
- * 20-Day Curriculum (Graph Foundations)
- * 9-Day Accelerated Structure — Graphs I
- * Master Engine invariant philosophy

---

# 🎯 DAY 7 OBJECTIVE

- Move from:
- > “Trees with one parent”
- To:
- > “General networks with arbitrary connections.”
- Today is about:
- * Graph modeling
- * BFS and DFS mastery
- * Component detection
- * Cycle detection
- * Visited invariant
- * Grid → graph transformation

---

# 🧠 1️⃣ What Is a Graph? (Zero Knowledge Entry)

- A graph is a structure made of:
- * **Vertices (Nodes)**
- * **Edges (Connections between nodes)**



- Unlike trees:
- * Graphs may contain cycles.
- * Nodes may have multiple parents.
- * Graph may be disconnected.

---

## Types of Graphs

### 1️⃣ Undirected Graph
- Edge (A—B) means: A connects to B AND B connects to A.

### 2️⃣ Directed Graph
- Edge (A → B) means: A connects to B only.

### 3️⃣ Weighted Graph
- Edges have cost/weight.

### 4️⃣ Unweighted Graph
- Edges have no cost.

[Image comparing undirected, directed, and weighted graphs]

---

# 🧠 2️⃣ Memory Representation

## 🔹 Adjacency List (Most Common)



```cpp {lineNumbers:true}
vector<vector<int>> adj(n);
```

- **Meaning:** For each node, store list of neighbors.
- **Space:** $O(V + E)$

---

## 🔹 Adjacency Matrix



```cpp {lineNumbers:true}
vector<vector<int>> matrix(n, vector<int>(n));
```

- **Space:** $O(V^2)$
- **Used when:** Graph is dense.

---

# 🧠 3️⃣ Core Invariant #1 — Visited Prevents Infinite Loops

- Graphs can have cycles. If you don't track visited: **You loop forever.**
- **Invariant:**
- > Once a node is visited, never process it again.

```cpp {lineNumbers:true}
vector<bool> visited(n, false);
```

- This invariant powers:
- * BFS & DFS
- * Connected components
- * Cycle detection

---

# 🧠 4️⃣ Breadth-First Search (BFS)

## ELI5
- Explore neighbors layer by layer.
- Like spreading water outward or a ripple in a pond.



---

## BFS Algorithm

```cpp {lineNumbers:true}
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

- **BFS Guarantee:** In an unweighted graph, the first time you reach a node is the **shortest path**.

---

# 🧠 5️⃣ Depth-First Search (DFS)

## ELI5
- Go as deep as possible before backtracking.
- Like exploring a maze by following one path until you hit a dead end.



---

## Recursive DFS

```cpp {lineNumbers:true}
void dfs(int node) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
```

- **Characteristics:** Explores full branches; good for components, cycle detection, and island counting.

---

# 🧠 6️⃣ Connected Components

- If a graph is disconnected, we must start BFS/DFS from every unvisited node.



```cpp {lineNumbers:true}
int components = 0;
for (int i = 0; i < n; i++) {
    if (!visited[i]) {
        dfs(i);
        components++;
    }
}
```

- **Invariant:** Each DFS/BFS traversal marks exactly one component.
- **Time:** $O(V + E)$

---

# 🧠 7️⃣ Cycle Detection (Undirected Graph)

### Key Insight
- If during DFS, you visit a neighbor that is **already visited** and is **NOT the parent** of the current node → A cycle exists.

[Image illustrating cycle detection in an undirected graph using DFS]

```cpp {lineNumbers:true}
bool dfs(int node, int parent) {
    visited[node] = true;
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node)) return true;
        }
        else if (neighbor != parent) return true;
    }
    return false;
}
```

---

# 🧠 8️⃣ Number of Islands (Grid → Graph)

- Given a grid of 0s and 1s, each cell is a node.
- **Edges:** Up, Down, Left, Right (only between 1s).

[Image showing grid to graph transformation for number of islands problem]

- **Algorithm:**
- 1. Traverse grid.
- 2. If `cell == 1` and `!visited`:
-    * Run DFS/BFS to mark all connected 1s.
-    * Increment island count.
- **Time:** $O(Rows \times Cols)$

---

# 🧠 9️⃣ Clone Graph

- **Problem:** Create a deep copy of a graph with cycles.
- **Approach:** Use a `HashMap<Node*, Node*>` to map original nodes to their clones.
- **Invariant:** Each original node must map to exactly one clone to avoid infinite recursion.

---

# 🧠 🔟 BFS vs DFS Comparison

| Feature | BFS | DFS |
| :--- | :--- | :--- |
| **Data Structure** | Queue | Stack / Recursion |
| **Shortest Path** | Yes (Unweighted) | No |
| **Space Usage** | $O(V)$ (Width) | $O(H)$ (Depth) |
| **Use Case** | Level order / Shortest | Deep exploration / Paths |

---

# 🧠 1️⃣1️⃣ Complexity Understanding

- **Time:** $T(V, E) = V + E$
- * Each node visited once ($V$).
- * Each edge explored once ($E$).

- **Space:**
- * Visited array: $O(V)$
- * BFS Queue: $O(V)$
- * DFS Stack: $O(H)$

---

# 🧠 1️⃣2️⃣ Core Invariants for Day 7

- 1️⃣ **Visited** prevents reprocessing and infinite loops.
- 2️⃣ **BFS** guarantees shortest path in unweighted graphs.
- 3️⃣ **DFS** explores the entire connected component.
- 4️⃣ **Parent tracking** is required for undirected cycle detection.
- 5️⃣ **Grid problems** are just graph problems on a structured lattice.

---

# ⚠️ Common Beginner Mistakes

- ❌ Forgetting the `visited` array.
- ❌ Marking `visited` **after** popping (should mark immediately when pushing/calling).
- ❌ Mixing directed vs undirected cycle logic.
- ❌ Forgetting the parent check in undirected cycles.
- ❌ Not resetting `visited` for multi-test cases.

---

# 🧠 Mental Shift After Day 7

- Students must now:
- * Convert abstract problems into graph models.
- * Recognize grids as implicit graphs.
- * Understand the $V + E$ complexity logic.
- * Detect cycles and components systematically.
- * Choose BFS vs DFS intentionally based on the goal.

---

- Would you like me to generate:
- * Day 8 (Shortest Path + Topological Sort)?
- * 10 invariant drills for Graphs?
- * A common Graph bug-fixing sheet?
- **Tell me the format.**