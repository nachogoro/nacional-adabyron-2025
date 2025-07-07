#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct vector2d {
    T x, y;
    vector2d() {}
    vector2d(T x, T y): x(x), y(y) {}

    vector2d<T>& operator+=(const vector2d<T> &t) {
        x += t.x, y += t.y;
        return *this;
    }

    vector2d<T>& operator-=(const vector2d<T> &t) {
        x -= t.x, y -= t.y;
        return *this;
    }
    
    vector2d<T>& operator*=(const T &t) {
        x *= t, y *= t;
        return *this;
    }

    vector2d<T>& operator/=(const T &t) {
        x /= t, y /= t;
        return *this;
    }

    vector2d<T> operator+(const vector2d<T> &t) {
        return vector2d<T>(*this) += t;
    }

    vector2d<T> operator-(const vector2d<T> &t) {
        return vector2d<T>(*this) -= t;
    }

    vector2d<T> operator*(const T &t) {
        return vector2d<T>(*this) *= t;
    }

    vector2d<T> operator/(const T &t) {
        return vector2d<T>(*this) /= t;
    }

    bool operator==(const vector2d<T> &t) const {
        return x == t.x && y == t.y;
    }
};

template <typename T>
vector2d<T> operator*(T t, vector2d<T> v) {
    return v * t;
}

template <typename T>
T dot(vector2d<T> a, vector2d<T> b) {
    return a.x * b.x + a.y * b.y;
}

template <typename T>
T orientation(vector2d<T> a, vector2d<T> b, vector2d<T> c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

int test(int n, vector2d<double> start, vector2d<double> end, vector2d<double> vertices[]) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        vector2d<double> v0 = vertices[i];
        vector2d<double> v1 = vertices[(i + 1) % n];
        vector2d<double> diff_v = v1 - v0;
        vector2d<double> end_relative = end - v0;                                                // vector del punto final respecto de v0
        vector2d<double> projection = diff_v * dot(diff_v, end_relative) / dot(diff_v, diff_v);  // proyección del vector end_relative sobre el vector diff_v
        vector2d<double> end_mirror = v0 + (projection * 2 - end_relative);                      // reflexión del punto de destino respecto del segmento
        if (orientation(start, v0, end_mirror) > 0 && orientation(start, v1, end_mirror) < 0)    // comprobamos si el punto de intersección se encuentra dentro del segmento
            res++;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector2d<double> start, end, vertices[n];
        cin >> start.x >> start.y;
        cin >> end.x >> end.y;
        for (int i = 0; i < n; i++)
            cin >> vertices[i].x >> vertices[i].y;
        cout << test(n, start, end, vertices) << endl;
    }
    return 0;
}
