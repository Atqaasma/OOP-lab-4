#include <iostream>
#include <list>
#include <string>
using namespace std;

class ToDoList {
public:
    string taskName;
    list<ToDoList> subTasks;

public:
    // Constructor for task name
    ToDoList(const string& name) : taskName(name) {}
    // Function to add a sub-task
    void addSubTask(const string& subTaskName) {
        subTasks.push_back(ToDoList(subTaskName));
    }
    // Function to display the to-do list and its sub-tasks
    void display(int level = 0) const {
        // Display current task
        cout << string(level * 4, ' ') << "- " << taskName << endl;

        // Display sub-tasks
        for (const auto& subTask : subTasks) {
            subTask.display(level + 1);
        }
    }
};

int main() {
    ToDoList mainList("TO DO List");
    mainList.addSubTask("DS; upcoming quiz preparation.");
    mainList.addSubTask("Diary writing.");
    mainList.addSubTask("GitHub setup.");
    mainList.addSubTask("OOP lab Tasks:");
    mainList.subTasks.back().addSubTask("Lab 4");
    mainList.subTasks.back().addSubTask("Lab 5");
    mainList.addSubTask("LA quiz on Monday");
    mainList.subTasks.back().addSubTask("Exe 1.4-1.8");
    mainList.display();

    return 0;
}
