#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

int n_button, itog;
int pos_count = 0;
char *moving;

short int number1,number2;
bool take_number1 = false,take_number2 = false, f_flag = false , sec_number_zero = false, isdigit_check_number1 = true, isdigit_check_number2 = true;

void Calc() {

    printw("%s", "Calculator by Tikhanov Oleg\n");
    printw("%s", "ver 0.95\n");
    printw("%s", "Для завершения, дважды нажать ESC в главном меню\n");
    printw("%s", "-----------------\n");
    printw("%s", "\n");

    char screen[8][30] = {
        "1. Ввести число А",
        "2. Ввести число Б",
        "3. Сложить (+)",
        "4. Вычесть (-)",
        "5. Умножить (*)",
        "6. Поделить (/)",
        "7. Выйти",
        "",
    };

    for (int i = 0; i <= 7; ++i) {
        if (i == pos_count) {
            printw("%s  %s\n", screen[i], "<---");
        } else {
            printw("%s\n", screen[i]);
        }

            // Check for debil
        if (i == 7 && isdigit_check_number1 == false) {
            printw("%s", "В переменную А вы ввели не число!\n");
        }
        else if (i == 7 && take_number1 == false) {
            printw("%s" , "Число А не введено!\n");
        }



        if (i == 7 && isdigit_check_number2 == false) {
            printw("%s", "В переменную Б вы ввели не число!\n");
        }
        else if (i == 7 && take_number2 == false) {
            printw("%s" , "Число Б не введено!\n");
        }



        if (i == 7 && f_flag == true && take_number1 == true && sec_number_zero == true && ((pos_count == 5 && n_button == 10) || n_button == 54)) {
            printw("%s", "Делить на 0 нельзя!");

        }

            // end check


         else if (i == 7 && f_flag == true && take_number1 == true && take_number2 == true) {
            printw("%s %d %s %d = %d", "Результат:", number1, moving, number2, itog);
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    initscr();
    while (true) {
        Calc(pos_count);

        n_button = getch();
        if (n_button == 27) {
            // ESC
            n_button = getch();
            if (n_button == 91) {
                // enter
                n_button = getch();
                if (n_button == 65) {
                    // up
                    pos_count = pos_count - 1;
                    if (pos_count < 0) {
                        pos_count = 6;
                    }
                } else if (n_button == 66) {
                    // down
                    pos_count = pos_count + 1;
                    if (pos_count > 6) {
                        pos_count = 0;
                    }
                }
            }
        }


        // 49 - 55; 1 - 7
        //Enter A
        if ((pos_count == 0 && n_button == 10) || n_button == 49) {
            clear();
            printw("%s", "Введите число А: ");

            char digit1[100];
            int x = 0;

            scanw("%s", digit1);

            if (digit1[0] == '-') {
                x = 1;
            }

            while (digit1[x] != '\0') {
                if (!isdigit(digit1[x])) {
                    isdigit_check_number1 = false;
                    break;
                }
                x = x + 1;
            }

            if (isdigit_check_number1 == true) {
                number1 = atoi(digit1); //atoi - to int
                isdigit_check_number1 = true;
                take_number1 = true;
            }
            else {
                isdigit_check_number1 = false;
                take_number1 = false;
            }

            // scanw("%hu\n", &number1);
            clear();
            pos_count = 0;
            Calc(pos_count);

        }

        //Enter B
        if ((pos_count == 1 && n_button == 10) || n_button == 50) {
            clear();
            printw("%s", "Введите число Б: ");

            char digit2[100];
            int y = 0;

            scanw("%s", digit2);

            if (digit2[0] == '-') {
                y = 1;
            }

            while (digit2[y] != '\0') {
                if (!isdigit(digit2[y])) {
                    isdigit_check_number2 = false;
                    break;
                }
                y = y + 1;
            }

            if (isdigit_check_number2 == true) {
                number2 = atoi(digit2); //atoi - to int
                isdigit_check_number2 = true;
                take_number2 = true;
                if (number2 == 0) {
                        sec_number_zero = true;
                    }
                    else {
                        sec_number_zero = false;
                    }
            }
            else {
                isdigit_check_number2 = false;
                take_number2 = false;
            }

            clear();
            pos_count = 1;
            Calc(pos_count);

        }

        //Summ
        if ((pos_count == 2 && n_button == 10) || n_button == 51) {
            moving = "+";
            f_flag = true;
            itog = number1 + number2;
            clear();
            pos_count = 2;
            Calc(pos_count);
        }

        //Vichet
        if ((pos_count == 3 && n_button == 10) || n_button == 52) {
            moving = "-";
            f_flag = true;
            itog = number1 - number2;
            clear();
            pos_count = 3;
            Calc(pos_count);
        }
        //Ymnozh
        if ((pos_count == 4 && n_button == 10) || n_button == 53) {
            moving = "*";
            f_flag = true;
            itog = number1 * number2;
            clear();
            pos_count = 4;
            Calc(pos_count);
        }

        //del
        if ((pos_count == 5 && n_button == 10) || n_button == 54) {
            moving = "/";
            f_flag = true;
            itog = number1 / number2;
            clear();
            pos_count = 5;
            Calc(pos_count);
        }

        //close calc
        if ((pos_count == 6 && n_button == 10) || n_button == 55 || n_button == 27) {
            break;
        }
        clear();
        endwin();
    }
    return 0;

}