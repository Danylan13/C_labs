#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *i, int *j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

void task_1() {
    system("clear");
    int A[100], enter, n, num;
    //Ввід
    printf("Введіть розмір масиву (не быльше 100): ");
    scanf("%d", &n);
    printf("Ви бажаєте ввести числа вручну(1) чи обрати випадково(2)?\n");
    printf("Оберіть: ");
    scanf("%d", &enter);
    if (enter == 1) {
        for (int i = 0; i < n; i++) {
            printf("A[%d] = ", i);
            scanf("%d", &num);
            A[i] = num;
        }
    }
    else {
        printf("Масив буде сформовано з чисел від 0 до 100\n");
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            A[i] = rand()%101;
        }
    }
    //Вивід
    printf("A: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    //Сортування
    int temp, ind;
    for (int i = 1; i < n; i++) {
        temp = A[i];
        ind = i - 1;
        while (ind >= 0 && A[ind] % 2 != 0) {
            A[ind + 1] = A[ind];
            A[ind] = temp;
            ind--;
        }
    }
    //Результат
    printf("\nA: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}

void task_2() {
    system("clear");
    int A[100], enter, n, num;
    //Ввід
    printf("Введіть розмір масиву (не быльше 100): ");
    scanf("%d", &n);
    printf("Ви бажаєте ввести числа вручну(1) чи обрати випадково(2)?\n");
    printf("Оберіть: ");
    scanf("%d", &enter);
    if (enter == 1) {
        for (int i = 0; i < n; i++) {
            printf("A[%d] = ", i);
            scanf("%d", &num);
            A[i] = num;
        }
    }
    else {
        printf("Масив буде сформовано з чисел від 0 до 100\n");
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            A[i] = rand()%101;
        }
    }
    //Вивід
    printf("A: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    //Метод лінійної вставки
    int temp, lnd;
    for (int i = 1; i < n; i++) {
        temp = A[i];
        lnd = i - 1;
        while(lnd >= 0 && A[lnd] > temp) {
        A[lnd + 1] = A[lnd];
        A[lnd] = temp;
        lnd--;
        }
    }
    //Результат
    printf("\nA: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}

void task_3() {
    system("clear");
    int A[100][100], size;
    int num, enter;
    //Ввід
    printf("Введіть розмір матриці (до 100): ");
    scanf("%d", &size);
    printf("Ви бажаєте ввести числа вручну(1) чи обрати випадково(2)?\n");
    printf("Оберіть: ");
    scanf("%d", &enter);
    if (enter == 1) {
        for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            printf("Введіть елемент a%d%d: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    else {
        printf("Масив буде сформовано з чисел від -100 до 100");
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % 201 - 100;       //Діапазон від -100 до 100
        }
    }
    // Вивід матриці А[][]
    printf("\nA[][]: \n");
    for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) {
        printf("%d  ", A[i][j]);
        if (j == size - 1)
        printf("\n");
    }
    printf("\n");
    //Перекид від'ємних елементів вище побічної діагоналі
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j < i && A[i][j] < 0) {
                swap (&A[i][j], &A[j][i]);
            }
        }
    }
    //Результат
    printf("\nA[][]: \n");
    for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) {
        printf("%d  ", A[i][j]);
        if (j == size - 1)
        printf("\n");
    }
}

int main() {
    printf("\n┌────────────────────────────────────────────────────────────────────────────────────────────┐");
    printf("\n│                               Лабораторна робота №2                                        │");
    printf("\n│                                                                                            │");
    printf("\n│                   Тема: «Одновимірні та двовимірні масиви»                                 │");
    printf("\n│                                                                                            │");
    printf("\n│  Виконав Данилюк Д.А., КМ-13                                          Любашенко Н. Д.      │");
    printf("\n│                                                                                            │");
    printf("\n│                                                                                            │");
    printf("\n│                                         2022                                               │");
    printf("\n└────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n1 - Дано одновимірний масив A, що складається з n елементів. Перенести в початок масиву всі парні елементи, а в кінець масиву - усі непарні\n");
    printf("2 - Впорядкувати масив методом лінійної вставки\n");
    printf("3 - Дано матрицю з цілих чисел. Зібрати всі від’ємні елементи вище за\n");
    printf("побічну діагональ (заповнення здійснювати за рядками)\n");
    int answer;
    printf("\nОберіть завдання: ");
    scanf("%d", &answer);
    switch (answer) {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        case 3:
            task_3();
            break;
    }
    return 0;
}
