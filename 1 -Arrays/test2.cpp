#include <bits/stdc++.h>

using namespace std;

int getCountOfPossibleTeams(vector<int> coders) {
    int n = coders.size();
    int ans = 0;

    for (int j = 1; j < n - 1; ++j) {
        int lessLeft = 0, greaterLeft = 0;
        int lessRight = 0, greaterRight = 0;
        
        for (int i = 0; i < j; ++i) {
            if (coders[i] < coders[j]) 
            	lessLeft++;
            if (coders[i] > coders[j]) 
            	greaterLeft++;
        }

        for (int k = j + 1; k < n; ++k) {
            if (coders[k] < coders[j]) 
            	lessRight++;
            if (coders[k] > coders[j]) 
            	greaterRight++;
        }

        ans += lessLeft * greaterRight + greaterLeft * lessRight;
    }

    return ans;
}

int main() {
    std::vector<int> coders = {1,2,3,4};
    std::cout << getCountOfPossibleTeams(coders) << std::endl;
    return 0;
}