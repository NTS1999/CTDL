#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool check(char open,char close)
{
	if (open=='(' && close==')')
	{
		return true;
	}
	else if (open=='[' && close==']')
	{
		return true;
	}
	else if (open=='{' && close=='}')
	{
		return true;
	}
	return false;
}
void KtraCanXung(){
	stack<char> a;
	stack<int> b;
	string t;
	cin>>t;

	int flag=1;
	for (int i=0;i<t.length();i++)
	{
		if (t[i]=='(' || t[i]=='[' || t[i]=='{')
		{
			a.push(t[i]);
			b.push(i+1);
		}
		else if (t[i]==')' || t[i]==']' || t[i]=='}')
		{
			if (a.empty() || !check(a.top(),t[i]))
			{
				cout<<i+1;
				flag=0;
				break;
			}
			else
			{
				a.pop();
				b.pop();
			}
		}
	}
	if (flag==1)
		if (a.empty())
			cout<<"Success";
		else
			cout<<b.top();

}

int main()
{

	KtraCanXung();
	return 0;
}
