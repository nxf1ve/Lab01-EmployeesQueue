#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
using namespace std;
using namespace std::chrono;

void measureVectorPush(vector<int>& vec, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; i++) {
        vec.push_back(i);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for push(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}
void measureVectorPop(vector<int>& vec, int count) {
    for (int i = 0; i < count; i++) {
        vec.push_back(i);
    }
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; i++) {
        vec.pop_back();
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for pop(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}

void measureStackPush(stack<int>& stk, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        stk.push(i);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for push(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}

void measureStackPop(stack<int>& stk, int count) {
    for (int i = 0; i < count; i++) {
        stk.push(i);
    }
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        if (!stk.empty()) {
            stk.pop();
        }
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for pop(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}

void measureQueuePush(queue<int>& q, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        q.push(i);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for push(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}

void measureQueuePop(queue<int>& q, int count) {
    for (int i = 0; i < count; ++i) {
        q.push(i);
    }

    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        if (!q.empty()) {
            q.pop();
        }
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for pop(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}

void measureMapInsert(map<int, int>& m, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        m[i] = i;
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for insert(" << count << " elements): " << fixed << elapsedTime.count() << " seconds" << endl;
}

void measureMapErase(map<int, int>& m, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        m.erase(i);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for erase(" << count << " elements): " << fixed << elapsedTime.count() << " seconds" << endl;
}

void measureUnorderedMapInsert(unordered_map<int, int>& um, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        um[i] = i;
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for insert(" << count << " elements): " << fixed << elapsedTime.count() << " seconds" << endl;
}
void measureUnorderedMapErase(unordered_map<int, int>& um, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        um.erase(i);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for erase(" << count << " elements): " << fixed << elapsedTime.count() << " seconds" << endl;
}