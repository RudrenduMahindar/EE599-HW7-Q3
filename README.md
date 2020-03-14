# EE599-HW7-Q3
Given the following code for BFS:

void Graph::BFS(int root) {
std::map<int, int> marks;
std::queue<int> q;
q.push(root);
marks[root] = 1;
while (!q.empty()) {
int cur = q.front();

q.pop();
for (auto &n : edge_map_[cur]) {
if (!marks[n]) {
marks[n] = 1;
q.push(n);
}
}
}
}
1. Enhance it to calculate the shortest distance for each node. The output should be a map that maps each node to its distance. 2. Enhance it to find the actual shortest path from the root to each node. The output should be a map that maps each node to a vector that represents the shortest path.
