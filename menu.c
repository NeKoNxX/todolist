#include "header.h"

void menu1() {
    printf("Welcome to the To-Do App!\n");
    printf("1. Sign In\n");
    printf("2. Sign Up\n");
    printf("3. Exit\n");
}

void menu2(int index) {
    int choice;
    char username[50], password[50];
    vtask(index);
    printf("\n");
    sleep(1);
    printf("What would you like to do ?? \n------------------------------------\n");
    printf("1. Add Task\n");
    printf("2. Update Task\n");
    printf("3. Delete Task\n");
    printf("4. Mark Task Complete\n");
    printf("5. Rearrange Task list according to priority\n");
    printf("6. Sign Out\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            atask(index);
            clear();
            printf("Task added successfully!\n");
            sleep(1);
            menu2(index);
            break;
        case 2:
            utask(index);
            clear();
            printf("Task updated successfully.\n");
            sleep(1);
            menu2(index);
            break;
        case 3:
            {   
                clear();
                vtask(index);
                int task_num;
                printf("Enter the task number to delete: ");
                scanf("%d", &task_num);
                dtask(index, task_num); 
                clear();
                printf("Task deleted successfully.\n");
                sleep(1);
                menu2(index);  
            }
            break;
        case 4:
            mark_task_complete(index);
            clear();
            printf("Task marked as completed.\n");
            sleep(1);
            menu2(index);
            break;
        case 5:
            stask(index);
            clear();
            printf("Task list reordered successfully.\n");
            sleep(1);
            menu2(index);
            break;
        case 6:
            clear();
            printf("You have logged out.\n");
            sleep(1);
            break;
        default:
            clear();
            printf("Invalid choice!\n");
            sleep(1);
            menu2(index);
            break;
    }
}
