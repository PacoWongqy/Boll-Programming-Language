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
    for (int i = 0; i < lena; i ++)			 //���������Ž�a����
        a[i] = a1[i] - '0';
    for (int i = 0; i < lena; i ++){
        c[i] = (x*10+a[i])/b;				//��λ��� 
        x=(x*10+a[i])%b;
    }
	int as = 0;
    while (c[as] == 0 && as <lena)			//���λ��0�����
        as++;
    for(int i=as;i<lena;i++)				//������ 
		cout<<c[i];
	cout<<endl<<x;
    return 0;
}

