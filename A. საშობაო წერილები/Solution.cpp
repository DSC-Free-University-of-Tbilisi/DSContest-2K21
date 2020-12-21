#include <iostream>
using namespace std;

int ansA, ansB;
int arrA[26], arrB[26];

int main(){
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '?'){
            ansA++;
        } else {
            arrA[a[i] - 'a']++;
        }
        if(b[i] == '?'){
            ansB++;
        } else {
            arrB[b[i] - 'a']++;
        }
    }


    for(int i = 0; i < 26; i++){
        if(arrA[i] == arrB[i]){
            continue;
        }

        if(arrA[i] < arrB[i]){
            ansA -= arrB[i] - arrA[i];
        } else {
            ansB -= arrA[i] - arrB[i];
        }
    }

    if(ansA < 0 || ansB < 0){
        cout << "no" << endl;
    } else {
        cout << "yes" << endl;
    }
    return 0;
}