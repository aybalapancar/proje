// saveLoadTasks.c
#include "tasks.h"
#include <stdio.h>

void saveTasks() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file) {
        printf("Dosya acilirken hatayla karsilasildi.\n");
        return;
    }

    fwrite(&taskCount, sizeof(int), 1, file);
    fwrite(tasks, sizeof(Task), taskCount, file);
    fclose(file);
}

void loadTasks() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("Kaydedilen gorev bulunamadi.Tekrar deneniyor.\n");
        return;
    }

    fread(&taskCount, sizeof(int), 1, file);
    fread(tasks, sizeof(Task), taskCount, file);
    fclose(file);
}

