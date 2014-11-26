#include<stdio.h>
#include <vector>


int maxProduct(int A[], int n)
{
	typedef struct//非0数的array
	{
		int			pos;
		int			num;
		int			minusNum;
		int			firstMinus;
		int			firstMinusPos;
		int			lastMinus;
		int			lastMinusPos;
	}assistSt;
	assistSt *assist = new assistSt[n];
	memset(assist, 0, sizeof(assistSt)*n);
	int assistIt = 0;
	int curr;

	int Max = 0, pos = 0, num = 0;
	bool bFirst = true;

	for(int i = 0; i < n; i++)
	{
		if (A[i] == 0)
		{
			bFirst = false;
			Max = A[i];
			pos = i;
			num = 1;
			if (assist[assistIt].num > 0)
			{
				assistIt++;
			}
		}
		else
		{
			if (assist[assistIt].num == 0)
			{
				assist[assistIt].pos = i;
			}
			if (A[i] < 0)
			{
				assist[assistIt].minusNum++;
				if (assist[assistIt].firstMinus == 0)
				{
					assist[assistIt].firstMinus = A[i];
					assist[assistIt].firstMinusPos = i;
				}
				assist[assistIt].lastMinus = A[i];
				assist[assistIt].lastMinusPos = i;
			}
			assist[assistIt].num++;
		}
	}


	for (int i=0; i<=assistIt; i++)
	{
		if (assist[i].minusNum % 2 != 0)
		{
			//这里开始比较其中的两个字串
			int maxTemp1 = 1, maxTemp2 = 1;
			bool bCompare1 = false, bCompare2 = false;
			for (int j=assist[i].pos; j<assist[i].lastMinusPos; j++)
			{	
				bCompare1 = true;
				maxTemp1 *= A[j];
			}
			for (int j=assist[i].firstMinusPos+1; j<assist[i].pos+assist[i].num; j++)
			{
				bCompare2 = true;
				maxTemp2 *= A[j];
			}
			if (bCompare1 && maxTemp1 >= maxTemp2)
			{
				if (Max < maxTemp1 || bFirst)
				{
					bFirst = false;
					Max = maxTemp1;
					pos = assist[i].pos;
					num = assist[i].lastMinusPos - assist[i].pos;
				}
			}
			else if(bCompare2)
			{
				if (Max < maxTemp2 || bFirst)
				{
					bFirst = false;
					Max = maxTemp2;
					pos = assist[i].firstMinusPos+1;
					num = assist[i].pos+assist[i].num - assist[i].firstMinusPos - 1;
				}
			}
		}
		else
		{
			int maxTemp = 1;
			bool bCompare = false;
			for (int j=assist[i].pos; j<assist[i].pos+assist[i].num; j++)
			{
				bCompare = true;
				maxTemp *= A[j];	
			}
			if (bCompare && (Max < maxTemp || bFirst))
			{
				bFirst = false;
				Max = maxTemp;
				pos =assist[i].pos;
				num = assist[i].num;
			}
		}
	}
	if (num == 0)
	{
		Max = A[0];
		pos = 0;
		num = 1;
	}

	printf("Max %d  pos %d  num %d\n", Max, pos, num);
	delete []assist;

	return Max;
}

int main()
{
	int arrey[] = {-2};

	maxProduct(arrey, sizeof(arrey) / sizeof(int));

	system("pause");

	return 0;
}