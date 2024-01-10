// editTask.c
#include "tasks.h"
#include <stdio.h>

void editTask() {
    int id, i, found = 0;
    printf("Duzenlemek icin gorev numarasi girin: ");
    scanf("%d", &id);

    for (i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Yeni gorev adi girin: ");
        scanf("%s", tasks[i].name);
        printf("Yeni gorev tanimi ekleyin: ");
        scanf("%s", tasks[i].description);
        printf("Gorev degistirildi.\n");
    } else {
        printf("Gorev bulunamadi.\n");
    }
}

