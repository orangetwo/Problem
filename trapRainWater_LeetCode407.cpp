//
// Created by 李思 on 2021/12/21.
//

#include "vector"
#include "queue"
#include "iostream"

using namespace std;

struct Node{
    int i, j, h;
    Node(int ii, int jj, int hh): i(ii), j(jj), h(hh){}
    bool operator <(const Node &root) const{
        return h > root.h;
    }
};

class Solution{
public:
    int trapRainWater(vector<vector<int>> &heightMap){

        if(heightMap.empty()) return 0;

        int row = heightMap.size();
        int column = heightMap[0].size();

        priority_queue<Node, vector<Node>> q;

        vector<vector<bool>> visit(row, vector<bool>(column, false));

        // 首先把二维数据的边 压入 优先队列
        for(int i = 0; i < row ; i ++){
            for(int j = 0; j < column ; j ++) {
                if (i == 0 || i == row - 1 || j  == 0 || j == column - 1){
                    q.push(Node(i, j, heightMap[i][j]));
                    visit[i][j] = true;
                }
            }
        }

        // four direction
        vector<int> dirX = { 0, 0, -1, 1};
        vector<int> dirY = { -1, 1, 0, 0};

        int h = 0;
        int area = 0;
        while(!q.empty()){
            auto curr = q.top();
            // if (h < curr.h) h++;
            h = max(h, curr.h);


            q.pop();
            for(int k = 0; k < 4; k ++){
                int i = curr.i + dirX[k];
                int j = curr.j + dirY[k];

                if(i >= 0 && j >= 0 && i < row && j < column && !visit[i][j]){
                    int adjacentNodeHeight = heightMap[i][j];

                    if (h > adjacentNodeHeight) area += (h - adjacentNodeHeight);
                    q.push(Node(i, j, adjacentNodeHeight));
                    visit[i][j] = true;
                }
            }

        }
        return area;

    }


};

int main(){

    vector<vector<int>> inputs(5, vector<int>(3));

    int idx = 2;
    for(int i = 0; i < 5; i ++){
        for (int j = 0; j < 3; j ++){
            inputs[i][j] = idx;
            idx ++;
        }
    }
//    inputs[0] = {2,3,4};
//    inputs[1] = {5,6,7};
//    inputs[2] = {8,9,10};
//    inputs[3] = {11,12,13};
//    inputs[4] = {14,15,16};

    Solution s;
    cout << s.trapRainWater(inputs);
    return 0;

}