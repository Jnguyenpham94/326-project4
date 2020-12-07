/**
 * FCFS scheduling
 */
 
#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

Task taskList[10];
int i = 0;

//Your code and design here
void add(char *name, int priority, int burst)
{
    //saves values of the current line of text into the current location
    taskList[i].name = name;
    taskList[i].priority = priority;
    taskList[i].burst = burst;
    i++;
}

void schedule()
{
    int length = sizeof(taskList)/sizeof(taskList[0]);//size of tasklist
    for(int j=0; j < length; j++){//just outputs the taskList without any special priority stuff
        run(&taskList[j], taskList[j].burst);
    }
}