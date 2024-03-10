#include<iostream>
#include<string>
using namespace std;
const int N = 10000;
int a[N], c[N],x=0;
int main()
{
    string a1;
    long long b; 
    cin >> a1 >>b;
    int lena=a1.size();
    for (int i = 0; i < lena; i ++)			 //将被减数放进a数组
        a[i] = a1[i] - '0';
    for (int i = 0; i < lena; i ++){
        c[i] = (x*10+a[i])/b;				//按位相除 
        x=(x*10+a[i])%b;
    }
	int as = 0;
    while (c[as] == 0 && as <lena)			//最高位的0不输出
        as++;
    for(int i=as;i<lena;i++)				//输出结果 
		cout<<c[i];
	cout<<endl<<x;
    return 0;
}

