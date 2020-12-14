// Time limit per test  -   2 seconds
// Memory limit per test    -   512 megabytes
// Required Knowledge   -   Graph Theory, Minimum Spanning Tree, Prim's algorithm
// Time Complexity  -   O(ELogV)
// Editorialist -  dkhos17@freeuni.edu.ge

/* Approach -   The question simply asks to calculate the weight of the MST of the input graph.
It can be easily realized that if the total wieght is to be minimized, the MST is to be found.
The code uses the STL Set implementation to make the runtime complexity as O(ELogV),
where E = nm(n+m) and V = nm, which can also be acheived using heaps. STL however ensures a more neat implementation.*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define Pq priority_queue
#define u_set unordered_set
#define MOD_ 1000000007
#define MAXN 100001
#define ioos ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define swap(a,b) a = a^b;b = a^b;a = a^b;
#define set_val(arr,v) memset(arr, v, sizeof(arr))
#define scanT(t) for(scanf("%d",&t); t; t--)
#define print(result) printf("%d\n", result)
#define scan(n) scanf("%d", &n)
#define scanP(x,y) scanf("%d %d", &x, &y)
#define scanPL(x,y) scanf("%lld %lld", &x, &y)
#define sort(vec) sort(vec.begin(), vec.end())
#define DFP(i, n) for (int i=0; i<n; i++)
#define DFM(i, n) for (int i=n-1; i>=0; i--)
#define point pair<int, int>
#define Edge pair < int, pair< pair<int, int>, pair<int, int> > >
#define F first
#define S second


multiset<int> rows[MAXN], cols[MAXN];
map<int, set<int> > idX[MAXN], idY[MAXN];
set< point > been;

bool edge_cmp(auto min, auto tmp){
    if(tmp.F == 1)return false;
    return min.F < tmp.F;
}

int getX(int val, int y, int x){
    for(int x0 : idY[y][val]){
        if(x0 == x) continue;
        return x0;
    }
    return -1;
}

int getY(int val, int x, int y){
    for(int y0 : idX[x][val]){
        if(y0 == y) continue;
        return y0;
    }
    return -1;
}

Edge getXmin(int x, int y, int V){
    auto it = rows[x].lower_bound(V);
    int y0 = -1;
    int res = INT_MAX;
    if(it != rows[x].end()){
        y0 = getY(*it, x, y);
        res = abs(*it-V);  
    }

    if(it != rows[x].begin()){
        int r = abs(*(--it)-V);
        if(r < res){
            res = r;
            y0 = getY(*it, x, y);
        }
    }
    
    if(y0 == -1) res = -1;
    return mp(-res, mp(mp(x,y), mp(x, y0)));
}

Edge getYmin(int x, int y, int V){
    auto it = cols[y].lower_bound(V);
    int x0 = -1;
    int res = INT_MAX;
    if(it != cols[y].end()){
        x0 = getX(*it, y, x);
        res = abs(*it-V);
    }

    if(it != cols[y].begin()){
        int r = abs(*(--it) - V);
        if(r < res){
            res = r;
            x0 = getX(*it, y, x);
        }
    }

    if(x0 == -1) res = -1;
    return mp(-res, mp(mp(x,y), mp(x0, y)));
}


void coutEdge(Edge min){
    cout << min.F << " " << min.S.F.F << " " <<
         min.S.F.S << " " << min.S.S.F << " " << min.S.S.S << endl;
}


Edge getMin(int x, int y, int V) {
    Edge minX = getXmin(x, y, V);
    Edge minY = getYmin(x, y, V);
    if(minX.F != 1 && minY.F != 1){
        return minX.F > minY.F ? minX : minY;
    }
    if(minX.F == 1)return minY;
    return minX;
}

pair<int, pair<int, int>> firstMin(int n, int m){
    int res = INT_MAX;
    int x = -1, y = -1;
    DFP(i,n){
        int prev = INT_MAX;
        if(res == 0)break;
        for(int e : rows[i]){
            if(prev == INT_MAX){
                prev = e;
                continue;
            }
            int tmp = abs(e - prev);
            if(tmp < res){
                x = i; y = getY(e, x, -1);
                res = tmp;
            }
            prev = e;
        }
    }
    DFP(j,m){
        int prev = INT_MAX;
        if(res == 0)break;
        for(int e : cols[j]){
            if(prev == INT_MAX){
                prev = e;
                continue;
            }
            int tmp = abs(e - prev);
            if(tmp < res){
                y = j; x = getX(e, y, -1);
                res = tmp;
            }
            prev = e;
        }
    }
    return mp(-res, mp(x,y));
}

int main() {
    int m,n; scanP(n,m);
    int gr[n][m];
    DFP(i,n){
        DFP(j,m){
            int val;
            scan(val);
            gr[i][j] = val;
            rows[i].insert(val);
            cols[j].insert(val);
            idX[i][val].insert(j);
            idY[j][val].insert(i);
        }
    }
    if(m == 1 && n == 1)return cout << 0, 0;
    pair<int ,pair<int, int> > p = firstMin(n,m);
    int t1 = p.S.F, t2 = p.S.S, val1 = gr[t1][t2];

    auto it1 = rows[t1].lower_bound(val1);
    rows[t1].erase(it1);
    
    auto it2 = cols[t2].lower_bound(val1);
    cols[t2].erase(it2);

    idX[t1][val1].erase(t2);
    idY[t2][val1].erase(t1);
    
    Edge min = getMin(p.S.F, p.S.S, val1);
    //coutEdge(min);
    
    int t3 = min.S.S.F, t4 = min.S.S.S, val2 = gr[t3][t4];
    it1 = rows[t3].lower_bound(val2);
    rows[t3].erase(it1);
    
    it2 = cols[t4].lower_bound(val2);
    cols[t4].erase(it2);
    
    idX[t3][val2].erase(t4);
    idY[t4][val2].erase(t3);

    ll mst = -min.F;
    been.insert(min.S.F);
    been.insert(min.S.S);

    Pq < pair < int, pair < point, point > > > Q;
    while(true){
        Edge min1 = getMin(min.S.F.F, min.S.F.S, gr[min.S.F.F][min.S.F.S]);
        if(min1.F <= 0) Q.push(min1);   
        
        Edge min2 = getMin(min.S.S.F, min.S.S.S, gr[min.S.S.F][min.S.S.S]);
        if(min2.F <= 0) Q.push(min2);   
        
        if(Q.empty() || been.size() == m*n)break;
        min = Q.top(); Q.pop();

        if(been.count(min.S.F) && been.count(min.S.S))continue;
        mst += -min.F;
        been.insert(min.S.F);
        been.insert(min.S.S);
        int x = min.S.S.F, y = min.S.S.S, val = gr[x][y];
        auto it1 = rows[x].lower_bound(val);
        auto it2 = cols[y].lower_bound(val);
        rows[x].erase(it1);
        cols[y].erase(it2);
        idX[x][val].erase(y);
        idY[y][val].erase(x);
        // coutEdge(min);
    }
    cout << mst << endl;
    return 0;    
}