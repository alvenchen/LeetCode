/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the". 
*/

/*
	a,b,c d
	d,c,b a
*/

#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;


void reverseWords(string &s)
{
	if(s.empty())
	{
		return;
	}
	unsigned int itBegin = 0, itEnd = s.length() - 1;
	unsigned int sPosS = itBegin, sPosE = itBegin, ePosS = itEnd, ePosE = itEnd;
	string tmp1, tmp2, saved;
	unsigned int savedPosS = 0, savedPosE = 0;
	bool bFirst = true;

	while(itBegin <= itEnd)
	{
		while(s[itBegin] == ' ' && itBegin<=itEnd )//ȥ������ǰ��Ŀո�
		{
			itBegin++;
		}
		sPosS = itBegin;

		while(s[itBegin] != ' ' && itBegin<=itEnd)//��ǰ��ĵ���
		{
			itBegin++;
		}
		sPosE = itBegin;
		tmp1.assign(s, sPosS, sPosE - sPosS);

		while(s[itEnd] == ' ' && itBegin<=itEnd)//ȥ������Ŀո�
		{
			itEnd--;
		}
		ePosE = itEnd;

		while(s[itEnd] != ' ' && itBegin<=itEnd)//�Һ���ĵ���
		{
			itEnd--;
		}
		ePosS = itEnd + 1;

		if (ePosS - 1 < sPosS)
		{
			break;
		}

		tmp2.assign(s, ePosS, ePosE - ePosS + 1);

		if (ePosE <= sPosE)
		{
			saved.insert(savedPosS, tmp1);
			if (!bFirst)//�������һ�����ʲ��ӿո���������
			{
				saved.insert(savedPosS + tmp1.length(), " ");
			}
			break;
		}

		saved.insert(savedPosS, tmp2);
		savedPosS += tmp2.length();
		saved.insert(savedPosS, " ");
		savedPosS += 1;
		saved.insert(savedPosS, tmp1);
		if (!bFirst)//�������һ�����ʲ��ӿո���������
		{
			saved.insert(savedPosS + tmp1.length(), " ");
		}
		bFirst = false;
	}

	s = saved;
}


int main()
{
	string str("~the sky   is blue!");
	reverseWords(str);

	printf("%s", str.c_str());

	return 0;
}