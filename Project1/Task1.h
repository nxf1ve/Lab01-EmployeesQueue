#pragma once
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;
void measureVectorPush(vector<int>& vec, int count);
void measureVectorPop(vector<int>& vec, int count);
void measureStackPush(stack<int>& stk, int count);
void measureStackPop(stack<int>& stk, int count);
void measureQueuePush(queue<int>& q, int count);
void measureQueuePop(queue<int>& q, int count);
void measureMapInsert(map<int, int>& m, int count);
void measureMapErase(map<int, int>& m, int count);
void measureUnorderedMapInsert(unordered_map<int, int>& um, int count);
void measureUnorderedMapErase(unordered_map<int, int>& um, int count);