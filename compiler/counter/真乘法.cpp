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
    for (int i = 0; i < lena; i ++)			 //������a1�Ž�a����
        a[lena-1-i] = a1[i] - '0';
    for (int i = 0; i < lenb; i ++)		    //������b1�Ž�b����
        b[lenb-1-i] = b1[i] - '0';
    for (int i = 0; i < lena; i ++){
        for (int j = 0; j < lenb; j ++){	//�����ó�����ÿһλȥ���Ա����� 
            c[j+i] = a[i] * b[j]+c[j+i];
            c[j+1+i] += c[j+i] / 10;
            c[j+i] %= 10;
        }
    }
	int as = lena+lenb;
    while (c[as-1] == 0 && as > 1)			//���λ��0�����
        as -= 1;

    for(int i=as-1;i>=0;i--)				//������ 
		cout<<c[i];
    return 0;
}

