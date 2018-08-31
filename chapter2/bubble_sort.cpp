#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<int> &A){
    int lastUnsorted = A.size()-1;
    bool isSorted = false;

    while(!isSorted){
        isSorted = true;
        for(int i=0; i<lastUnsorted; i++){
            if(A[i] > A[i+1]){
                swap(A[i], A[i+1]);
                isSorted = false;
            }
        }
        lastUnsorted--;
    }
}

int main(){
    vector<int> A = {5,3,6,2,1,4,9,8,0};
    bubble_sort(A);

    cout << "After Sorting..." << endl;
    
    for(auto a : A){
        cout << a << " ";
    }
}
