// By Using Divide and Conqure technique in O(nlgn) running time
#include<iostream>
#include<vector>
#include<climits>
#include<math.h>
#include <tuple>

using namespace std;

tuple<int, int, int> find_cross_maximum_subarray(vector<int>& A, int low, int mid, int high){
    int max_left_sum = INT_MIN;
    int max_left_index;
    int sum = 0;
    for(int i=mid; i >= low; i--){
        sum += A[i];
        if(sum > max_left_sum){
            max_left_sum = sum;
            max_left_index = i;
        }
    }

    int max_right_sum = INT_MIN;
    int max_right_index;
    sum = 0;
    for(int i=mid+1; i <= high; i++){
        sum += A[i];
        if(sum > max_right_sum){
            max_right_sum = sum;
            max_right_index = i;
        }
    }
    
    return make_tuple(max_left_index, max_right_index, max_left_sum+max_right_sum);

}

tuple<int, int, int> find_maximum_subarray(vector<int> &A, int low, int high){
    if(A.size() > 1 && low < high){
        int mid = floor((low+high)/2);
        int left_low, left_high, left_sum;
        tie(left_low, left_high, left_sum) = find_maximum_subarray(A, low, mid-1);
        int right_low, right_high, right_sum;
        tie(right_low, right_high, right_sum) = find_maximum_subarray(A, mid+1, high);
        int cross_low, cross_high, cross_sum;
        tie(cross_low, cross_high, cross_sum) = find_cross_maximum_subarray(A, low, mid, high);

        if(left_sum >= right_sum && left_sum >= cross_sum){
            return make_tuple(left_low, left_high, left_sum);
        } else if(right_sum >= left_sum && right_sum >= cross_sum){
            return make_tuple(right_low, right_high, right_sum);
        } else {
            return make_tuple(cross_low, cross_high, cross_sum);
        }
    }
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
