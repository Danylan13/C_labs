#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void title_page() {
    printf("\n┌────────────────────────────────────────────────────────────────────────────────────────────┐");
    printf("\n│                                  Laboratory work №1                                        │");
    printf("\n│                                                                                            │");
    printf("\n│ Theme: 'Base type of data, input-output, operations with bits, operations of bit shifting' │");
    printf("\n│                                                                                            │");
    printf("\n│  Completed by Danyliuk D.A., КМ-13                                   Lyubashenko N. D.     │");
    printf("\n│                                                                                            │");
    printf("\n│                                                                                            │");
    printf("\n│                                         2022                                               │");
    printf("\n└────────────────────────────────────────────────────────────────────────────────────────────┘\n");
}

void first_task () {
    float a, b, res;
    printf("Enter the first number: ");
    scanf("%f", &a);
    printf("Enter second number: ");
    scanf("%f", &b);
    res = pow(a - b, 2);
    printf("Squared difference of numbers: %.2f", res);
}

void second_task() {
    int b, volume, surface;
    printf("Enter a length of the edge of the cube: ");
    scanf("%d", &b);
    volume = b * b * b;
    surface = 6 * b * b;
    printf("Cube volume - %d\n", volume);
    printf("Total cube surface - %d", surface);
}

void third_task_packing() {
    int s, d, f, b, UnitStateWord;
    printf("Enter a system area code (0-7): ");
    scanf("%d", &s);
    printf("Enter a feature of the dirty buffer (0/1): ");
    scanf("%d", &d);
    printf("Enter a feature of the free buffer (0/1): ");
    scanf("%d", &f);
    printf("Enter a block number displayed in the buffer (0-255): ");
    scanf("%d", &b);
    UnitStateWord  = (s & 7) << 13;
    UnitStateWord  |= 0 << 12;
    UnitStateWord  |= (d & 1) << 11;
    UnitStateWord  |= 0 << 10;
    UnitStateWord  |= (f & 1) << 9;
    UnitStateWord  |= 0 << 8;
    UnitStateWord  |= b & 0xFF;
    printf("Buffer status word = %04x", UnitStateWord);
}

void third_task_unpacking() {
    int s, d, f, b, UnitStateWord;
    printf("Enter a buffer status word");
    printf("(Hex number from 0 to 0xFFFF): ");
    scanf("%x", &UnitStateWord);
    s = (UnitStateWord >> 13) & 7;
    d = (UnitStateWord >> 11) & 1;
    f = (UnitStateWord >>  9) & 1;
    b = UnitStateWord & 0xFF;
    printf("A system area code = %d\n", s);
    printf("A feature of the dirty buffer = %d\n", d);
    printf("A feature of the free buffer = %d\n", f);
    printf("A block number displayed in the buffer = %d", b);
}

void menu() {
    printf("--------------\n");
    printf("What task do you want to run? (1-3) \n");
    printf("1 - Calculate (a-b)^2 \n");
    printf("2 - Calculate volume and full surface of cube with edge length of b. \n");
    printf("3 - Programming of bit operations and shift operations\n");
    printf("--------------\n-> ");
    int task;
    scanf("%d", &task);
    if (task == 1){
        first_task();
    }
    else if (task == 2){
        second_task();
    }
    else if (task == 3){
        int choice;
        printf("Select the program task(1/2):\n");
        printf("1 - Packing.\n");
        printf("2 - Unpacking.\n");
        printf("--------------\n-> ");
        scanf("%d", &choice);
        if (choice == 1) {
            third_task_packing();
        }
        else if (choice == 2) {
            third_task_unpacking();
        }
    }
}

int main() {
    title_page();
    menu();
}
