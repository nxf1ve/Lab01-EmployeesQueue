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
        int value = rand();
        vec.push_back(value);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for push(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}

void measureVectorPop(vector<int>& vec, int count) {
    for (int i = 0; i < count; i++) {
        vec.push_back(rand());
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
        int value = rand();
        stk.push(value);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for push(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}

void measureStackPop(stack<int>& stk, int count) {
    for (int i = 0; i < count; i++) {
        stk.push(rand());
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
        int value = rand();
        q.push(value);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for push(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}

void measureQueuePop(queue<int>& q, int count) {
    for (int i = 0; i < count; ++i) {
        q.push(rand());
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
        int key = rand();
        int value = rand();
        m[key] = value;
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for insert(" << count << " elements): " << fixed << elapsedTime.count() << " seconds" << endl;
}

void measureMapErase(map<int, int>& m, int count) {
    for (int i = 0; i < count; ++i) {
        int key = rand();
        m[key] = rand();
    }
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        int key = rand();
        m.erase(key);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for erase(" << count << " elements): " << fixed << elapsedTime.count() << " seconds" << endl;
}

void measureUnorderedMapInsert(unordered_map<int, int>& um, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        int key = rand();
        int value = rand();
        um[key] = value;
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for insert(" << count << " elements): " << fixed << elapsedTime.count() << " seconds" << endl;
}

void measureUnorderedMapEmplace(unordered_map<int, int>& um, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        int key = rand();
        int value = rand();
        um.emplace(key, value);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for emplace(" << count << " elements): " << fixed << elapsedTime.count() << " seconds" << endl;
}

void measureUnorderedMapErase(unordered_map<int, int>& um, int count) {
    for (int i = 0; i < count; ++i) {
        int key = rand();
        um[key] = rand();
    }
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        int key = rand();
        um.erase(key);
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for erase(" << count << " elements): " << fixed << elapsedTime.count() << " seconds" << endl;
}