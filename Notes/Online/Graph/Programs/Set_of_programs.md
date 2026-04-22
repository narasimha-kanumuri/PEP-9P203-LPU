<!--
Based on the notes so far, from the file "Notes/Online/Graph/Notes/001.Notes.md", we can create a new file "Notes/Online/Graph/Programs/Set_of_programs.md" that contains a set of programs related to graph theory. This new file will include various algorithms and implementations for graph-related problems, such as depth-first search, breadth-first search and more. Each program will be accompanied by explanations and examples to help understand the concepts better.
COncept wise programs, the hard condition being every standard program must have a twist included in both question(story), constraint, test case so it feels new for learning and practicing. 
The twist can be in the form of a unique story, an addition to standard questions, an unusual constraint, or a test case that challenges the standard approach to solving the problem. This will not only make the learning process more engaging but also help in developing problem-solving skills by encouraging thinking outside the box.

Each question just three lines, with a twist mentioned in the last line. The twist should be unique and not commonly found in standard graph problems, making it a fresh challenge for learners. Detailed question i will take up in each file
-->

# Set of Programs

## 1. Depth-First Search (DFS) with a Twist

### Question

Given a graph, perform a depth-first search starting from a given node. However, the twist is that you must visit the nodes in a specific order based on a custom priority function provided for each node.

**Twist:**
The priority function will determine the order of node visits, and it may change dynamically based on certain conditions during the traversal. For example, if a node has been visited more than once, its priority may decrease, affecting the order of subsequent visits.

## 2. Breadth-First Search (BFS) with a Twist

### Question

Given a graph, perform a breadth-first search starting from a given node. The twist is that you must also keep track of the distance from the starting node to each visited node, and if the distance exceeds a certain threshold, you must skip visiting that node.

**Twist:**
The threshold for skipping nodes can change dynamically based on the number of nodes visited so far. For example, after visiting a certain number of nodes, the threshold may decrease, making it more challenging to visit distant nodes as the traversal progresses.

## 3. Dijkstra's Algorithm with a Twist