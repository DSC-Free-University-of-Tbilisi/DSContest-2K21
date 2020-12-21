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

void solve(){
    int n;
    cin>>n;
    vector<string> dict(n);
    for(int i = 0 ; i < n ; i++){
        cin>>dict[i];
    }
    string s;
    cin>>s;
    vector<int> dp(s.size() + 1, 0);
    dp[s.size()] = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        for(auto w: dict){
            if(i + w.size() > s.size()) continue;
            if(w == s.substr(i, w.size()) &&  dp[i + w.size()]) dp[i] = 1;
        }
    }
    cout<<(dp[0]? "True": "False") << endl;
}
 
int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    solve();
}