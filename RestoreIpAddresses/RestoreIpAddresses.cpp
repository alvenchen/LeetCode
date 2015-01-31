/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int num = s.size();
		vector<string> vec;

		int n[5] = {0};
		int seg[4] = {0};
		for (n[1]=1; n[1]<4; n[1]++)
		{
			for (n[2]=1; n[2]<4; n[2]++)
			{
				for (n[3]=1; n[3]<4; n[3]++)
				{
					n[4] = num - n[1] - n[2] - n[3];
					if (n[4] > 0 && n[4] < 4)
					{
						if (calc(s, 0, n[1]) > 255)
						{
							continue;;
						}
						if (calc(s, n[1], n[2]) > 255)
						{
							continue;;
						}
						if (calc(s, n[1]+n[2], n[3]) > 255)
						{
							continue;;
						}
						if (calc(s, n[1]+n[2]+n[3], n[4]) > 255)
						{
							continue;;
						}
						vec.push_back(get(s, n[1], n[2], n[3], n[4]));
					}
				}
			}
		}
		return vec;
	}

	int calc(string &s, int b, int n)
	{
		int ret = 0;
		for (int i=0; i<n; i++)
		{
			ret *= 10;
			ret += s[i+b] - '0';
		}
		if (ret == 0)
		{
			if (n > 1)
			{
				ret = 256;
			}
		}
		else
		{
			if (s[b] == '0')
			{
				ret = 256;
			}
		}
		return ret;
	}
	string get(string &s, int n1, int n2, int n3, int n4)
	{
		string ret;
		ret = s.substr(0, n1);
		ret += ".";
		ret += s.substr(n1, n2);
		ret += ".";
		ret += s.substr(n1+n2, n3);
		ret += ".";
		ret += s.substr(n1+n2+n3, n4);
		return ret;
	}
};

int main()
{
	string s = "25525511135";
//	string s = "010010";
	Solution so;
	so.restoreIpAddresses(s);

	return 0;
}