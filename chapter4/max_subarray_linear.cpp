// By Using Brute-force technique in O(n^2) running time
#include<iostream>
#include<vector>
#include<climits>
#include<math.h>
#include <tuple>

using namespace std;

tuple<int, int, int> find_maximum_subarray(vector<int> &A, int low, int high){
    int max_so_far = A[0];
    int max_ending_here = A[0];
    int left_index, right_index;
    left_index = 0;
    right_index = 0;
    for(int i=1; i<=high; i++){
        if((max_ending_here + A[i]) < A[i]){
            left_index = i;
        }
        max_ending_here = max(A[i], max_ending_here + A[i]);
        
        if(max_ending_here > max_so_far){
            max_so_far = max_ending_here;
            right_index = i;
        }
    }
    return make_tuple(left_index, right_index, max_so_far);
}

int main(){
    vector<int> A = {-2, -3, 4, -1, -2, 1, 5, -3};
    int l,r,max_sum;
    tie(l, r, max_sum) = find_maximum_subarray(A, 0, A.size()-1);

    cout << "Max Subarray... Sum = " << max_sum << endl;
    
    for(int i=l; i <= r; i++){
        cout << A[i] << " ";
    }
}
