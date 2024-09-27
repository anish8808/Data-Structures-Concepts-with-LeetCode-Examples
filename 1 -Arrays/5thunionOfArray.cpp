#include <iostream>
#include <vector>

using namespace std;

int main() {
    int arr[5] = {1 ,2 ,4 , 5 , 6};
    int brr[2] ={8 , 9};

    vector<int> ans;
    for (int i = 0; i < 5; i++) {
        ans.push_back(arr[i]);
    }
    for (int i = 0; i < 2; i++) {
        ans.push_back(brr[i]);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
