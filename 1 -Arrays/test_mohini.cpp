#include <bits/stdc++.h>

using namespace std ;


int findDamagedToy(int N, int T, int D) {
    
    int lastToyPosition = ((D - 1) + T) % N;
    
    if (lastToyPosition == 0) {
        return N;
    }
    return lastToyPosition;
}

int main() {
    int N, T, D;
    std::cin >> N >> T >> D;
    std::cout << findDamagedToy(N, T, D) << std::endl;
    return 0;
}