#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int evalRPN(vector<string> &tokens) 
{
	int ret = 0;
	stack<int>num;
	stack<char>op;
	int num1=0, num2=0;

	for (int i=0; i<tokens.size(); i++)
	{
		if (tokens[i].size()<=1 && tokens[i][0] >= 0x2a && tokens[i][0]<= 0x2f)
		{
			op.push(tokens[i][0]);
		}
		else
		{
			num.push(atoi(&tokens[i][0]));
		}

		if (!op.empty())
		{
			if (num.size() < 2)
			{
				break;
			}

			num2=num.top();
			num.pop();
			num1=num.top();
			num.pop();
			switch(op.top())
			{
			case '+':
				ret = num1 + num2;
				break;
			case '-':
				ret = num1 - num2;
				break;
			case '*':
				ret = num1 * num2;
				break;
			case '/':
				ret = num1 / num2;
				break;
			default:
				break;
			}
			num.push(ret);
			op.pop();

		}
	}

	return ret = num.top();
}

int main()
{
	int ret = 0;

	vector<string> vec;
	vec.push_back("2");
	vec.push_back("1");
	vec.push_back("+");
	vec.push_back("3");
	vec.push_back("*");
	printf("%d\n", evalRPN(vec));
	
	vec.clear();
	vec.push_back("4");
	vec.push_back("13");
	vec.push_back("5");
	vec.push_back("/");
	vec.push_back("+");
	printf("%d\n", evalRPN(vec));

	vec.clear();
	vec.push_back("4");
	printf("%d\n", evalRPN(vec));

	vec.clear();
	vec.push_back("-1");
	vec.push_back("1");
	vec.push_back("*");
	vec.push_back("-1");
	vec.push_back("+");
	printf("%d\n", evalRPN(vec));

	system("pause");
	return 0;
}