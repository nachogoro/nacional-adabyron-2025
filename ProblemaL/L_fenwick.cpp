#include <bits/stdc++.h>
using namespace std;

class fenwick_tree {
private:
    vector<int> bit;

public:
    /**
     * Inicializa un árbol de fenwick sobre un array con ceros.
     * @param size Tamaño del array.
     */
    fenwick_tree(size_t size): bit(size) {}

    size_t size() const {
        return bit.size();
    }

    /**
     * Realiza una consulta de rango con un coste asintótico de O(log n).
     * @param r Un índice del array, entre 0 (inclusive) y el tamaño del array (no inclusive).
     * @return La suma de los elementos del array en el rango [0, r] (inclusive).
     */
    int query(int r) {
        int sum = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            sum += bit[r];
        return sum;
    }

    /**
     * Actualiza el array sumando un incremento en una posición del array, en O(log n).
     * @param index Posición del array en el que se quiere realizar el incremento.
     * @param delta Candad que se quiere sumar en la i-ésima posición del array.
     */
    void update(int index, int delta) {
        for (; index < size(); index = index | (index + 1))
            bit[index] += delta;
    }
};

/**
 * Realiza compresión de coordenadas sobre un array de tamaño n, preservando el orden relativo de sus elementos.
 * @param array Puntero al primer elemento del array.
 * @param size Tamaño del array.
 * @return Valor máximo del array tras aplicar la compresión, que es igual al número de elementos diferentes del mismo.
 */
int coordinate_compression(int array[], size_t size) {
    vector<pair<int, int>> elements(size);
    for (int i = 0; i < size; i++)
        elements[i] = make_pair(array[i], i);
    sort(elements.begin(), elements.end());                             // ordenamos los pares de valores por orden no decreciente del valor de a[i]
    int current_index = 1;                                              // contador de elementos diferentes encontrados hasta ahora
    for (int i = 0; i < size; i++) {                                    // iteramos sobre el array por orden no decreciente del array
        array[elements[i].second] = current_index;                      // asignamos el valor del contador al array
        if (i + 1 < size && elements[i].first < elements[i+1].first)    // si hay dos elementos consecutivos distintos, incrementamos el contador
            current_index++;
    }
    return current_index;  // número de elementos distintos en el array
}

int test(int numero_noches, int horas_llegada[]) {
    int max_element = coordinate_compression(horas_llegada, numero_noches);  // aplicamos compresión de coordenadas sobre el array
    fenwick_tree ft(max_element + 1);  // construimos un árbol de Fenwick sobre un array con (max_element + 1) ceros
    int result = 0;
    for (int d = 0; d < numero_noches; d++) {
        // Si el número de noches anteriores a las que hemos llegado antes que la hora de llegada del día d
        // es mayor o igual a la mitad de noches anteriores (d / 2.0), sumamos uno al resultado.
        if (d <= 2 * ft.query(horas_llegada[d] - 1))
            result++;
        ft.update(horas_llegada[d], 1);  // añadimos 1 al i-ésimo elemento del array asociado al árbol de Fenwick
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int numero_noches;
        scanf("%d", &numero_noches);
        int horas_llegada[numero_noches];
        for (int i = 0; i < numero_noches; i++)
            scanf("%d", horas_llegada + i);
        printf("%d\n", test(numero_noches, horas_llegada));
    }
    return 0;
}
