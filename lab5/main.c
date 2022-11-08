#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Вивід на екран користувача матрицю
void print_matrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%9.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int task() {
    float** A;
    int enter, num, n, m;
    // Введення масивів та виділення памяті для них
    printf("\nВведіть кількість рядків матриці A: ");
    scanf("%d", &n);
    printf("Введіть кількість стовпців матриці A: ");
    scanf("%d", &m);
    A = (float**)malloc(n * sizeof(float*)); // Виділення памяті для масиву матриці A
    for (int i = 0; i < n; i++) {
        A[i] = (float*)malloc(m * sizeof(float));
    }
    //Введення елементів матриці
    printf("\nВведення чисел вручну - 1, введення чисел випадково - 2: ");
    scanf("%d", &enter);
    if (enter == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("Введіть елемент A[%d][%d]: ", i, j);
                scanf("%f", &A[i][j]);
            }
        }
    } else if (enter == 2) {
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = rand() % 201 - 100;
            }
        }
    }
    // Виведення матриці
    printf("\nМатриця A:\n");
    print_matrix(A, n, m);
    // Виведення суми мінімальних елементів кожного стовпця
    int min; // Мінімальний елемент кожного стовпця
    float sum = 0; // Сума мінімальних елементів кожного стовпця
    for (int i = 0; i < m; i++) { // Проходження по стовпцям
        min = A[0][i]; // Записування першого елемента кожного стовпця у змінну min
        for (int j = 0; j < n; j++) { // Проходження по рядкам
            if (A[j][i] < min) { // Якщо елемент матриці менший за мінімальний, то записуємо його у змінну min
                min = A[j][i]; // Записування елемента в змінну min
            }
        }
        sum += min; // Додавання мінімального елемента кожного стовпця до суми
    }
    // Виведення результату
    printf("\nСума мінімальних елементів кожного стовпця: %f\n", sum);
    //Робимо простір вільним
    for (int i = 0; i < n; i++) {
        free(A[i]); // Видалення пам'яті від масиву матриці A
    }
    free(A); // Видалення пам'яті від масиву матриці A
    return 0;
}

int main() {
    printf("\n┌────────────────────────────────────────────────────────────────────────────────────────────┐");
    printf("\n│                               Лабораторна робота №5                                        │");
    printf("\n│                                                                                            │");
    printf("\n│                       Тема: «Динамічне виділення пам'яті»                                  │");
    printf("\n│                                                                                            │");
    printf("\n│  Виконав Данилюк Д.А., КМ-13                                          Любашенко Н. Д.      │");
    printf("\n│                                                                                            │");
    printf("\n│                                                                                            │");
    printf("\n│                                         2022                                               │");
    printf("\n└────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n1 - Дано матрицю A розмірності m*n. Знайти суму мінімальних елементів кожного стовпця матриці.\n");
    task();
    return 0;
}
