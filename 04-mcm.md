# 📘 Matrix Chain Multiplication (MCM) — Detailed Notes

Matrix Chain Multiplication (MCM) is a **Dynamic Programming** optimization problem that determines the **most efficient way** to multiply a sequence of matrices.

Matrix multiplication is **associative**, meaning:


(A × B) × C = A × (B × C)

Even though the result is the same, the **number of scalar multiplications** required varies based on the parenthesization.

---

## 🎯 Goal of MCM

To find the **order of parenthesis** such that the **total number of multiplications** is **minimum**.

Example:

For matrices A(10×20), B(20×30), C(30×40), D(40×50)

There are many ways to parenthesize:

- ((AB)C)D
- (A(BC))D
- (AB)(CD)
- A((BC)D)
- A(B(CD))

All produce same result  
But **computational cost differs** significantly.

---

## 📌 Understanding the Input

Given an array `p[]` storing **dimensions**:

For `n` matrices → `p` contains `n+1` values:

Matrix | Dimensions
------ | ----------
A₁     | p[0] × p[1]
A₂     | p[1] × p[2]
A₃     | p[2] × p[3]
⋮      | ⋮

Example:

p = {10, 20, 30, 40, 50}

So matrices are:
- A₁: 10×20
- A₂: 20×30
- A₃: 30×40
- A₄: 40×50

---

## 📊 DP Matrices Used

We use **two tables**:

| Table | Meaning |
|-------|---------|
| **M** | Stores minimum cost of multiplying Ai..Aj |
| **S** | Stores optimal split point `k` |

### Initialization Rule

- Diagonal elements → cost = 0  
  (Single matrix multiplication has zero cost)
- Others initialized to **infinity** (INF)

This structure forms an **upper triangular matrix**.

---

## 🔍 Key Concept — Chain Length (diff)

`diff = j - i` represents:

| diff | Meaning |
|------|---------|
| 0 | Single matrix |
| 1 | Chain of 2 matrices |
| 2 | Chain of 3 matrices |
| ... | ... |

We gradually consider **larger** subproblems:

Example for n = 4 matrices:

diff = 1 → pairs:
- A₁A₂
- A₂A₃
- A₃A₄

diff = 2 → triplets:
- A₁A₂A₃
- A₂A₃A₄

That’s why:

i ranges from 0 to n - diff - 1
j = i + diff

---

## 🧠 Recurrence / Cost Calculation

For each possible split `k`:

Cost = M[i][k] + M[k+1][j] + (p[i] * p[k+1] * p[j+1])

We choose:

Minimum cost → store in M[i][j]
Split position → store in S[i][j]


---

## 🔁 Optimal Parenthesization (Using S Table)

We use recursion:

### Base Condition
If `i == j` → only one matrix:
Print Ai

### Otherwise
Print "("
Solve left part : i to S[i][j]
Solve right part : S[i][j] + 1 to j
Print ")"

📌 This is a **top-down** reconstruction of optimal solution.

---

## 🧩 Example Output Meaning

### M Table (Cost Table)

Shows minimum multiplications for every sub-chain:

- Bottom left ignored (not possible chains)
- Result for full multiplication → `M[0][n-1]`

### S Table (Split Table)

Stores the best `k` where the multiplication should be split.

Example:
S[0][3] = 1 → Split A₁..A₄ into:
(A₁A₂) & (A₃A₄)

---

## 🏁 Final Output Summary

| Output | Meaning |
|--------|---------|
| M Table | Minimum multiplication costs |
| S Table | Optimal split points |
| M[0][n-1] | Minimum multiplication cost |
| Parenthesization | Best multiplication sequence |

---

## ✔ What MCM Solves

It minimizes **computation time** in:
- Graphics pipelines
- Scientific computations
- Linear algebra solvers
- Compiler optimization for matrix-intensive programs

---

---

## Time & Space Complexity

| Metric | Complexity |
|--------|------------|
| Time | `O(n³)` → Triple loop |
| Space | `O(n²)` → M and S storing |

---

## 🔑 Key Takeaways

✔ MCM uses **Dynamic Programming**  
✔ Build solution using **bottom-up table filling**  
✔ Parenthesization reconstructed using **S table**  
✔ Reduces computational complexity significantly  
✔ Focuses on **order**, not result, of multiplication
