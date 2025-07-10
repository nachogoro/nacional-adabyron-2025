#include <iostream>
#include <vector>
#include <queue>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {
		int N;
		std::cin >> N;

		// left.size() >= right.size()
		std::priority_queue<int> left;
		std::priority_queue<int, std::vector<int>, std::greater<int>> right;

		int cuenta = 0;

		for (int i = 0; i < N; ++i) {
			int actual;
			std::cin >> actual;

			// número par de noches anteriores
			// criterio: llegar más tarde que n/2 noches anteriores.
			// left contiene la mitad inferior de las n noches anteriores.
			// Es decir: actual > left.top()
			//
			// número impar de noches anteriores
			// criterio: llegar mas tarde que ceil(n/2) noches anteriores.
			// left contiene ceil(n/2) noches anteriores.
			// Es decir: actual > left.top() igualmente.
			if (left.empty() || actual > left.top()) {
				cuenta++;
			}

			if (left.empty() || actual <= left.top()) {
				left.push(actual);
			} else {
				right.push(actual);
			}

			// Rebalanceo
			if (left.size() > right.size() + 1) {
				right.push(left.top());
				left.pop();
			} else if (right.size() > left.size()) {
				left.push(right.top());
				right.pop();
			}
		}

		std::cout << cuenta << '\n';
	}
}

