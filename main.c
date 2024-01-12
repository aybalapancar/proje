#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "tasks.dat"
#define MAX_TASKS 100
#define TASK_NAME_LEN 50
#define TASK_DESC_LEN 200
#define MAX_USERS 5

typedef struct {
    int id;
    char name[TASK_NAME_LEN];
    char description[TASK_DESC_LEN];
} Task;

typedef struct {
    char username[20];
    char password[20];
} User;

Task tasks[MAX_TASKS];
int taskCount = 0;
User users[MAX_USERS] = {{"aybala", "1234"}, {"aybuke", "7890"}};
// Örnek kullanıcılar

void loginUser();
int authenticateUser(const char *username, const char *password);

void addTask();
void deleteTask();
void editTask();
void saveTasks();
void loadTasks();
void displayTasks();
void displayMenu();

int main() {
    loginUser();
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

void loginUser() {
    char enteredUsername[20];
    char enteredPassword[20];

    do {
        printf("Kullanici adinizi girin: ");
        scanf("%s", enteredUsername);
        printf("Sifrenizi girin: ");
        scanf("%s", enteredPassword);

        if (authenticateUser(enteredUsername, enteredPassword)) {
            printf("Giris basarili. Hos geldiniz, %s!\n", enteredUsername);
            break;
        } else {
            printf("Giris basarisiz. Tekrar deneyin.\n");
        }
    } while (1);
}

void displayMenu() {
    printf("\nGorev Planlayici1"
           "\n");
    printf("1. Gorev ekle\n");
    printf("2. Gorev sil\n");
    printf("3. Gorev duzenle\n");
    printf("4. Gorevleri goster\n");
    printf("5. Gorev kaydet\n");
    printf("0. Cikis\n");
    printf("Seciminizi giriniz: ");
}

int authenticateUser(const char *username, const char *password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Giriş başarılı
        }
    }
    return 0; // Giriş başarısız
}
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Gorev listesi dolu!\n");
        return;
    }

    Task newTask;
    newTask.id = taskCount + 1;
    printf("Gorev numarasi girin: ");
    scanf("%s", newTask.name);
    printf("Gorev tanimi girin: ");
    scanf("%s", newTask.description);

    tasks[taskCount++] = newTask;
    printf("Gorev basariyla eklendi.\n");
}
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

void deleteTask() {
    int id, i, found = 0;
    printf("Silmek icin gorev numarasi girin girin: ");
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
        printf("Yeni gorev numarasi girin: ");
        scanf("%s", tasks[i].name);
        printf("Yeni gorev tanimi ekleyin: ");
        scanf("%s", tasks[i].description);
        printf("Gorev degistirildi.\n");
    } else {
        printf("Task not found.\n");
    }
}
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
        printf("Kaydedilen gorev bulunamadi.\n");
        return;
    }

    fread(&taskCount, sizeof(int), 1, file);
    fread(tasks, sizeof(Task), taskCount, file);
    fclose(file);
}

