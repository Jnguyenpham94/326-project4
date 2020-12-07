/**
 * Round-robin scheduling
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

Task taskList[6];
int length = sizeof(taskList) / sizeof(taskList[0]); //size of tasklist
int i = 0;
int count = 6;

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
    while(count > 0)
    {
        for (int j = 0; j < length; j++)
        { //outputs a quantum time until all burst values are 0
            if (taskList[j].burst == 0)
            {
                count--;
            }
            if (taskList[j].burst >= QUANTUM)
            {
                run(&taskList[j], QUANTUM);
                taskList[j].burst = taskList[j].burst - QUANTUM;
            }
            if (taskList[j].burst < QUANTUM)
            {
                run(&taskList[j], taskList[j].burst);
                taskList[j].burst = 0;
            }
        }
    }
}