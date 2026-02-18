## Binary Search Visualization

```mermaid
graph LR
A[Start 0-9] --> B[Mid=4]
B -->|Target < mid| C[Search 0-3]
B -->|Target > mid| D[Search 5-9]
```