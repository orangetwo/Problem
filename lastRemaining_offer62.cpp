//
// Created by 李思 on 2021/12/25.
//



class Solution{
public:
    int lastRemaining(int n, int m){
        int x = 0;
        for(int i = 2; i <=n; i ++){
            x = (x + m) % i;
        }

        return x;
    }
};