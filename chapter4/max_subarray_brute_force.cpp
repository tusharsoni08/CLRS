// By Using Brute-force technique in O(n^2) running time
#include<iostream>
#include<vector>
#include<climits>
#include<math.h>
#include <tuple>

using namespace std;

tuple<int, int, int> find_maximum_subarray(vector<int> &A, int low, int high){
    int max_sum_so_far, current_sum, left_index, right_index;
    max_sum_so_far = A[0];
    for(int i=0; i <= high; i++){
        current_sum = 0;
        for(int j=i; j <= high; j++){
            current_sum += A[j];
            if(current_sum > max_sum_so_far){
                max_sum_so_far = current_sum;
                left_index = i;
                right_index = j;
            }
        }
    }

    return make_tuple(left_index, right_index, max_sum_so_far);
}

int main(){
    vector<int> A = {-2, -5, 6, -2, -3, 1, 5, -6};
    int l,r,max_sum;
    tie(l, r, max_sum) = find_maximum_subarray(A, 0, A.size()-1);

    cout << "Max Subarray... Sum = " << max_sum << endl;
    
    for(int i=l; i <= r; i++){
        cout << A[i] << " ";
    }
}
