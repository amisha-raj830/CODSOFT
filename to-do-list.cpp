#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
    }

    void viewTasks() {
        cout << "TO-DO LIST:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "TASK " << (i + 1) << ": " << tasks[i].description;
            if (tasks[i].completed) {
                cout << " [COMPLETED]";
            }
            cout << "\n";
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void removeTask(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task removed.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoList todo;
    int choice;

    do {
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();  // Clear newline from input buffer
                getline(cin, taskDescription);
                todo.addTask(taskDescription);
                break;
            }
            case 2:
                todo.viewTasks();
                break;
            case 3: {
                size_t index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todo.markTaskCompleted(index - 1);  // Adjust index for 0-based vector
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                todo.removeTask(index - 1);  // Adjust index for 0-based vector
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while(choice!=5);
    return 0;
}