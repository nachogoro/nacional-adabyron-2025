#include <iostream>

int main() {
	int casos;
	std::cin >> casos;

	for (int i = 0; i < casos; ++i) {
		int chicas, amigos, amigas;
		std::cin >> chicas >> amigos >> amigas;

		int chicos = chicas * amigos / amigas;

		if (chicos * amigas == chicas * amigos) {
			std::cout << chicos << "\n";
		} else {
			std::cout << "IMPOSIBLE\n";
		}
	}
}
