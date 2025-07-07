#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <algorithm>

constexpr int64_t INF = std::numeric_limits<int64_t>::max();

int main() {
	while (true) {
		int64_t nSizes;
		std::cin >> nSizes;

		if (nSizes == 0) break;

		std::vector<int64_t> sizes(nSizes);

		for (int64_t i = 0; i < nSizes; ++i) {
			std::cin >> sizes[i];
		}

		std::sort(begin(sizes), end(sizes));
		int64_t minBox = sizes[0];

		// Table containing the first crossed-out element for each column
		std::vector<int64_t> table(minBox, INF);

		// Next element to cross
		std::queue<int64_t> to_cross;
		for (auto box : sizes) {
			to_cross.push(box);
		}

		while (!to_cross.empty())
		{
			auto crossed = to_cross.front();
			to_cross.pop();
			auto column = crossed % minBox;

			if (table[column] <= crossed) {
				// The element is already crossed
				continue;
			}

			table[column] = crossed;

			for (int iBox = 1; iBox < nSizes; ++iBox) {
				to_cross.push(crossed + sizes[iBox]);
			}
		}

		auto maxDistance = *std::max_element(begin(table), end(table));

		if (maxDistance == INF)
			std::cout << "INFINITO\n";
		else
			std::cout << maxDistance - minBox << "\n";
	}
}
