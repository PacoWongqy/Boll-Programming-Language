#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int a[N], b[N], c[N];
int main()
{
    string a1;
    string b1;
    cin >> a1 >> b1;
    int lena=a1.size();
    int lenb=b1.size();
    for (int i = 0; i < lena; i ++)			 //将乘数a1放进a数组
        a[lena-1-i] = a1[i] - '0';
    for (int i = 0; i < lenb; i ++)		    //将乘数b1放进b数组
        b[lenb-1-i] = b1[i] - '0';
    for (int i = 0; i < lena; i ++){
        for (int j = 0; j < lenb; j ++){	//依次用乘数的每一位去乘以被乘数 
            c[j+i] = a[i] * b[j]+c[j+i];
            c[j+1+i] += c[j+i] / 10;
            c[j+i] %= 10;
        }
    }
	int as = lena+lenb;
    while (c[as-1] == 0 && as > 1)			//最高位的0不输出
        as -= 1;

    for(int i=as-1;i>=0;i--)				//输出结果 
		cout<<c[i];
    return 0;
}

