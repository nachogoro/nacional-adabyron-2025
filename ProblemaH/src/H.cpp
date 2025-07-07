#include <iostream>
#include <vector>

int main() {
	int casos;
	std::cin >> casos;

	for (int c = 0; c < casos; ++c) {
		int cubiletes, intercambios;
		std::cin >> cubiletes >> intercambios;

		std::vector<int> estado(cubiletes);

		for (int i = 0; i < cubiletes; ++i) {
			estado[i] = i+1;
		}

		for (int s = 0; s < intercambios; ++s) {
			int src, dst;
			std::cin >> src >> dst;

			std::swap(estado[src-1], estado[dst-1]);
		}

		for (int i = 0; i < cubiletes; ++i) {
			std::cout << estado[i];
			if (i < cubiletes - 1)
				std::cout << " ";
			else
				std::cout << "\n";
		}
	}
}
