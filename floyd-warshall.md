# Floyd–Warshall Algorithm — Dynamic Programming Explanation

The Floyd–Warshall algorithm is used to compute the **shortest path between all pairs of nodes** in a graph.

✔ Supports directed & weighted graphs  
✔ Handles negative edge weights  
✔ Detects negative cycles  
✔ Final result is a complete shortest distance matrix  

---

## Understanding the Problem

We are given:

- `n` nodes labeled from **0 to n−1**
- A list of directed edges: `(u, v, w)`
  → meaning: path from `u` to `v` with cost `w`

The goal is:

> Find the minimum distance from every node `i` to every node `j`.

This type of DP problem is known as **All-Pairs Shortest Path (APSP)**.

---

## 0-Based Indexing — Why?

The algorithm uses 0-based indexing because:

- No wasted matrix space  
- Direct mapping to programming array indexing  
- Cleaner implementation: nodes → `0 to n-1`

| Indexing | Matrix Size | Unused Space | Node Labels |
|---------|-------------|-------------|-------------|
| 1-based | (n+1) × (n+1) | Yes (0th row/col unused) | 1 to n |
| 0-based | n × n | No | 0 to n-1 |

---

## Step 1 — Create Initial Matrix `D0`

### Initialization Rules:

| Condition | Set Value |
|----------|-----------|
| i == j | `0` (distance to itself) |
| Edge exists (u, v, w) | `w` |
| No direct edge | `INF` (large constant) |

Thus, we first fill the diagonal with `0`, and other cells with `INF`.  
Then insert actual edge weights into the matrix.

This matrix is called **D₀** — the starting point before running DP.

---

## Step 2 — Dynamic Programming Transition

We try improving distances by checking for an **intermediate node `k`**:

### Recurrence Relation:

D[i][j] = min(D[i][j], D[i][k] + D[k][j])


Meaning:

> If going through `k` gives a shorter path from `i` to `j`, update it.

We repeat this process for every `(i, j)` pair for each intermediate `k`.

This is the core logic of Floyd–Warshall.

---

## Iterative Steps

- First: Direct distances → stored in `D0`
- Then: Allow paths using node `0` → update matrix
- Next: Allow paths using node `1`
- Continue until `k = n-1`

After processing all `k` values → Matrix contains **shortest distances** between every pair of nodes.

---

## Output

Finally, the program prints:

1️⃣ **Initial Distance Matrix (`D0`)**  
2️⃣ **Final APSP Matrix** after Floyd–Warshall

If a value remains `INF`, it means there is **no path** between those nodes.

---

## Time & Space Complexity

| Metric | Complexity |
|--------|------------|
| Time | `O(n³)` → triple nested loop |
| Space | `O(n²)` → adjacency matrix storage |

---

## Key Takeaways

- A powerful DP method for **all-pairs** shortest path
- Supports negative weights
- Final matrix gives complete connectivity info
- Simpler implementation compared to Dijkstra for APSP
