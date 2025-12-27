# C Todo List Application
A modular, console-based task manager built in C featuring user authentication and file-based storage.

## 🚀 Features
* **User Authentication:** Create an account and sign in to access your personal task list.
* **Task Management:** Add new tasks, update existing ones, or delete them easily.
* **Completion Tracking:** Mark tasks as "done" or "pending."
* **Priority Sorting:** Automatically reorder your list by High, Medium, or Low priority.
* **Persistent Storage:** Your tasks are saved in individual text files (`tasks_ID.txt`) so they are there next time you log in.

## 🛠️ How to Compile and Run
Because this project is split into multiple `.c` files, you must compile them all together. 

**Using GCC:**
```bash
gcc main.c auth.c func.c menu.c sort.c task.c -o todo_app
