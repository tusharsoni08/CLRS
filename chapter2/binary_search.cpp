#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

// recusive version
bool binary_search(vector<int> &A, int num, int p, int r){
    if(p <= r){
        int q = floor((p+r)/2);
        if(A[q] == num){
            return true;
        } else if(A[q] < num){
            return binary_search(A, num, q+1, r);
        } else {
            return binary_search(A, num, p, q-1);
        }
    }

    return false;
}

int main(){
    vector<int> A = {1,2,3,4,5,6,7,8,9};

    cout << "List -> ";
    
    for(auto a : A){
        cout << a << " ";
    }

    cout << endl;

    int num;
    cout << "Enter a number to search: ";
    cin >> num;

    if(binary_search(A, num, 0, A.size()-1)){
        cout << num << " is there" << endl;
    } else {
        cout << "Not Found!" << endl;
    }
}
