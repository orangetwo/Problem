//
// Created by 李思 on 2021/12/21.
//

#include "vector"
#include "queue"
using namespace std;

struct Node{
    int i, j, h;
    Node(int ii, int jj, int hh): i(ii), j(jj), h(hh){}
    bool operator <(const Node &root) const{
        return h > root.h2;
    }
};
class Solution{

public:
    int trapRainWater(vector<vector<int>> &heightMap){

        if(heightMap.empty()) return 0;

        int row = heightMap.size();
        int column = heightMap[0].size();

        priority_queue<Node> q;
    }


};

