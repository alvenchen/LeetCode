/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution
{
public:
	void solve(vector<vector<char>> &board)
	{
		if (board.size() < 3)
		{
			return;
		}
		if (board[0].size() < 3)
		{
			return;
		}
		int height = board.size();
		int width = board[0].size();

		struct pixel
		{
			pixel(int a, int b)
			{
				X = a;
				y = b;
			}
			bool operator < (const pixel &p)const
			{
				if (X == p.X)
				{
					return y < p.y;
				}
				return X < p.X;
			}
			int X;
			int y;
		};
		vector<pixel> v;
		queue<pixel> q;

		for (int i=1; i<width-1; i++)
		{
			if (board[0][i] == 'O')
			{
				q.push(pixel(0, i));
			}
		}
		for (int i=1; i<width-1; i++)
		{
			if (board[height-1][i] == 'O')
			{
				q.push(pixel(height-1, i));
			}
		}
		for (int i=1; i<height-1; i++)
		{
			if (board[i][0] == 'O')
			{
				q.push(pixel(i, 0));
			}
		}
		for (int i=1; i<height-1; i++)
		{
			if (board[i][width-1] == 'O')
			{
				q.push(pixel(i, width - 1));
			}
		}

		set<pixel> s;
		while(!q.empty())
		{
			pixel p = q.front();
			s.insert(p);
			q.pop();
			if (p.X > 0)
			{
				if (board[p.X-1][p.y] == 'O')
				{
					pixel tmp(p.X-1, p.y);
					if (s.find(tmp) == s.end())
					{
						q.push(tmp);
						s.insert(tmp);
					}
				}
			}
			if (p.X < height-1)
			{
				if (board[p.X+1][p.y] == 'O')
				{
					pixel tmp(p.X+1, p.y);
					if (s.find(tmp) == s.end())
					{
						q.push(tmp);
						s.insert(tmp);
					}
				}
			}
			if (p.y > 0)
			{
				if (board[p.X][p.y-1] == 'O')
				{
					pixel tmp(p.X, p.y-1);
					if (s.find(tmp) == s.end())
					{
						q.push(tmp);
						s.insert(tmp);
					}
				}
			}
			if (p.y < width - 1)
			{
				if (board[p.X][p.y+1] == 'O')
				{
					pixel tmp(p.X, p.y+1);
					if (s.find(tmp) == s.end())
					{
						q.push(tmp);
						s.insert(tmp);
					}
				}
			}
		}
		
		for (int i=1; i<height-1; i++)
		{
			for (int j=1; j<width-1; j++)
			{
				board[i][j] = 'X';
			}
		}

		set<pixel>::iterator it = s.begin();
		for (; it!=s.end(); ++it)
		{
			board[(*it).X][(*it).y] = 'O';
		}
	}
};

void Create(vector<vector<char>> &board, int n)
{
	char r;
	board.clear();
	vector<char> tmp;
	for (int i=0; i<n; i++)
	{
		board.push_back(tmp);
		for (int j=0; j<n; j++)
		{
			r= (rand() % 3 == 0) ? 'O' : 'X';
			board[i].push_back(r);
		}
	}
}

void Print(vector<vector<char>> &board)
{
	for (int i=0; i<board.size(); i++)
	{
		for (int j=0; j<board[0].size(); j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	srand(GetTickCount());

	vector<vector<char>> board;
	
	Create(board, 6);
	Print(board);

	Solution solution;
	solution.solve(board);

	printf("after solution:\n");
	Print(board);

	system("pause");

	return 0;
}