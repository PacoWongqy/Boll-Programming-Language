#include <bits/stdc++.h>
#define END return 0;
using namespace std;
int main(){
    string input[99999], arr[9999],cmd,name;
    int x, list = 0, var, var2, arrsize,y,j;
    while(true){
        cout << "_________________code__________________" << endl<<"BA["<<endl;
        x = 0;
        //清空输入 
        //输入 
		for(int i=0;i<99999;i++)input[i]="";
        while(1){
        	cout<<x+1<<":";
            getline(cin, input[x]);
            if(input[x] == "END"){
                x++;
                break;
            }
            x++;
        }
    	cout <<"]"<<endl<< "_________________command ______________" << endl;
    	//输出结果 
    	for(int i = 0; i < x; i++){
    		if(input[i]=="IMPORT "){
			}
            else if(input[i]=="COUT{#"){
            	list = i;
                while(true){
                  	list++;
                    cout << input[list];
                    if(input[list+1] == "#}"){
                       	break;
                    }
                    if(input[list+1]=="#}ENDL"){
                    	i=list;
						cout<<endl;
                    	break;
					}
					if(list>x){
						cout<<endl<<list-1<<" is ERROR"<<endl;
						break;
					}
                }
            	//cout字符串
			}
			else if(input[i]=="INPUT{"){
				list=i;
            	while(input[list]!="}"){
            		list++;
            		var = list;
            		while(var>=0){ 
            			if(input[var] == ("VAR " + input[list] + "{")){
            				getline(cin,input[var+1]);
            			}
            			var--;
            		}
            		if(list>x){
						cout<<endl<<list-1<<" is ERROR"<<endl;
						break;
					}
				} 
					//input变量
			}
            else if(input[i]== "COUT{$"){
            	list = i;
                while(true){
                	list++;
                   	var = list;
                   	while(true){ 
                       	if(input[var] == ("VAR " + input[list] + "{")){
                           	var2 = var;
                           	arrsize = 0;
                           	while(1){
                               	var2++;
                               	if(input[var2] == "}"){
                                   	break;
                               	}
                               	arr[arrsize] = input[var2];
                               	arrsize++;
                           	}
                           	for(int j = 0; j < arrsize; j++){
                               	cout << arr[j];
                           	}
                           	break;
                       	}
                        if(var<=0){
                        	break;
						}
                       	var--;
                    }
                    if(input[list]=="$}"){
                    	break;
					}
					if(input[list]=="$}ENDL"){
						cout<<endl;
                    	break;
					}
					if(list>x){
						cout<<endl<<list-1<<" is ERROR"<<endl;
						break;
					}
				}
				//cout变量
			}
        }
        cout<<endl;
    }
    END
}

