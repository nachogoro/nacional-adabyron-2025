#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <algorithm>

constexpr int64_t INF = std::numeric_limits<int64_t>::max();

class Graph {
	public:
		Graph(int64_t size) : adj(size) { }

		void addEdge(int64_t src, int64_t dst, int64_t weight) {
			adj[src].push_back({dst, weight});
		};

		std::vector<int64_t> dijkstra(int64_t src) {
			std::priority_queue<std::pair<int64_t, int64_t>> q;
			std::vector<int64_t> distance(adj.size(), INF);
			std::vector<bool> processed(adj.size(), false);

			distance[src] = 0;
			q.push({0, src});


			while (!q.empty()) {
				int64_t currentNode = q.top().second;
				q.pop();

				if (processed[currentNode])
					continue;

				processed[currentNode] = true;

				for (auto edge : adj[currentNode]) {
					int64_t neighbour = edge.first;
					int64_t w = edge.second;
					if (distance[currentNode]+w < distance[neighbour]) {
						distance[neighbour] = distance[currentNode]+w;
						q.push({-distance[neighbour], neighbour});
					}
				}
			}

			return distance;
		}

	private:
		std::vector<std::vector<std::pair<int64_t, int64_t>>> adj;
};

int main() {
	while (true) {
		int64_t nSizes;
		std::cin >> nSizes;

		if (nSizes == 0) break;

		std::vector<int64_t> sizes(nSizes);

		for (int64_t i = 0; i < nSizes; ++i) {
			std::cin >> sizes[i];
		}

		int64_t minBox = sizes[0];
		Graph g(minBox);

		for (auto box : sizes) {
			for (int64_t residue = 0; residue < minBox; ++residue) {
				g.addEdge(residue, (residue + box) % minBox, box);
			}
		}

		auto distances = g.dijkstra(0);

		auto maxDistance = *std::max_element(begin(distances), end(distances));

		if (maxDistance == INF)
			std::cout << "INFINITO\n";
		else
			std::cout << maxDistance - minBox << "\n";
	}
}
