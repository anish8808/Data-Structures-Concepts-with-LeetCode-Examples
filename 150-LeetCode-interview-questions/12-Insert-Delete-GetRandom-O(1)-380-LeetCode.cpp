// https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=study-plan-v2&envId=top-interview-150
#include <bits/stdc++.h>

using namespace std;

class RandomizedSet
{
public:
    unordered_map<int, int> mapp;
    vector<int> nums;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mapp.count(val))
        {
            return false;
        }
        nums.push_back(val);
        mapp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!mapp.count(val))
        {
            return false;
        }
        int idx = mapp[val];
        int lastElement = nums.back();

        nums[idx] = lastElement;
        mapp[lastElement] = idx;
        nums.pop_back();
        mapp.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

int main()
{
    RandomizedSet obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(6);
    obj.remove(1);
    obj.remove(3);
    obj.getRandom();

    return 0;
}