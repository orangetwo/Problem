#include "vector"
using namespace std;

bool compare(vector<int> &x, vector<int> &y){
    return x[0] == y[0] ? x[1] >= y[1] : x[0] <= y[0];
}

int main() {
    //vector<int> test{3,2,1,4,5,9};
    vector<vector<int>> o{{5,2},{6,7},{6,4},{1,8},{2,3},{5,4}};
    sort(o.begin(), o.end(), compare);

    return 0;
}
