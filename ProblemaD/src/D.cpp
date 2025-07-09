#include <cstdint>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t T_est;
    while (std::cin >> T_est && T_est != 0) {
        uint32_t low = 1, high = T_est;
        uint32_t answer = 0;
        int aciertos = 0;
        std::string resp;

        while (low <= high) {
            uint32_t mid = low + (high - low) / 2;

            // Ajustamos la consulta para compensar los "SI" anteriores:
            uint64_t consulta = uint64_t(mid) << aciertos;

            std::cout << "? " << consulta << std::endl;
            std::cin >> resp;

            if (resp == "SI") {
                answer = mid;
                ++aciertos;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        std::cout << "=> " << answer << std::endl;
    }
    return 0;
}

