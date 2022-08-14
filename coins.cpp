#include <iostream>
#include <vector>

int coinChange(std::vector<int> &coins, int amount)
{
    std::vector<int> x((amount + 1), (amount + 1));
    x[0] = 0;
    for (int i = 0; i < x.size(); ++i)
    {
        for (auto j : coins)
        {
            if ((i - j) >= 0)
            {
                x[i] = std::min((x[i]), 1 + x[i - j]);
            }
            if (x[i] == 1)
            {
                break;
            }
        }
    }
    return x[amount] == amount + 1 ? -1 : x[amount];
}

int main()
{

    std::vector<int> vec = {0, 1, 5};
    int amount = 13;
    int coins = coinChange(vec, amount);
    std::cout << coins << std::endl;
}