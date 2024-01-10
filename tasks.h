// tasks.h

#ifndef TASKS_H
#define TASKS_H

#define FILE_NAME "tasks.dat"
#define MAX_TASKS 100
#define TASK_NAME_LEN 50
#define TASK_DESC_LEN 200

// Task structure
typedef struct {
    int id;
    char name[TASK_NAME_LEN];
    char description[TASK_DESC_LEN];
} Task;

extern Task tasks[MAX_TASKS];
extern int taskCount;

// Function declarations
void addTask();
void deleteTask();
void editTask();
void saveTasks();
void loadTasks();
void displayTasks();
void displayMenu();

#endif

