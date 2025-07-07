#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

bool es_posible(const std::vector<int>& v, int k, double media) {
	int n = v.size();
	// Suma prefijo restando a cada elemento original media
	std::vector<double> prefix(n + 1, 0.0);

	for (int i = 0; i < n; ++i) {
		prefix[i + 1] = prefix[i] + (v[i] - media);
	}

	double min_prefix = 0.0;
	for (int i = k; i <= n; ++i) {
		if (prefix[i] - min_prefix >= 0.0)
			return true;
		min_prefix = std::min(min_prefix, prefix[i - k + 1]);
	}

	return false;
}

double max_avg_binary_search(const std::vector<int>& v, int k) {
	double low = *std::min_element(begin(v), end(v));
	double high = *std::max_element(begin(v), end(v));
	double eps = 1e-5;

	while (high - low > eps) {
		double mid = (low + high) / 2.0;
		if (es_posible(v, k, mid))
			low = mid;
		else
			high = mid;
	}

	return low;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (true) {
		int n, k;
		std::cin >> n >> k;
		if (n == 0 && k == 0) break;

		std::vector<int> v(n);
		for (int& x : v) std::cin >> x;

		double resultado = max_avg_binary_search(v, k);
		std::cout << std::fixed << std::setprecision(5) << resultado << '\n';
	}

	return 0;
}

