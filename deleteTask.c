// deleteTask.c
#include "tasks.h"
#include <stdio.h>

void deleteTask() {
    int id, i, found = 0;
    printf("Silmek için gorev numarasi girin: ");
    scanf("%d", &id);

    for (i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        printf("Gorev basariyla silindi.\n");
    } else {
        printf("Gorev bulunamadi.\n");
    }
}

