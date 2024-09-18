#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[100];
    int isNumber = 1;
    int i = 0;
    short int number1 = 0;

    // Ввод значения с помощью scanf
    printf("Введите значение: ");
    scanf("%s", input);

    // Проверка на число
    if (input[0] == '-') {
        i = 1; // Начинаем с элемента после минуса, если число отрицательное
    }

    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            isNumber = 0;
            break;
        }
        i++;
    }

    // Вывод результата и запись числа в переменную
    if (isNumber) {
        printf("yes\n");
        number1 = atoi(input);
        printf("Записанное число: %d\n", number1);
    } else {
        printf("no\n");
    }

    return 0;
}