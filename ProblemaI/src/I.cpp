#include <bits/stdc++.h>
using namespace std;

typedef double C;
typedef complex<C> P;
#define X real()
#define Y imag()

C cross(P u, P v){
    return (conj(u)*v).Y;
}

C cross (P a, P b, P c){
    return cross(b-a,c-b);
}

// Punto simétrico de c respecto de la recta formada por a y b
P simetrico(P a, P b, P c){
    C d = cross(a-c,a-b) / abs(b-a);
    P ab = b-a;
    P u = {-ab.Y,ab.X};
    return c + 2*d*(u/abs(u));
}

// devuelve el punto de colisión para el segmento ab 
// con puntos inicial y final
P colision(P a, P b, P i, P f){
    P ii = simetrico(a,b,i);
    P fa = a-f, fii = ii-f, ab = b-a;
    C l = cross(fii,fa) / cross(fii,-ab);
    return a + l*ab; 
}

// Si c está en el segmento de a a b (ya sabemos que c está en la recta)
bool onSegment(P a, P b, P c){
    return min(a.X,b.X) <= c.X && c.X <= max(a.X,b.X) &&
        min(a.Y,b.Y) <= c.Y && c.Y <= max(a.Y,b.Y);
}

int main(){
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        vector<P> polygon(n);
        P initial, final;
        C x, y;
        cin >> x >> y; initial = {x,y};
        cin >> x >> y; final = {x,y};
        for (auto &p : polygon){
            cin >> x >> y; p = {x,y};
        }
        int num = 0;
        for (int i = 0; i < n; i++){
            P p1 = polygon[i];
            P p2 = polygon[(i+1)%n];
            P c = colision(p1,p2,initial,final);
            if (onSegment(p1,p2,c)) num++;
        }
        cout << num << '\n';
    }
    return 0;
}