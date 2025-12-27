#include "header.h"

// Function to add a new task
void atask(int index) {
    Task t;
    char filename[30];
    FILE *fp;

    sprintf(filename, "tasks_%d.txt", index);
    fp = fopen(filename, "a");
    if (!fp) {
        printf("Error: file not found\n");
        return;
    }

    printf("Enter task: ");
    getchar();  
    fgets(t.name, sizeof(t.name), stdin);
    t.name[strcspn(t.name, "\n")] = 0; 
    printf("Enter priority (High/Medium/Low): ");
    fgets(t.priority, sizeof(t.priority), stdin);
    t.priority[strcspn(t.priority, "\n")] = 0;
    if(t.priority[0]=='H' || t.priority[0]=='h')  strcpy(t.priority, "High");
    else if(t.priority[0]=='M' || t.priority[0]=='m') strcpy(t.priority, "Medium");
    else if(t.priority[0]=='L' || t.priority[0]=='l')  strcpy(t.priority, "Low");
    strcpy(t.completed, "pending");

    fprintf(fp, "%s;%s;%s\n", t.name, t.completed, t.priority);
    fclose(fp);
    
}

// Function to update an existing task
void utask(int index){ 
    clear();
    vtask(index);
    char filename[30];
    FILE *fp;
    char line[200];
    Task tasks[100];
    int count = 0, task_num;
    char new_name[100], new_priority[10];

    sprintf(filename, "tasks_%d.txt", index);
    fp = fopen(filename, "r+");
    if (!fp) {
        printf("Error: file not found\n");
        return;
    }


    while (fgets(line, sizeof(line), fp)) {
        int j = 0, k = 0;
        while (line[j] != ';') {
            tasks[count].name[k++] = line[j++];
        }
        tasks[count].name[k] = '\0';
        if (line[j] == ';') j++;
        k = 0;
        while (line[j] != ';') {
            tasks[count].completed[k++] = line[j++];
        }
        tasks[count].completed[k] = '\0';
        if (line[j] == ';') j++;
        
        k = 0;
        while (line[j] != '\0' && line[j] != '\n') {
            tasks[count].priority[k++] = line[j++];
        }
        tasks[count].priority[k] = '\0';
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\nEnter the task number to update: ");
    scanf("%d", &task_num);
    if (task_num < 1 || task_num > count) {
        printf("Invalid task number.\n");
        return;
    }
    printf("Enter the new task name: ");
    getchar();  
    fgets(new_name, sizeof(new_name), stdin);
    new_name[strcspn(new_name, "\n")] = 0;  
    printf("Enter the new priority (High/Medium/Low): ");
    fgets(new_priority, sizeof(new_priority), stdin);
    new_priority[strcspn(new_priority, "\n")] = 0;

    strcpy(tasks[task_num - 1].name, new_name);
    strcpy(tasks[task_num - 1].priority, new_priority);

    fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Unable to open file for writing\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s;%s;%s\n", tasks[i].name, tasks[i].completed, tasks[i].priority);
    }
    fclose(fp);
    
}

// Function to delete an existing task
void dtask(int index, int task_num) {
    char filename[30];
    FILE *fp;
    char line[200];
    Task tasks[100];
    int count = 0;

    sprintf(filename, "tasks_%d.txt", index);
    fp = fopen(filename, "r+");
    if (!fp) {
        printf("Error: file not found\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        int j = 0, k = 0;
        while (line[j] != ';') {
            tasks[count].name[k++] = line[j++];
        }
        tasks[count].name[k] = '\0';
        if (line[j] == ';') j++;
        
        k = 0;
        while (line[j] != ';') {
            tasks[count].completed[k++] = line[j++];
        }
        tasks[count].completed[k] = '\0';
        if (line[j] == ';') j++;
        
        k = 0;
        while (line[j] != '\0' && line[j] != '\n') {
            tasks[count].priority[k++] = line[j++];
        }
        tasks[count].priority[k] = '\0';
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("No tasks available.\n");
        return;
    }

    if (task_num < 1 || task_num > count) {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = task_num - 1; i < count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Unable to open file for writing\n");
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        fprintf(fp, "%s;%s;%s\n", tasks[i].name, tasks[i].completed, tasks[i].priority);
    }
    fclose(fp);
   
}

// Function to mark a task as completed
void mark_task_complete(int index) {
    clear();
    vtask(index);
    char filename[30];
    FILE *fp;
    char line[200];
    Task tasks[100];
    int count = 0, task_num;
    sprintf(filename, "tasks_%d.txt", index);
    fp = fopen(filename, "r+");
    if (!fp) {
        printf("Error: file not found\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        int j = 0, k = 0;
        while (line[j] != ';') {
            tasks[count].name[k++] = line[j++];
        }
        tasks[count].name[k] = '\0';
        if (line[j] == ';') j++;
        k = 0;
        while (line[j] != ';') {
            tasks[count].completed[k++] = line[j++];
        }
        tasks[count].completed[k] = '\0';
        if (line[j] == ';') j++;
        
        k = 0;
        while (line[j] != '\0' && line[j] != '\n') {
            tasks[count].priority[k++] = line[j++];
        }
        tasks[count].priority[k] = '\0';
        count++;
    }
    fclose(fp);
    if (count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\nEnter the task number to mark as completed: ");
    scanf("%d", &task_num);
    if (task_num < 1 || task_num > count) {
        printf("Invalid task number.\n");
        return;
    }
    strcpy(tasks[task_num - 1].completed, "done");

    for (int i = task_num - 1; i < count - 1; i++) {
        tasks[i] = tasks[i + 1]; 
    }
    count--; 
    fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Unable to open file for writing\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s;%s;%s\n", tasks[i].name, tasks[i].completed, tasks[i].priority);
    }
    fclose(fp);

    
}

//Fucntion to view task list
void vtask(int index) {
    char filename[30];
    sprintf(filename, "tasks_%d.txt", index);
    FILE *fp;
    fp = fopen(filename, "r");
    if (!fp) {
        printf("No tasks available.\n");
        return;
    } 
    char line[200];
    Task tasks[100];
    int count = 0;
    
   
    while (fgets(line, sizeof(line), fp)) {
        int j = 0, k = 0;
        while (line[j] != ';' && line[j] != '\0' && line[j] != '\n') {
            tasks[count].name[k++] = line[j++];
        }
        tasks[count].name[k] = '\0';
        if (line[j] == ';') j++;

        k = 0;
        while (line[j] != ';' && line[j] != '\0' && line[j] != '\n') {
            tasks[count].completed[k++] = line[j++];
        }
        tasks[count].completed[k] = '\0';
        if (line[j] == ';') j++;
        k = 0;
        while (line[j] != '\0' && line[j] != '\n') {
            tasks[count].priority[k++] = line[j++];
        }
        tasks[count].priority[k] = '\0';

        count++;
    }
    fclose(fp);
    if (count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("Your Tasks:\n---------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. [%s] %s - Priority: %s\n", i + 1, tasks[i].completed, tasks[i].name, tasks[i].priority);
    }
}


