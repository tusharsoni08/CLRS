#include<iostream>
#include<vector>

using namespace std;

void insertion_sort(vector<int> &A){
    int n = A.size();
    for(int i=1; i < n; i++){
        int key = A[i];
        int j = i-1;
        while(j >= 0  && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    vector<int> A = {5,3,6,2,1,4,9,8,0};
    insertion_sort(A);

    cout << "After Sorting..." << endl;
    
    for(auto a : A){
        cout << a << " ";
    }
}
