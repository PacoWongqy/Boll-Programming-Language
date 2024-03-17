#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct T{
	long long tp,num,l,r;
	char op;
}t[3010];
string s;
long long tot,len;
stack<long long> nst;
stack<char> cst;
long long int pri(char op){
	if(op=='+'||op=='-') return 1;
	if(op=='*'||op=='/') return 2;
	return 3;
}
long long int dfs(long long u){
	if(t[u].tp==0) return t[u].num;
	if(t[u].op=='+') return dfs(t[u].l)+dfs(t[u].r);
	if(t[u].op=='-') return dfs(t[u].l)-dfs(t[u].r);
	if(t[u].op=='*') return dfs(t[u].l)*dfs(t[u].r);
	if(t[u].op=='/') return dfs(t[u].l)/dfs(t[u].r);
	return 0;
}
void cac(){
	long long x,y;char op=cst.top();cst.pop();
	y=nst.top();nst.pop();
	x=nst.top();nst.pop();
	t[++tot]={1,0,x,y,op};
	nst.push(tot);
}
int main(){
	while(true){
        cout<<"$:";
        getline(cin, s);
        len=s.size();
        for(int i=0;i<len;i++){
            if(isdigit(s[i])){
                long long int val=0;
                for(;i<len&&isdigit(s[i]);i++) val=val*10+s[i]-'0';
                t[++tot]={0,val,0,0,0};
                nst.push(tot);
                i--;
            }
            else{
                if(s[i]=='(') cst.push(s[i]);
                else if(s[i]==')'){
                    while(cst.size()&&cst.top()!='(') cac();
                    cst.pop();
                }
                else{
                    while(cst.size()&&cst.top()!='('&&pri(s[i])<=pri(cst.top())) cac();
                    cst.push(s[i]);
                }
            }
        }
        while(!cst.empty()) cac();
        cout<<"out:"<<dfs(tot)<<endl;
	}
	return 0;
}
