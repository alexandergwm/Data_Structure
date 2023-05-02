#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class TaskDelegation{
public: 
    void newTask(int id, int difficulty)
    {
        taskHeap.push({difficulty,id});
    }

    int requestTask()
    {
        if(taskHeap.empty())
        {
            return -1;
        }

        int taskId = taskHeap.top().second;
        taskHeap.pop();
        return taskId;
    }

private:
    priority_queue<pair<int,int>> taskHeap;
};

int main() {
    TaskDelegation taskDelegation;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "N") {
            int id, difficulty;
            cin >> id >> difficulty;
            taskDelegation.newTask(id, difficulty);
        } else if (operation == "R") {
            cout << taskDelegation.requestTask() << endl;
        }
    }

    return 0;
}