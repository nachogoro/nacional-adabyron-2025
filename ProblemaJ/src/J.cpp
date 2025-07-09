#include <bits/stdc++.h>
using namespace std;

typedef long double C;
typedef complex<C> P;
#define X real()
#define Y imag()

C cross(P u, P v){
    return (conj(u)*v).Y;
}

C cross(P a, P b, P c){
    return cross(b-a,c-b);
}

// devuelve el convex hull de un conjunto de puntos
// con sus vértices ordenados en sentido anti-horario
vector<P> convexHull(vector<P> &pp){
    sort(pp.begin(),pp.end(),[](const P &a, const P &b){
        if (a.X == b.X) return a.Y < b.Y;
        return a.X < b.X;
    }); 

    int n = pp.size(), k = 0;
    if (n == 1) return pp;
    
    vector<P>H(2*n);
    for (int i = 0; i < n; i++){
        while (k >= 2 && cross(H[k-2], H[k-1], pp[i]) <= 0) k--;
        H[k++] = pp[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--){
        while (k >= t && cross(H[k-2],H[k-1], pp[i]) <= 0) k--;
        H[k++] = pp[i];
    }
    H.resize(k-1);
    return H;
}

// comprueba si un punto está dentro de un polígono convexo
// dados sus puntos en orden anti-horario
bool insideConvexPolygon(vector<P> &polygon, P p){
    int n = polygon.size();
    
    // si el polígono es un único punto
    if (n == 1) return polygon[0] == p;
    
    // si el polígono es un segmento
    else if (n == 2){
        P a = polygon[0], b = polygon[1];
        return min(a.X,b.X) <= p.X && p.X <= max(a.X,b.X) &&
            min(a.Y,b.Y) <= p.Y && p.Y <= max(a.Y,b.Y) &&
            cross(a,b,p) == 0;
    }
    // reducir polígono a un triángulo
    int l = 1, r = n-1;
    while (r-l > 1){
        int mid = (r+l)/2;
        // p está a la izquierda
        if (cross(polygon[0],polygon[mid],p) >= 0)
            l = mid;
        else r = mid;
    }
    vector<P> t = {polygon[0],polygon[l],polygon[r]};
    
    // comprobar punto p dentro del triangulo
    for (int i = 0; i < 3; i++){
        if (cross(t[i],t[(i+1)%3],p) < 0)
            return false;
    }
    return true;
}

bool solve(){
    int N, Q; cin >> N >> Q;
    if (!N) return false;
    vector<C> a(N), m(N);
    for (auto &x : a) cin >> x;
    for (auto &x : m) cin >> x;

    vector<P> pp(N);
    for (int i = 0; i < N; i++)
        pp[i] = {a[i],m[i]};

    vector<P> H = convexHull(pp);

    while (Q--){
        C x, y;
        cin >> x >> y;
        P p = {x,y};
        cout << (insideConvexPolygon(H,p) ? "SI" : "NO") << '\n';
    }
    cout << "---\n";
    return true;
}

int main(){
    while (solve()) ;
    return 0;
}