#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#define SIZE 64

int main()
{
    int iOption, iDecimal;
    char sOctal[SIZE] = "";
    char *log = "";

    do
    {
        system("cls");
        printf("*****************************************\n");
        printf("*\tOctal - Decimal Conversion\n");
        printf("*****************************************\n");
        printf("\t[Options]\n");
        printf("[1]->\tDecimal to Octal\n");
        printf("[1]->\tOctal to Decimal\n");
        if (log != "")
        {
            printf("\n%s\n", log);
        }
        printf("*****************************************\n");
        log = "";
        iOption = -1;
        printf("\n->\tChoose an option (0 or ctrl+c to quit): ");
        scanf("%d", &iOption);
        switch (iOption)
        {
        case -1:
            printf("\n[Warning!]\tForbidden String Input!!\n[ERROR]\t\tProgram crashed!\n");
            break;
        case 0:
            printf("\n\t[Process terminated.]\n");
            break;
        case 1:
        repeat:
            iDecimal = -1;
            printf("\nEnter the number (-1 or ctrl+c to quit): ");
            scanf("%d", &iDecimal);
            if (iDecimal < 0)
            {
                printf("Quitting...\n");
                break;
            }
            char current[] = "";
            char temp[64];
            int quot = iDecimal;

            while (quot)
            {
                strcpy(temp, "");
                sprintf(temp, "%d", quot % 8);
                strcat(current, temp);
                quot /= 8;
            }
            strrev(current);
            printf("[Output]: %s\n", current);

            goto repeat;
        case 2:
        repeat2:
            printf("\nEnter a valid octal number (q or ctrl+c to quit): ");
            scanf("%s", &sOctal);
            if (sOctal[0] == 'q')
            {
                printf("Quitting...\n");
                break;
            }
            strrev(sOctal);
            int calc = 0;
            char temp2[64];

            for (int i = 0; i < SIZE; i++)
            {
                if (!(sOctal[i]))
                {
                    break;
                }
                strcpy(temp2, "");
                sprintf(temp2, "%c", sOctal[i]);
                int iOctalc = atoi(temp2); // this turns the str to int
                if (iOctalc < 8)
                {
                    calc += iOctalc * pow(8, i);
                }
                else
                {
                    printf("Invalid octal number.\nPlease try again.\n");
                    goto repeat2;
                }
            }
            printf("[Output]: %d\n", calc);

            goto repeat2;
        default:
            log = "[Logs]\n[Warning!]\tThat is not in the Option!!\n[ERROR]\t\tPlease Try Again!\n";
            break;
        }

    } while (!(iOption <= 0));

    return 0;
}