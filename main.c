// main.c
#include <stdio.h>
#include "tasks.h"

int main() {
    loadTasks();
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                editTask();
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                saveTasks();
                printf("Gorev basariyla kaydedildi.\n");
                break;
            case 0:
                printf("Cikis yapiliyor.\n");
                break;
            default:
                printf("Gecersiz secim.Tekrar deneyin.\n");
        }
    } while (choice != 0);

    return 0;
}

