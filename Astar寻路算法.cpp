// ConsoleApplication8.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#include <stdio.h>
#include "stdafx.h"
#include <stdarg.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int kCost1 = 10;//直移一格消耗
const int kCost2 = 14;//斜移一格消耗

struct Point {
	int x, y;
	int F, G, H;
	Point * parent;
	Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL) {

	}
};




class Astar {
public :
	void InitAstar(std::vector<vector<int>> &_maze);
	std::list<Point*> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
	
private:
	Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
	std::vector<Point *> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;
	bool isCanreach(const Point*point, const Point * target, bool isIgnoreCornet) const;
	Point *isInList(const std::list<Point*> &list, const Point *point)const;
	Point * getLeastFPoint();

	int calcG(Point *temp_start, Point *point);
	int calcH(Point *point, Point *end);
	int calcF(Point *point);


private:
	std::vector<std::vector<int>> maze;
	std::list<Point *> openList;
	std::list<Point *> closeList;
};

void Astar::InitAstar(std::vector<std::vector<int>> &_maze) {
	maze = _maze;
}

int Astar::calcG(Point * temp_start, Point * point) {
	int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y)) == 1 ? kCost1 : kCost2;
	int parentG = point->parent == NULL ? 0 : point->parent->G;
	return parentG + extraG;
}

int Astar::calcH(Point *point, Point *end) {
	return sqrt((double)(end->x - point->x)*(double)(end->x - point->x) + (double)(end->y - point->y)*(double)(end->y - point->y))*kCost1;
}

int Astar::calcF(Point *point) {
	return point->G + point->H;
}

Point* Astar::getLeastFPoint() {
	if (!openList.empty()) {
		auto resPoint = openList.front();
		for (auto &point : openList) {
			if (point->F < resPoint->F) {
				resPoint = point;
			}
		}
		return resPoint;
	}
	return NULL;
}

Point* Astar::findPath(Point &startPoint, Point & endPoint, bool isIgnoreCorner) {
	openList.push_back(new Point(startPoint.x, startPoint.y));
	while (!openList.empty()) {
		auto curPoint = getLeastFPoint();
		openList.remove(curPoint);
		closeList.push_back(curPoint);

		auto surroundPoints = getSurroundPoints(curPoint,isIgnoreCorner);
		for (auto &target : surroundPoints) {
			if (!isInList(openList, target)) {
				target->parent = curPoint;
				target->G = calcG(curPoint,target);
				target->H = calcH(curPoint, target);
				target->F = calcF(target);

				openList.push_back(target);
			}
			else {
				int tempG = calcG(curPoint,target);
				if (tempG < target->G) {
					target->parent = curPoint;
					target->G = tempG;
					target->F = calcF(target);
				}
			}
			Point * resPoint = isInList(openList, &endPoint);
			if (resPoint)
				return resPoint;
		}
	}
	return NULL;
}

std::list<Point *> Astar::GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner) {
	Point *result = findPath(startPoint, endPoint, isIgnoreCorner);
	std::list<Point *> path;
	while (result) {
		path.push_front(result);
		result = result->parent;
	}
	return path;
}

Point *Astar::isInList(const std::list<Point *> &list, const Point* point) const
{
	for (auto p : list)
		if (p->x == point->x && p->y == point->y)
			return p;
	return NULL;
}

bool Astar::isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const
{
	if (target->x<0 || target->x>maze.size() - 1
		|| target->y<0 || target->y>maze[0].size() - 1
		|| maze[target->x][target->y] == 1
		|| target->x == point->x&& target->y == point->y
		|| isInList(closeList, target))
		return false;
	else {
		if (abs(point->x - target->x) + abs(point->y - target->y) == 1)
			return true;
		else {
			if (maze[point->x][target->y] == 0 && maze[target->x][target->y] == 0)
				return true;
			else
				return isIgnoreCorner;
		}
	}
}

std::vector<Point *> Astar::getSurroundPoints(const Point * point, bool isIgnoreCorner) const
{
	std::vector<Point *> surroundPoints;

	for (int x = point->x - 1; x <= point->x + 1; x++) {
		for (int y = point->y - 1; y <= point->y + 1; y++) {
			if (isCanreach(point, new Point(x, y), isIgnoreCorner)) {
				surroundPoints.push_back(new Point(x, y));
			}
		}
	}
	return surroundPoints;
}


int main(int argc, char** argv)
{
	vector<vector<int>>maze = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,1,1,0,1,0,0,0,0,1 },
		{ 1,0,0,1,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,1,0,0,1,1,1 },
		{ 1,1,1,0,0,0,0,0,1,1,0,1 },
		{ 1,1,0,1,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1 }
	};
	Astar astar;
	astar.InitAstar(maze);

	Point start(1,1);
	Point end(6, 10);
	list<Point *> path = astar.GetPath(start, end, false);

	for (auto &p : path) {
		cout << '(' << p->x << ',' << p->y << ')' << endl;
	}

	std::cin.get();
	return 0;
}