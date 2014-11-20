//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time. 

#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <string.h>
// 
// class Stack
// {
// public:
// 	Stack(int size = 10)
// 		:m_Size(size),m_depth(1)
// 	{
// 		m_pBuff = new int *[m_depth];
// 		for (int i=0; i<m_depth; i++)
// 		{
// 			m_pBuff[i] = new int[m_Size];
// 			//memset(m_pBuff[i], 0, m_Size);
// 		}
// 		m_Top = -1;
// 		m_TopDepth = 0;
// 	}
// 	~Stack()
// 	{
// 		for (int i=0; i<m_depth; i++)
// 		{
// 			delete []m_pBuff[i];
// 		}
// 		delete []m_pBuff;
// 	}
// 
// 	void push(int x)
// 	{
// 		if (m_Top == m_Size - 1)
// 		{
// 			if (m_TopDepth == m_depth - 1)
// 			{
// 				int **pBuff = new int *[m_depth << 1];
// 				for (int i=0; i<m_depth; i++)
// 				{
// 					pBuff[i] = m_pBuff[i];
// 				}
// 				for (int i=m_depth ;i<m_depth<<1; i++)
// 				{
// 					pBuff[i] = new int[m_Size];
// 				}
// 				//memset(pBuff[m_depth], 0, m_Size);
// 				delete []m_pBuff;
// 				m_pBuff = pBuff;
// 				m_depth = m_depth << 1;
// 			}
// 			m_Top = 0;
// 			m_pBuff[++m_TopDepth][m_Top] = x;
// 		}
// 		else
// 		{
// 			m_pBuff[m_TopDepth][++m_Top] = x;
// 		}
// 	}
// 
// 	void pop()
// 	{
// 		if (m_Top == 0)
// 		{
// 			if (m_TopDepth > 0)
// 			{
// 				m_TopDepth--;
// 				m_Top = m_Size - 1;
// 			}
// 			else
// 			{
// 				m_Top = -1;
// 			}
// 		}
// 		else
// 		{
// 			m_Top--;
// 		}
// 	}
// 
// 	int top()
// 	{
// 		if (m_Top < 0)
// 		{
// 			return 0;
// 		}
// 		return m_pBuff[m_TopDepth][m_Top];
// 	}
// 
// 	bool IsEmpty()
// 	{
// 		return (m_Top < 0);
// 	}
// 
// private:
// 	int m_Size;
// 	int m_depth;
// 	int **m_pBuff;
// 	int m_Top;
// 	int m_TopDepth;
// };


class Stack
{
public:
	Stack(int size = 10)
		:m_Size(size)
	{
		m_pBuff = (int *)malloc(size*sizeof(int));
		m_Top = -1;
	}
	~Stack()
	{
		delete []m_pBuff;
	}

	void push(int x)
	{
		if (m_Top == m_Size - 1)
		{
			m_pBuff = (int *)realloc(m_pBuff , (m_Size << 2) * sizeof(int));
			m_Size = m_Size << 2;
		}
		m_pBuff[++m_Top] = x;
	}

	void pop()
	{
		if (m_Top < 0)
		{
			m_Top = -1;
		}
		else
		{
			m_Top--;
		}
	}

	int top()
	{
		if (m_Top < 0)
		{
			return 0;
		}
		return m_pBuff[m_Top];
	}

	bool IsEmpty()
	{
		return (m_Top < 0);
	}

	int GetTopPos()
	{
		return m_Top;
	}
private:
	int m_Size;
	int *m_pBuff;
	int m_Top;
};

class MinStack//Min heap
{
public:
	MinStack()
		:m_MinPos(-1)
	{
	}

	~MinStack()
	{
		
	}

	void push(int x)
	{
		m_Stack.push(x);
		if (x <= m_Min.top() || m_Min.IsEmpty())
		{
			m_Min.push(x);
		}
	}

	void pop()
	{
		if (m_Min.top() == m_Stack.top())
		{
			m_Min.pop();
			m_Stack.pop();
		}
		else
		{
			m_Stack.pop();
		}
	}

	int top()
	{
		return m_Stack.top();
	}

	int getMin()
	{
		return m_Min.top();
	}

private:
	Stack	m_Stack;
	Stack	m_Min;
	int		m_MinPos;
};

int main()
{
	srand(100);

 	MinStack stack;

	stack.push(395);
	stack.push(276);
	stack.push(29);
	stack.push(-482);
	printf("%d ", stack.getMin());
	stack.pop();
	printf("%d ", stack.getMin());
	stack.push(-108);
	printf("%d ", stack.getMin());
	stack.push(-251);
	printf("%d ", stack.getMin());
	stack.push(-439);
	printf("%d ", stack.getMin());
	stack.push(370);
	printf("%d ", stack.getMin());
	stack.pop();
	printf("%d ", stack.getMin());
	stack.pop();
	printf("%d ", stack.getMin());
	stack.pop();
	printf("%d ", stack.getMin());
	stack.pop();
	printf("%d ", stack.getMin());

	system("pause");

	return 0;
}