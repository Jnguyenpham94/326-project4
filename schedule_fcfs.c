/**
 * FCFS scheduling
 */
 
#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

struct node newNode;

//Your code and design here
void add(char *name, int priority, int burst)
{
    Task newTask;
    struct node newNode;
    newTask.name = name;
    newTask.priority = priority;
    newTask.burst = burst;
    insert(&newNode, &newTask);
}

void schedule()
{
    
}