// displayTasks.c
#include "tasks.h"
#include <stdio.h>

void displayTasks() {
    int i;
    if (taskCount == 0) {
        printf("Gosterilecek gorev yok.\n");
        return;
    }

    for (i = 0; i < taskCount; i++) {
        printf("Gorev: %d, Isim: %s, Tanim: %s\n", tasks[i].id, tasks[i].name, tasks[i].description);
    }
}

