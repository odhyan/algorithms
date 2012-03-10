/*
Author: Saurabh Odhyan
infix to postfix conversion and evaluation of the postfix expression
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char ch)
{
    switch(ch)
    {
               case '^' : return 5;
               case '/' : return 4;
               case '*' : return 4;                                            
               case '+' : return 3;
               case '-' : return 3;
               default  : return 0;
    }
}
bool isOperand(char ch)
{
	if(ch=='(' || ch==')' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^') return false;
	return true;
}
int eval(int x,int y,char ch){
	switch(ch){
		case '^' : return x^y;
		case '/' : return x/y;
		case '*' : return x*y;
		case '+' : return x+y;
		case '-' : return x-y;
		default : return 1;
	}
}
int evalPostfix(string str){
	stack<char> S;
	for(int i=0;i<str.size();i++){
		if(isOperand(str[i])){
			S.push(str[i]-'0');
		}else{
			int y=S.top(); S.pop();
			int x=S.top(); S.pop();
			int z=eval(x,y,str[i]);		
			S.push(z);
		}
	}
	return S.top();
}
int main()
{
	string str; //infix expression as input
	while(cin>>str)
	{
		stack<char> S;
		string res=""; //postfix expression as output
		for(int i=0;i<str.size();i++)
		{
			if(isOperand(str[i]))
				res+=str[i];
			else if(str[i]=='('){
				S.push(str[i]);
			}
			else if(str[i]==')'){
				while(S.top()!='('){
					res+=S.top(); 
					S.pop();					
				}
				S.pop();
			}
			else if(S.empty() || precedence(str[i])>precedence(S.top())){
					S.push(str[i]);
			}
			else{
				while(!S.empty() && precedence(str[i])<=precedence(S.top())){
					res+=S.top(); 
					S.pop();
				}
				S.push(str[i]);
			}				
		}
		while(!S.empty()){
			res+=S.top();
			S.pop();
		}
		cout<<"Postfix expression: "<<res<<endl;

		cout<<"Value: "<<evalPostfix(res)<<endl;
	}
}
