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


Task taskList[8]; // size will need to change for larger sizes.
int length = sizeof(taskList)/sizeof(taskList[0]); //size of tasklist
int i = 0;
int count = 8;

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
                continue;
            }
            if (taskList[j].burst >= QUANTUM)
            {
                run(&taskList[j], QUANTUM);
                taskList[j].burst = taskList[j].burst - QUANTUM;
            }
            else if (taskList[j].burst < QUANTUM)
            {
                run(&taskList[j], taskList[j].burst);
                taskList[j].burst = 0;
            }
        }
    }
}