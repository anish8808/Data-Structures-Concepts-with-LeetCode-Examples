#include <iostream>
#include <Unordered_map>
#include <map>
using namespace std;

int main()
{
    // hash Map Data Strcture , where we can store the data in format of key & value <key , value>
    //  insertion , deletion , searching everything O(1)

    unordered_map<int, string> uMap;
    map<int, string> oMap;

    uMap[2] = "Anish";
    uMap[1] = "shubham";
    uMap[3] = "Manish";

    oMap[2] = "Anish";
    oMap[1] = "shubham";
    oMap[3] = "Manish";

    for (auto it : oMap)
    {
        cout << it.first << " " << it.second << endl;
    }

    for (auto it : uMap)
    {
        cout << it.first << " " << it.second << endl;
    }

    // find func this will retune itiretaor

    if (uMap.find(1) == uMap.end())
    {
        cout << "1 nahi mila" << endl;
    }
    else
    {
        cout << "1 mil gaya" << endl;
    }

    // second way this will retunr integer value

    if (uMap.count(3) == 1)
    {
        cout << "3 is not present" << endl;
    }
    else
    {
        cout << "3 is present" << endl;
    }

    return 0;
}