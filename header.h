#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int signin(int *index);
void signup();

typedef struct {
    char name[100];
    char completed[10];
    char priority[10]; 
} Task;


void atask(int index);
void vtask(int index);
void utask(int index);
void dtask(int index, int task_num);
void mark_task_complete(int index);
void menu1();
void menu2(int index);
int priority_value(const char *priority);
void stask(int index);
void clear();
 
