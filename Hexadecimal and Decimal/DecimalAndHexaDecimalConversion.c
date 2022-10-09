#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#define SIZE 64

int main()
{
    int iOption, iDecimal;
    char sHex[64] = "";
    char *log = "";

    do
    {
        system("cls");
        printf("*****************************************\n");
        printf("*\tHexadecimal - Decimal Conversion\n");
        printf("*****************************************\n");
        printf("\t[Options]\n");
        printf("[1]->\tDecimal to Hexadecimal\n");
        printf("[2]->\tHexadecimal to Decimal\n");
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
            printf("\nEnter a number (-1 or ctrl+c to quit): ");
            scanf("%d", &iDecimal);
            if (iDecimal < 0)
            {
                printf("Quitting...\n");
                break;
            }

            char current[] = "";
            char temp[SIZE] = "";
            int quot = iDecimal;

            while (quot)
            {
                int mod = quot % 16;
                strcpy(temp, "");
                switch (mod)
                {
                case 10:
                    sprintf(temp, "A", 0);
                    break;
                case 11:
                    sprintf(temp, "B", 0);
                    break;
                case 12:
                    sprintf(temp, "C", 0);
                    break;
                case 13:
                    sprintf(temp, "D", 0);
                    break;
                case 14:
                    sprintf(temp, "E", 0);
                    break;
                case 15:
                    sprintf(temp, "F", 0);
                    break;

                default:
                    sprintf(temp, "%d", mod);
                    break;
                }
                strcat(current, temp);

                quot /= 16;
            }
            strrev(current);
            printf("[Output]: %s\n", current);
            goto repeat;
        case 2:
        repeat2:
            printf("\nEnter a valid hex number (-1 or ctrl+c to quit): ");
            scanf("%s", &sHex);
            if (sHex[0] == 'q')
            {
                printf("Quitting...\n");
                break;
            }
            strrev(sHex);
            int calc = 0;
            char temp2[SIZE] = "";

            for (int i = 0; i < SIZE; i++)
            {
                if (!(sHex[i]))
                {
                    break;
                }
                char upc = toupper(sHex[i]);
                strcpy(temp2, "");
                switch (upc)
                {
                case 'A':
                    sprintf(temp2, "10", 0);
                    break;
                case 'B':
                    sprintf(temp2, "11", 0);
                    break;
                case 'C':
                    sprintf(temp2, "12", 0);
                    break;
                case 'D':
                    sprintf(temp2, "13", 0);
                    break;
                case 'E':
                    sprintf(temp2, "14", 0);
                    break;
                case 'F':
                    sprintf(temp2, "15", 0);
                    break;
                default:
                    sprintf(temp2, "%c", upc);
                    break;
                }
                int iHexc = atoi(temp2);
                if (iHexc < 16)
                {
                    calc += iHexc * pow(16, i);
                }
                else
                {
                    printf("Invalid hex number.\nPlease try again.\n");
                    goto repeat2;
                }
            }
            printf("[Output]: %d\n", calc);

            goto repeat2;
        default:
            log = "[Logs]\n[Warning!]\tThat is not in the Option!!\n[ERROR]\t\tPlease Try Again!\n";
            break;
        }

    } while (iOption > 0);

    return 0;
}