#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>

int n_button;
int position = 0;
short int number1;
short int number2;
int itog;
bool f_flag = false;


void printMenu(int position) {
    char menu[8][30] = {
        "1. Ввести число А",
        "2. Ввести число Б",
        "3. Сложить (+)",
        "4. Вычесть (-)",
        "5. Умножить (*)",
        "6. Поделить (/)",
        "7. Выйти",
        ""
    };

    for (int i = 0; i <= 7; ++i) {
        if (i == position) {
            printw("%s  %s\n", menu[i], "<---");
        } else {
            printw("%s\n", menu[i]);
        }
        if (i == 7 && f_flag == true) {
            printw("%s %d", "Результат:", itog);
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    initscr();

    while (true) {
        printMenu(position);

        n_button = getch();
        if (n_button == 27) {
            //to up
            n_button = getch();
            if (n_button == 91) {
                n_button = getch();
                if (n_button == 65) {
                    position = position - 1;
                    if (position < 0) {
                        position = 6;
                    }
                }
                if (n_button == 66) {
                    // down
                    position = position + 1;
                    if (position > 6) {
                        position = 0;
                    }
                }
            }
        }

        // 49 - 55; 1 - 7
        //Enter A
        if ((position == 0 && n_button == 10) || n_button == 49) {
            clear();
            printw("%s", "Введите число А: ");
            scanw("%d\n", &number1);
            clear();
            printMenu(position);
        }

        //Enter B
        if ((position == 1 && n_button == 10) || n_button == 50) {
            clear();
            printw("%s", "Введите число Б: ");
            scanw("%d\n", &number2);
            clear();
            printMenu(position);
        }

        //Summ
        if ((position == 2 && n_button == 10) || n_button == 51) {
            f_flag = true;
            itog = number1 + number2;
            clear();
            printMenu(position);
        }

        //Vichet
        if ((position == 3 && n_button == 10) || n_button == 52) {
            f_flag = true;
            itog = number1 - number2;
            clear();
            printMenu(position);
        }
        //Ymnozh
        if ((position == 4 && n_button == 10) || n_button == 53) {
            f_flag = true;
            itog = number1 * number2;
            clear();
            printMenu(position);
        }

        //del
        if ((position == 5 && n_button == 10) || n_button == 54) {
            f_flag = true;
            itog = number1 / number2;
            clear();
            printMenu(position);
        }

        //close calc
        if ((position == 6 && n_button == 10) || n_button == 55) {
            break;
        }
        clear();
        endwin();
    }
    return 0;
}
