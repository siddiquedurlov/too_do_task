#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

// Declare an array to hold tasks
char tasks[MAX_TASKS][MAX_LENGTH];
int task_count = 0;

// Function to add a task
void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached!\n");
        return;
    }

    printf("Enter the task: ");
    getchar(); // To capture the new line character after previous input
    fgets(tasks[task_count], MAX_LENGTH, stdin);
    tasks[task_count][strcspn(tasks[task_count], "\n")] = 0; // Remove newline char
    task_count++;
    printf("Task added successfully!\n");
}

// Function to view all tasks
void view_tasks() {
    if (task_count == 0) {
        printf("No tasks to display!\n");
        return;
    }

    printf("To-Do List:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

// Function to delete a task
void delete_task() {
    int task_number;
    printf("Enter task number to delete: ");
    scanf("%d", &task_number);

    if (task_number < 1 || task_number > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    // Shift tasks up to remove the deleted task
    for (int i = task_number - 1; i < task_count - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }

    task_count--;
    printf("Task deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                delete_task();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
