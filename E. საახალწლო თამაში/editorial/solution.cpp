#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define printVec(vec) for(int i$ = 0; i$ < vec.size() ; i$++){ if(i$ + 1 != vec.size())cout<<vec[i$]<<" "; else cout<<vec[i$]<<endl;}
#define S second
#define F first
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int N = 1e6 + 7;

string solve(){
    ll n, m , k;
    cin>>n>>m>>k;
    vector<ll> sizes(n), santa(n), rudolph(n);
    for(int i = 0 ; i < n ; i++){
        cin>>santa[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin>>rudolph[i];
    }
    for(int i = 0 ; i < n ; i++){
        sizes[i] = abs(santa[i] - rudolph[i]) % (k + 1);
    }
    vector<int> c(65, 0);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j <= 64; j++){
            c[j] += (sizes[i]>>j) & 1;
        }
    }
    for(int j = 0; j <= 64; j++){
        if(c[j] % (m + 1) ) {
            return "Santa";
        }
    }
    return "Rudolph";
}
 
int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    cout<< solve() <<endl;
}