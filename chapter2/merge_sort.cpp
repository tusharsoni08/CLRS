#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void merge(vector<int> &A, int p, int q, int r){
    vector<int> left;
    for(int i=p; i <= q; i++){
        left.push_back(A[i]);
    }

    vector<int> right;
    for(int i=q+1; i <= r; i++){
        right.push_back(A[i]);
    }

    int i = 0;
    int j = 0;

    for(int k=p; k <=r; k++){
        if((j >= right.size()) || ((i < left.size()) && left[i] < right[j])){
            A[k] = left[i];
            i++;
        }else{
            A[k] = right[j];
            j++;
        }
    }
}

void merge_sort(vector<int> &A, int p, int r){
    if(p < r){
        int q = floor((p+r)/2);
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(){
    vector<int> A = {5,3,6,2,1,4,9,8,0};
    merge_sort(A, 0, A.size()-1);

    cout << "After Sorting..." << endl;
    
    for(auto a : A){
        cout << a << " ";
    }
}
