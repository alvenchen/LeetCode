/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.empty())
		{
			return false;
		}
		bool bExist = false;
		int m = board[0].size(), n = board.size();
		vector<vector<char>> mask(n, vector<char>(m, 0));

		for (int i=0; i<n && bExist==false; i++)
		{
			for (int j=0; j<m;j++)
			{
				if (board[i][j] == word[0])
				{
					if (Check(board, word, 0, i, j, mask))
					{
						bExist = true;
						break;
					}
										
				}
			}
		}

		return bExist;
	}

	void calcPos(int op, int i, int j, int &newi, int &newj)
	{
		newi = i;
		newj = j;
		if (op==0)
		{
			newi--;
		}
		else if (op == 1)
		{
			newi++;
		}
		else if(op==2)
		{
			newj--;
		}
		else if(op == 3)
		{
			newj++;
		}
	}

	bool Check(vector<vector<char> > &board, string &word, int index, int i, int j, vector<vector<char>> &mask)
	{
		if (mask[i][j] == 1)
		{
			return false;
		}
		if (index == word.size()-1)
		{
			return true;
		}
		bool bFindChar = false;
		mask[i][j] = 1;
		for (int op=0; op<4; op++)
		{
			if (Check(board, word[index+1], i, j, op))
			{
				int newi=0, newj=0;
				calcPos(op, i, j, newi, newj);
				bFindChar |= Check(board, word, index+1, newi, newj, mask);
			}
		}
		if (!bFindChar)
		{
			mask[i][j] = 0;
		}

		return bFindChar;
	}

	bool Check(vector<vector<char> > &board, char key, int i, int j, int op)
	{
		int m = board[0].size(), n = board.size();
		bool ret = false;
		switch(op)//up down left right
		{
		case 0:
			if (i > 0 && n > 1)
			{
				if (board[i-1][j] == key)
				{
					ret = true;
				}
			}
			break;
		case 1:
			if (i < n-1 && n > 1)
			{
				if (board[i+1][j] == key)
				{
					ret = true;
				}
			}
			break;
		case 2:
			if (j > 0 && m > 1)
			{
				if (board[i][j-1] == key)
				{
					ret = true;
				}
			}
			break;;
		case 3:
			if (j < m-1 && m > 1)
			{
				if (board[i][j+1] == key)
				{
					ret = true;
				}
			}
			break;
		default:
			break;
		}
		return ret;
	}
};

int main()
{
	char buf1[] = {"ABCE"};
	char buf2[] = {"SFES"};
	char buf3[] = {"ADEE"};
	vector<char> vec1, vec2, vec3;
	vec1.assign(buf1, buf1+sizeof(buf1));
	vec2.assign(buf2, buf2+sizeof(buf2));
	vec3.assign(buf3, buf3+sizeof(buf3));

	vector<vector<char>> board;
	board.push_back(vec1);
	board.push_back(vec2);
	board.push_back(vec3);

	Solution so;
	so.exist(board, "ABCESEEEFS");

	return 0;
}