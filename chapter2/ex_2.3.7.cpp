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
    vector<int> A = {5,3,6,2,1,4,9,8,7};

    cout << "List -> ";
    
    for(auto a : A){
        cout << a << " ";
    }

    cout << endl;

    int sum;
    cout << "Enter sum of number: ";
    cin >> sum;
    int y;
    bool isFound = false;
    // first sort array in O(nlgn)
    merge_sort(A, 0, A.size()-1);

    // now search it's other number using binary search in remaining array
    for(int i=0; i < A.size(); i++){
        y = sum - A[i];
        if(binary_search(A, y, i+1, A.size()-1)){
            cout << "Yeah numbers found " << y << "+" << A[i] << "=" << sum << endl;
            isFound = true;
            break;
        }
    }

    if(!isFound){
        cout << "Not exist :(" << endl;
    }

}
