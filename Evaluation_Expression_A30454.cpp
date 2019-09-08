#include <iostream>
#include <stack>
#include <string>
using namespace std;
int ut(char c)
{
	if (c=='(')
		return 0;
	if (c=='+' || c=='-')
		return 1;
	if (c=='*'|| c=='/'|| c=='%')
		return 2;
	if (c=='^')
		return 3;
}
string HauTo()
{
	stack<char> s;
	int i=0;
	string str,str1="",str2="";
	getline(cin,str);
	while (i<str.length())
	{
		char c = str.at(i);
		if (c != ' ')
		{
			if ((c-'0'>= 0 && c-'0'<=9) || isalpha(c))
				str1+=c;
			else
			{
				str2+=str1;
				str1 = "";
				if (c=='(')
					s.push(c);
				else
				{
					if (c==')')
					{
						while (s.top() != '(')
						{
							str2+=s.top();
							s.pop();	
						}
						s.pop();
					}
					else
					{
						while (!s.empty()&&ut(c)<=ut(s.top()))
						{
							str2+=s.top();
							s.pop();
						}
						s.push(c);
					}
				}
			}
		}
		i++;
	}
	if (str1!="")
		str2+=str1;
	while (!s.empty())
	{
		str2+=s.top();
		s.pop();
	}
	return str2;
}
bool LaSo(char c)
{
	return (c >= '0' && c <= '9');
}
bool LaToanTu(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/'|| c == '%' || c == '^' );
}
int TinhHauTo(string t)
{
	stack<int> s;
	int x = 0, a, b, result;
	int len = t.length();
	for (int i=0;i<len;i++)
	{
		if (LaSo(t[i]))
		{
			while (LaSo(t[i]))
				x=x*10+t[i++]-49;
			s.push(x);
			x=0;
		}
		if (LaToanTu(t[i]))
		{
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			if (t[i] == '-') result = b-a;
			if (t[i] == '*') result = b*a;
			if (t[i] == '/') result = b/a;
			if (t[i] == '+') result = b+a;
			if (t[i] == '%') result = b%a;
			s.push(result);
		}
	}
	return s.top();
}
int main()
{
	string a=HauTo();
	cout<<a;
	string b;
	cin>>b;
	cout<<TinhHauTo(b);
	return 0;
}
