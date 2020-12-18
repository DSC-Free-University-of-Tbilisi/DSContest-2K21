// Time limit per test  -   2 seconds
// Memory limit per test    -   512 megabytes
// Required Knowledge   -   Recursion
// Time Complexity  -  
// Editorialist -  dpipi17@freeuni.edu.ge

/* Approach -   it's a really simple problem if you read input as a string and check all numbers which can be received in k steps using recursion. From these numbers, you have to choose the minimum and the maximum values */

#include <bits/stdc++.h>
using namespace std;

const int MX = 5007;
const int  MOD = 1e9 + 7;

string maximum = "";
string minimum = "";

void getAnsws(string n, int chances, int position) {
    if(n > maximum) {
        maximum = n;
    }

    if(n < minimum) {
        minimum = n;
    }

    if(position > 0) {
        if(minimum != "99999999999" && maximum != "00000000000") {
            if(n[position - 1] > minimum[position - 1] && n[position - 1] < maximum[position - 1]) {
                return;
            }
        }
    }

    if(chances == 0) {
        return;
    }
    
    for(int i = position; i < n.size(); i++) {
        if(position != 0 || n[i] != '0') {
            if(i == position) {
                getAnsws(n, chances, position + 1);
            } else {
                swap(n[i], n[position]);
                getAnsws(n, chances - 1, position + 1);
                swap(n[i], n[position]);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    string n;
    cin >> n;
    int k;
    cin >> k;

    int length = n.size();
    maximum = n; minimum = n;
    getAnsws(n, min(length, k), 0);
    
    cout << minimum << " " << maximum << endl;

    return 0;
}
