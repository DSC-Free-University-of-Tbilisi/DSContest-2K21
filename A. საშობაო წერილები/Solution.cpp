#include <iostream>
using namespace std;


int main(){
    int arrA[26];
    int arrB[26];
    string a, b;
    int ansA, ansB;
    ansA = 0;
    ansB = 0;
 
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