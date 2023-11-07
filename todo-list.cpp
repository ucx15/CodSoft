#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    cout << "------ To-Do List Manager ------\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Quit\n";


    vector<string> tasks;  // Vector to store tasks
    
	int choice;
    string task;


    while (true) {
        cout << "\n> ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\t ";
                getline(cin, task);
                tasks.push_back(task);
                cout << "added!\n";
                break;

            case 2:
                if (tasks.empty()) {
                    cout << "No tasks to display.\n";
                }
				else {
                    cout << "Tasks:" << endl;
                    for (size_t i=0; i<tasks.size(); ++i) {
                        cout << (i+1) << ". " << tasks[i] << endl;
                    }
                }
                break;

            case 3:
                if (tasks.empty()) {
                    cout << "No tasks to delete." << endl;
                }
				else {
                    int taskIndex;
                    cout << "Task to delete: ";
                    cin >> taskIndex;

                    if ((taskIndex > 0) && static_cast<size_t>(taskIndex) < (tasks.size()+1)) {
                        tasks.erase(tasks.begin() + taskIndex-1);
                        cout << "Task deleted!\n";
                    }
					else {
                        cout << "Invalid task number. No task deleted.\n";
                    }
                }
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
