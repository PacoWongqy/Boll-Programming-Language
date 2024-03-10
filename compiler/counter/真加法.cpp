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

    int carry = 0;
    for (int i = 0; i < maxLen || carry; i++) {
        if (i < len1)
            carry += m[len1 - 1 - i] - '0';
        if (i < len2)
            carry += n[len2 - 1 - i] - '0';
        
        result[maxLen - i] = carry % 10;
        carry /= 10;
    }

    cout << "Sum is: ";
    int start = 0;
    while (result[start] == 0 && start < maxLen)
        start++;
    for (int i = start; i <= maxLen; i++)
        cout << result[i];

    return 0;
}
