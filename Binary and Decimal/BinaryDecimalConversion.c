#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#define SIZE 64

int main()
{
    int iOption, iDecimal;
    char sBinary[SIZE] = "";
    char *log = "";
    do
    {
        system("cls");
        printf("*****************************************\n");
        printf("*\tBinary - Decimal Conversion\n");
        printf("*****************************************\n");
        printf("\t[Options]\n");
        printf("[1] ->\tDecimal to Binary\n");
        printf("[2] ->\tBinary to Decimal\n");
        if (log != "")
        {
            printf("\n%s\n", log);
        }
        printf("*****************************************\n");
        log = "";
        iOption = -1; // This iniatilizes the option to catch an error due to string input. See case -1 in switch.
        printf("\n->\tChoose an option (0 to quit): ");
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
            iDecimal = -1; // This iniatilizes the input to catch an error due to string input.
            printf("\nInput (-1 to stop): ");
            scanf("%d", &iDecimal);
            if (iDecimal < 0)
            {
                printf("Quitting..\n");
                break;
            }

            char current[] = "";
            char temp[64];

            int quot = iDecimal;
            while (quot != 0)
            {
                /*
                Creates an empty temp string and concats it to the current string
                */
                strcpy(temp, "");
                sprintf(temp, "%d", quot % 2);
                strcat(current, temp);

                quot /= 2;
            }
            // Reverses the current string so that it follows the MSV to LSV in conversion
            strrev(current);

            printf("[Output]: %s\n", current);
            goto repeat;
        case 2:
        repeat2:
            printf("\nInput (q for menu, ctrl+c to stop): ");
            scanf("%s", &sBinary);

            if (sBinary[0] == 'q')
            {
                printf("Quitting..\n");
                break;
            }
            int len = sizeof(sBinary);
            int calc = 0;
            strrev(sBinary);
            for (int i = 0; i < len; i++)
            {
                if (!(sBinary[i]))
                {
                    break;
                }
                if (sBinary[i] == '0' || sBinary[i] == '1')
                {
                    if (sBinary[i] == '1')
                    {
                        calc += pow(2, i);
                    }
                }
                else
                {
                    printf("Cannot interpret the binary.\nPlease try again.\n");
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