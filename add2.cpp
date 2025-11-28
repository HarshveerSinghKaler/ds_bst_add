#include <iostream>
using namespace std;

int countBST(int n) {
    if(n <= 1) return 1;
    int total = 0;
    for(int i=1; i<=n; i++) {
        int left = i-1;
        int right = n-i;
        total += countBST(left)*countBST(right);
    }
    return total;
}

int main() {
    int n = 3;

    cout<<countBST(n);

    return 0;
}