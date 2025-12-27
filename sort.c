#include "header.h"


//function to get priority value
int priority_value(const char *priority) {
    if (strcmp(priority, "High") == 0) return 0;
    else if (strcmp(priority, "Medium") == 0) return 1;
    else if (strcmp(priority, "Low") == 0) return 2;
    else return 100;
}

//function to sort task list
void stask(int index) {
    clear();
    char filename[30];
    FILE *fp;
    char line[200];
    Task tasks[100];
    int count = 0;

    sprintf(filename, "tasks_%d.txt", index);
    fp = fopen(filename, "r");
    if (!fp) return;
    while (fgets(line, sizeof(line), fp)) {
        int j = 0, k = 0;
        while (line[j] != ';') tasks[count].name[k++] = line[j++];
        tasks[count].name[k] = '\0'; j++; k = 0;
        while (line[j] != ';') tasks[count].completed[k++] = line[j++];
        tasks[count].completed[k] = '\0'; j++; k = 0;
        while (line[j] != '\0' && line[j] != '\n') tasks[count].priority[k++] = line[j++];
        tasks[count].priority[k] = '\0';
        count++;
    }
    fclose(fp);
    if (count == 0) return;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int p1 = priority_value(tasks[j].priority);
            int p2 = priority_value(tasks[j + 1].priority);
            if (p1 > p2) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    fp = fopen(filename, "w");
    if (!fp) return;
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s;%s;%s\n", tasks[i].name, tasks[i].completed, tasks[i].priority);
    }

    fclose(fp);
}
