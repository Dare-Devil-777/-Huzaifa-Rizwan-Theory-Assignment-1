#include <iostream>
#include <string>

using namespace std;

// Node structure for a task

struct Task {
    int taskId;
    string description;
    int priority;
    Task* next;
};


// Function to create a new task node

Task* createTask(int id, string desc, int priority) {
    Task* newTask = new Task;
    newTask->taskId = id;
    newTask->description = desc;
    newTask->priority = priority;
    newTask->next = nullptr;
    return newTask;
}


// Function to insert a new task at the correct position based on priority

void insertTask(Task*& head, Task* newTask) {
    if (head == nullptr || newTask->priority >= head->priority) {
        newTask->next = head;
        head = newTask;
    } else {
        Task* current = head;
        while (current->next != nullptr && current->next->priority > newTask->priority) {
            current = current->next;
        }
        newTask->next = current->next;
        current->next = newTask;
    }
}


// Function to remove the task with the highest priority

void removeHighestPriorityTask(Task*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Task* temp = head;
    head = head->next;
    delete temp;
}


// Function to remove a task by its ID

void removeTaskById(Task*& head, int taskId) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->taskId == taskId) {
        Task* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Task* current = head;
    while (current->next != nullptr && current->next->taskId != taskId) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Task* temp = current->next;
        current->next = temp->next;
        delete temp;
    } else {
        cout << "Task with ID " << taskId << " not found." << endl;
    }
}


// Function to view all tasks

void viewTasks(Task* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Task* current = head;
    while (current != nullptr) {
        cout << "Task ID: " << current->taskId << endl;
        cout << "Description: " << current->description << endl;
        cout << "Priority: " << current->priority << endl;
        cout << endl;
        current = current->next;
    }
}

int main() {
    Task* head = nullptr;
    int choice;

    while (true) {
        cout << "1. Add a new task" << endl;
        cout << "2. View all tasks" << endl;
        cout << "3. Remove the highest priority task" << endl;
        cout << "4. Remove a task by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, priority;
                string description;
                cout << "Enter task ID: ";
                cin >> id;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, description);
                cout << "Enter priority: ";
                cin >> priority;
                Task* newTask = createTask(id, description, priority);
                insertTask(head, newTask);
                break;
            }
            case 2:
                viewTasks(head);
                break;
            case 3:
                removeHighestPriorityTask(head);
                break;
            case 4: {
                int taskId;
                cout << "Enter task ID to remove: ";
                cin >> taskId;
                removeTaskById(head, taskId);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
