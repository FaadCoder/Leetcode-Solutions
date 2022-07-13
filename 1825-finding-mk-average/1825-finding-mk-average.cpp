// OJ: https://leetcode.com/contest/weekly-contest-236/problems/finding-mk-average/
// Author: github.com/lzl124631x
// Time: 
//     MKAverage: O(1)
//     addElement: O(logM)
//     calculateMKAverage: O(1)
// Space: O(M)
class MKAverage
{
    multiset<int> top, bot, mid;
    queue<int> q;
    long sum = 0, m, k;
    public:
        MKAverage(int m, int k): m(m), k(k) {}

    void addElement(int n)
    {
        if (q.size() < m) mid.insert(n);	// when there are less than `m` numbers, always insert into `mid`.
        q.push(n);
        if (q.size() == m)
        {
           	// when we reached exactly `m` numbers, we nudge numbers from `mid` to `top` and `bot`, and calculate `sum`.
            for (int i = 0; i < k; ++i)
            {
                bot.insert(*mid.begin());
                mid.erase(mid.begin());
            }
            for (int i = 0; i < k; ++i)
            {
                top.insert(*mid.rbegin());
                mid.erase(prev(mid.end()));
            }
            for (int x: mid) sum += x;
        }
        else if (q.size() > m)
        {
           	// when we've seen more than `m` numbers. We first add the new number `n` to where it should belong.
           	// If we add `n` to `top` or `bot`, we balance them with `mid` to make sure `top` and `bot` have exactly `k` numbers
            if (n<*bot.rbegin())
            {
                bot.insert(n);
                int x = *bot.rbegin();
                bot.erase(prev(bot.end()));
                mid.insert(x);
                sum += x;
            }
            else if (n > *top.begin())
            {
                top.insert(n);
                int x = *top.begin();
                top.erase(top.begin());
                mid.insert(x);
                sum += x;
            }
            else
            {
                mid.insert(n);
                sum += n;
            }
           	// Then we remove the number `rm` that is no longer one of the latest `m` numbers.
            int rm = q.front();
            q.pop();
            auto it = mid.find(rm);
            if (it != mid.end())
            {
            	// first try removing from `mid`, then `top` or `bot`.
                mid.erase(it);
                sum -= rm;
            }
            else
            {
                it = top.find(rm);
                if (it != top.end())
                {
                    top.erase(it);
                }
                else
                {
                    bot.erase(bot.find(rm));
                }
            }
           	// Lastly, balance `top` and `bot` if needed
            if (bot.size() < k)
            {
                int x = *mid.begin();
                bot.insert(x);
                mid.erase(mid.begin());
                sum -= x;
            }
            else if (top.size() < k)
            {
                int x = *mid.rbegin();
                top.insert(x);
                mid.erase(prev(mid.end()));
                sum -= x;
            }
        }
    }

    int calculateMKAverage()
    {
        return q.size() == m ? (sum / (m - 2 *k)) : -1;
    }
};