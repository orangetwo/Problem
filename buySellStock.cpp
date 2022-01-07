//
// Created by 李思 on 2022/1/5.
//
/*
 * 每天有 三种状态 buy(该天买入) rest(该天无任何动作) sell(该天卖出)
 * sell的前置动作中必须包含buy rest操作的前置动作分两个动作即buy或sell
 *   dp[n-1][k][0] 代表 第n天时不持有股票 最多允许k次交易 最多获得的利润
 *   dp[n-1][k][1] 代表 第n天时持有股票  最多允许k次交易 最多获取的利润
 *   考虑 dp[n-1][k][0]的状态转移来源:
 *                      1. 第n天没有持有股票且 第n-1天处于不持有股票状态 dp[n-2][k][0]
 *                      2. 第n-1天持有股票 且在第n天出售以保持第n天处于不持有股票状态 dp[n-2][k][1] + prices[n-1]
 *   考虑 dp[n-1][k][1]的状态转移来源:
 *                      1. 第n天没有买入股票 dp[n-2][k][1]
 *                      2. 第n天买入股票  dp[n-2][k-1][0] - prices[n-1]
 *
 *   这里需要注意 买入一次 增加一次交易 卖出是不增加交易的.
 *
 *   Base Case 分析:
 *                1. 因为n=0时对应的第一天, 这里我们提出 -1为未开始, 则 dp[-1][...][0] = 0
 *                2. 同样未开始的时候是不可能持有股票的,因为是要求最大值,这里我们设置 dp[-1][...][1] = -∞
 *                3. 考虑k是从1开始的,故k=0时意味着根本不允许交易 有 dp[...][0][0] = 0
 *                4. 不需要交易的情况下,也是不可能持有股票的. 设置 dp[...][0][1] = -∞
 */

/*
 *  当 k = 1时,
 *              dp[i][0][0] = 0
 *              dp[i][0][1] = -∞
 *
 *              dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
 *              dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]) -> dp[i][1][1] = max(dp[i-1][1][1], 0 - prices[i])
 *
 *              化简
 *
 *              dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 *              dp[i][1] = max(dp[i-1][1], - prices[i])
 */

#include "vector"
using namespace std;

int maxProfit(vector<int> prices){

    if(prices.empty()) return 0;

    int profit = 0;
    int minPrice = prices[0];
    for(auto price : prices){
        profit = max(profit, price - minPrice);

        if (price < minPrice) minPrice = price;
    }
    return profit;
}

/*
 * k = 2时, base case:
 *          dp[i][0][0] = 0
 *          dp[i][0][1] = -∞
 *          dp[-1][...][0] = 0
 *          dp[-1][...][-1] = -∞
 *         状态转移:
 *          dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1])
 *          dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1])
 */

int maxProfitTwoTimes(vector<int> prices, int transactions){
    int days = prices.size();
    vector<vector<vector<int>>> dp(days, vector<vector<int>>(transactions + 1, vector<int>(2, 0)));

    // base case
    for(int day = 0; day < days; day ++){
        dp[day][0][0] = 0;
        dp[day][0][1] = INT_MIN;
    }

    // 状态转移
    for(int day = 0; day < days; day ++){
        for(int transaction = 1; transaction <= transactions; transaction ++){

            if(day == 0){
                dp[day][transaction][0] = 0;
                dp[day][transaction][1] = -prices[day];
                continue;
            }

            dp[day][transaction][0] = max(dp[day-1][transaction][0], dp[day-1][transaction][1] + prices[day]);
            dp[day][transaction][1] = max(dp[day-1][transaction][1], dp[day-1][transaction - 1][0] - prices[day]);

        }
    }
    return dp[days-1][transactions][0];
}
