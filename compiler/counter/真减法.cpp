#include <bits/stdc++.h>
using namespace std;

int main() {
    char m[100], n[100];
    cin >> m;
    cin >> n;

    int len1 = strlen(m);
    int len2 = strlen(n);

    int maxLen = max(len1, len2);
    int result[maxLen + 1];
    memset(result, 0, sizeof(result));

    int borrow = 0;
    for (int i = 0; i < maxLen || borrow; i++) {
        if (i < len1)
            borrow += m[len1 - 1 - i] - '0';
        if (i < len2)
            borrow -= n[len2 - 1 - i] - '0';
        
        if (borrow < 0) {
            result[maxLen - i] = 10 + borrow;
            borrow = -1;
        } else {
            result[maxLen - i] = borrow;
            borrow = 0;
        }
    }

    cout << "Difference is: ";
    int start = 0;
    while (result[start] == 0 && start < maxLen)
        start++;
    for (int i = start; i <= maxLen; i++)
        cout << result[i];

    return 0;
}
