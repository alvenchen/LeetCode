/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line

*/
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

struct Point 
{
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

//两点就能确定一条线  所以应该找三个点
//三点一线 ： (x1-x2)*(y1-y3) = (x1-x3)*(y1-y2)

int maxPoints(vector<Point> &points) 
{
	int PointNum = points.size();
	if (PointNum < 2)
	{
		return PointNum;
	}

	int max = 2;
	int maxTmp = 2;
	struct Line
	{
		Line():a(0),b(0)
		{

		}
		Line(float x, long y)
		{
			a = x;
			y = b;
		}
		bool operator <(const Line &obj) const
		{
			if (b == obj.b)
			{
				return a < obj.a;
			}
			return b < obj.b;
		}
		float a;//y = ax + b
		int b;
	};
	map<Line , int>saved;
	Line tmp(0, 0);
	int samePoint1 = 0, samePoint2 = 0;

	for (int i=0; i<PointNum; i++)
	{
		samePoint1 = 0;
		for (int j=i+1; j<PointNum; j++)
		{
			maxTmp = 2;
			samePoint2 = 0;
			if (points[i].x == points[j].x && points[i].y == points[j].y)
			{
				samePoint1++;
				continue;
			}
			else if (points[i].x - points[j].x == 0)
			{
				tmp.a = 0xffffffff;
				tmp.b = points[i].x;
			}
			else if(points[i].y - points[j].y == 0)
			{
				tmp.a = 0;
				tmp.b = points[i].y;
			}
			else
			{
				tmp.a = (float)(points[i].y - points[j].y) / (float)(points[i].x - points[j].x);
				tmp.b = points[i].x * points[j].y - points[j].x * points[i].y;
			}
			if (saved.find(tmp) == saved.end())
			{
				for (int k=j+1; k<PointNum; k++)
				{
					if (points[j].x == points[k].x && points[j].y == points[k].y)
					{
						samePoint2++;
					}
					else if (tmp.a == 0xffffffff)
					{
						if (points[i].x == points[k].x)
						{
							maxTmp++;
						}
					}
					else if(tmp.a == 0)
					{
						if (points[i].y == points[k].y)
						{
							maxTmp++;
						}
					}
					else
					{
						if ((points[i].x - points[j].x) * (points[i].y - points[k].y) == \
							(points[i].x - points[k].x) * (points[i].y - points[j].y))
						{
							maxTmp++;
						}
					}
				}
				if (max < maxTmp + samePoint1 + samePoint2)
				{
					max = maxTmp + samePoint1 + samePoint2;
				}
			}
			else
			{
				
			}
		}
		if (max < maxTmp + samePoint1 + samePoint2 - 1)
		{
			max = maxTmp + samePoint1 + samePoint2 - 1;
		}
	}

	return max;
}

int maxPoints2(vector<Point> &points) {
#define INT_MAX 2147483647
#define INT_MIN -2147483648
	if (points.size()<=0) return 0;
	if (points.size()<=2) return points.size();
	int maxnum = 0;
	//using a map to find the same slope line
	map<double, int> slopeMap;
	//The algorithm here is quite straight forward.
	// take each point in array to caculate with others
	//
	//Actually the algorithm here can be optimized.
	// there are many duplicated calculation.
	// considering two points A and B, (A,B) is same with (B,A), here re-calculated.
	for(int i=0; i<points.size(); i++) {
		//reset teh slope map.
		slopeMap.clear();
		slopeMap[INT_MIN] = 0;
		int samePointCnt = 1;
		for (int j=0; j<points.size(); j++) {
			if (i==j) continue; //skip the same point
			//Caculate the slope of two points
			int delta_x = points[i].x - points[j].x;
			int delta_y = points[i].y - points[j].y;
			//Special case: two points are exactly at same place
			if (delta_y == 0 && delta_x == 0){
				samePointCnt++;
				continue;
			}
			//Special case: delta_x == 0
			double slope = INT_MAX;
			if (delta_x!=0) {
				slope = 1.0*delta_y / delta_x;
			}
			//Count the points is same line.
			slopeMap[slope]++;
		}
		//find the max number of points located at same line with points[i]
		map<double, int>::iterator it;
		for (it = slopeMap.begin(); it != slopeMap.end(); it++) {
			if (maxnum < it->second + samePointCnt) {
				maxnum = it->second + samePointCnt;
			}
		}
	}
	return maxnum;
}

int main()
{
 	vector<Point>vec;
// 	vec.push_back(Point(-435,-347));
// 	vec.push_back(Point(-435,-347));
// 	vec.push_back(Point(609,613));
// 	vec.push_back(Point(-348,-267));
// 	vec.push_back(Point(-174,-107));
// 	vec.push_back(Point(87,133));
// 	vec.push_back(Point(-87,-27));
// 	vec.push_back(Point(-609,-507));
// 	vec.push_back(Point(435,453));
// 	vec.push_back(Point(-870,-747));
// 	vec.push_back(Point(-783,-667));
// 	vec.push_back(Point(0,53));
// 	vec.push_back(Point(-174,-107));
// 	vec.push_back(Point(783,773));
// 	vec.push_back(Point(-261,-187));
// 	vec.push_back(Point(-609,-507));
// 	vec.push_back(Point(-261,-187));
// 	vec.push_back(Point(-87,-27));
// 	vec.push_back(Point(87,133));
// 	vec.push_back(Point(783,773));
// 	vec.push_back(Point(-783,-667));
// 	vec.push_back(Point(-609,-507));
// 	vec.push_back(Point(-435,-347));
// 	vec.push_back(Point(783,773));
// 	vec.push_back(Point(-870,-747));
// 	vec.push_back(Point(87,133));
// 	vec.push_back(Point(87,133));
// 	vec.push_back(Point(870,853));
// 	vec.push_back(Point(696,693));
// 	vec.push_back(Point(0,53));
// 	vec.push_back(Point(174,213));
// 	vec.push_back(Point(-783,-667));
// 	vec.push_back(Point(-609,-507));
// 	vec.push_back(Point(261,293));
// 	vec.push_back(Point(435,453));
// 	vec.push_back(Point(261,293));
// 	vec.push_back(Point(435,453));

// 
	vec.push_back(Point(0, 1));
	vec.push_back(Point(1, 2));
	vec.push_back(Point(0, -1));
	vec.push_back(Point(1, 0));
	vec.push_back(Point(2, 3));

	printf("Max %d\n", maxPoints2(vec));

	system("pause");

	return 0;
}