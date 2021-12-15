//
// Created by 李思 on 2021/12/9.
//

#include "iostream"
#include "vector"
using namespace std;

vector<int> mergeSortedArrayInplace(vector<int> &A, vector<int> &B, int k){

    int a = k - 1;
    int b = B.size() - 1;
    int c = A.size() - 1;

    while(a >= 0 && b >= 0){
        if(A[a] >= B[b]) A[c--] = A[a--];
        else A[c--] = B[b--];
    }

    if(a > 0) return A;
    else{
        for(int i = 0; i < b+1; i++){
            A[i] = B[i];
        }
        return A;
    }


}

int main() {

    vector<int> A(7, 0);
    vector<int> B{2,4};
    int length = 5;
    int values[5] ={3, 5, 6, 7, 9};
    for(int i =0; i < length; i ++){
        A[i] = values[i];
    }
    for(int i =0; i < A.size(); i ++){
        cout << A[i] << " ";
    }
    cout << endl;
    vector<int> show = mergeSortedArrayInplace(A, B, length);
    for(int i =0; i < show.size(); i ++){
        cout << show[i] << " ";
    }
    return 0;
}