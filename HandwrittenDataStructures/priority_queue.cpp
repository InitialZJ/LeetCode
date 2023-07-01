#include <queue>
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <limits.h>
using namespace std;

class PriorityQueue
{
private:
    vector<int> nums;

public:
    PriorityQueue();
    ~PriorityQueue();
    bool empty();
    int size();
    void push(int v);
    void pop();
    int top();
    int left(int i);
    int parent(int i);
    void heapfy();
};

PriorityQueue::PriorityQueue()
{
    nums = vector<int>();
}

PriorityQueue::~PriorityQueue()
{
}

bool PriorityQueue::empty()
{
    return size() == 0;
}

int PriorityQueue::size()
{
    return nums.size();
}

void PriorityQueue::push(int v)
{
    nums.push_back(v);
    int i = size() - 1;
    while (parent(i) >= 0 && nums[parent(i)] < v)
    {
        swap(nums[i], nums[parent(i)]);
        i = parent(i);
    }
}

int PriorityQueue::left(int i)
{
    return i * 2 + 1;
}

int PriorityQueue::parent(int i)
{
    return (i - 1) >> 1;
}

int PriorityQueue::top()
{
    return nums[0];
}

void PriorityQueue::pop()
{
    nums[0] = nums[size() - 1];
    heapfy();
    nums.pop_back();
}

void PriorityQueue::heapfy()
{
    int index = 0;
    while (index * 2 + 1 < size())
    {
        int child = index * 2 + 1;
        if (child + 1 < size() && nums[child] < nums[child + 1])
            ++child;
        if (nums[index] < nums[child])
        {
            swap(nums[index], nums[child]);
            index = child;
        }
        else
            break;
    }
}

int main()
{
    priority_queue<int, vector<int>, less<int>> pq1;
    PriorityQueue pq2;

    if (pq1.empty() != pq2.empty() || pq1.size() != pq2.size())
        cout << "Error" << endl;

    default_random_engine e;
    uniform_int_distribution<int> u(INT_MIN, INT_MAX);
    e.seed(time(0));
    for (int i = 0; i < 100000; i++)
    {
        int r = u(e);
        pq1.push(r);
        pq2.push(r);

        if (pq1.empty() != pq2.empty() || pq1.size() != pq2.size() || pq1.top() != pq2.top())
            cout << "Error" << endl;
    }
    for (int i = 0; i < 100000 - 1; i++)
    {
        pq1.pop();
        pq2.pop();

        if (pq1.empty() != pq2.empty() || pq1.size() != pq2.size() || pq1.top() != pq2.top())
            cout << "Error" << endl;
    }
    pq1.pop();
    pq2.pop();

    if (pq1.empty() != pq2.empty() || pq1.size() != pq2.size() || pq2.size() != 0)
        cout << "Error" << endl;
    return 0;
}