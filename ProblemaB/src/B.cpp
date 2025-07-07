#include <cstdint>
#include <iostream>
#include <vector>

constexpr int LIMITE = 10'000'000;

std::vector<int> eratostenes(int max) {
	std::vector<bool> es_primo(max + 1, true);
	es_primo[0] = es_primo[1] = false;
	for (int i = 2; i * i <= max; ++i) {
		if (es_primo[i]) {
			for (int j = i * i; j <= max; j += i) {
				es_primo[j] = false;
			}
		}
	}

	std::vector<int> primos;
	for (int i = 2; i <= max; ++i) {
		if (es_primo[i]) primos.push_back(i);
	}
	return primos;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> primos = eratostenes(LIMITE);

	uint64_t numero;
	while (std::cin >> numero && numero != 0) {
		const uint64_t mitad = numero / 2;

		int izq = 0, der = 1;
		uint64_t suma = primos[izq] + primos[der];
		bool encontrado = false;

		while (der < primos.size()) {
			if (suma < numero)
			{
				++der;
				if (der < primos.size())
					suma += primos[der];
			}
			else if (suma > numero)
			{
				suma -= primos[izq];
				++izq;

				if (izq == der)
				{
					// Hemos encogido la ventana hasta w=1, no habrá solución
					break;
				}
			} else {
				std::cout << primos[izq] << " " << primos[der] << "\n";
				encontrado = true;
				break;
			}

			// No puede haber suma de 2+ primos si el menor de ellos es mayor
			// que la mitad del número buscado
			if (primos[izq] > mitad)
				break;
		}

		if (!encontrado) {
			std::cout << "NO\n";
		}
	}
}
