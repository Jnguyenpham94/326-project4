/*
 * Priority scheduling
 */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

Task taskList[8];
int i = 0;

/*
 * Your code and design here:
 */
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
    int length = sizeof(taskList) / sizeof(taskList[0]); //size of tasklist
    Task tempTask; //temporary storage for Task struct
    int i, j;
    //basically a modified insertion sort for priority
    for (i = 1; i < length; i++)
    {
        tempTask = taskList[i];
        j = i-1;
        while(j >= 0 && taskList[j].priority > tempTask.priority)
        {
            taskList[j+1] = taskList[j];
            j = j-1;
        }
        taskList[j+1] = tempTask;
    }
    //prints out the output
    for (int l = 0; l < length; l++)
    {
        run(&taskList[l], taskList[l].burst);
    }
}
