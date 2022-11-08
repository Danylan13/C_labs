#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void title_page() {
    printf("\n┌────────────────────────────────────────────────────────────────────────────────────────────┐");
    printf("\n│                                  Лабораторна робота №3                                     │");
    printf("\n│                                                                                            │");
    printf("\n│                          Тема: 'Опрацювання символьних даних'                              │");
    printf("\n│                                                                                            │");
    printf("\n│  Виконав: Данилюк Д.А., КМ-13                                       Любашенко Н.Д.         │");
    printf("\n│                                                                                            │");
    printf("\n│                                                                                            │");
    printf("\n│                                         2022                                               │");
    printf("\n└────────────────────────────────────────────────────────────────────────────────────────────┘\n");
}

void task_1() {
    char str[500];
    int amount = 0;

    printf("Введіть речення: ");
    fgets(str, 500, stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
        char next;
        int n = 0;

        while (!isalpha(str[i + 1 + n]) || isdigit(str[i + 1 + n])) {
            n += 1;
        }
        next = str[i + 1 + n];

        char previous;
        int m = 0;

        while (!isalpha(str[i - 1 - m]) || isdigit(str[i - 1 - m])) {
            m += 1;
        }
        previous = str[i - 1 - m];

        if (tolower(previous) == tolower(next)) {
            amount += 1;
        }
        i += m;
        }
    }
    printf("Кількість слів, які починаються на букву, на якій закінчується попереднє слово: %d\n", amount);
}

int main(){
  title_page();
  task_1();
}
