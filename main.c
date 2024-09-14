#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    int a;
    while(true)
    {
        printf("1. Ввести число А \n");
        printf("2. Ввести число Б\n");
        printf("3. Сложить\n");
        printf("4. Вычесть\n");
        printf("5. Умножить\n");
        printf("6. Поделить\n");
        printf("7. Выйти\n");
        printf("\nВыберите действие: ");
        scanf("%i",&a);


        short int number1;
        short int number2;

        if (a==1) {
            system("clear");
            printf("\nВведите число А: ");
            scanf("%hd",&number1);
            system("clear");
        }

        if (a==2) {
            system("clear");
            printf("\nВведите число Б: ");
            scanf("%hd",&number2);
            system("clear");
        }

        if (a==3) {
            printf("\nРезультат: ");
            int c = number1 + number2;
            printf("%d\n\n" , c);
            usleep(3000000);
            system("clear");

        }

        if (a==4) {
            printf("\nРезультат: ");
            int c = number1 - number2;
            printf("%d\n\n" , c);
            usleep(3000000);
            system("clear");
        }

        if (a==5) {
            printf("\nРезультат: ");
            int c = number1 * number2;
            printf("%d\n\n" , c);
            usleep(3000000);
            system("clear");
        }

        if (a==6) {
            printf("\nРезультат: ");
            int c = number1 / number2;
            printf("%d\n\n" , c);
            usleep(3000000);
            system("clear");
        }

        if(a==7)
        {   printf("Good bye!");
            break;
        }
    }
    return 0;
}
