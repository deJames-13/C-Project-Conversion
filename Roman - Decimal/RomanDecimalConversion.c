#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
    char *log = "";
    int iOption, iDecimal;
    do
    {
        system("cls");
        printf("*****************************************\n");
        printf("*\tDecimal - Roman Conversion\n");
        printf("*****************************************\n");
        printf("\t[Options]\n");
        printf("[1]->\tDecimal to Roman\n");
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
            printf("\nInput the number (-1 or ctrl+c to quit): ");
            scanf("%d", &iDecimal);
            if (iDecimal < 0)
            {
                printf("Quitting..\n");
                break;
            }
            int m_count = iDecimal / 1000;
            int c_count = (iDecimal % 1000) / 100;
            int x_count = ((iDecimal % 1000) % 100) / 10;
            int i_count = ((iDecimal % 1000) % 100) % 10;
            char current[] = "";
            // printf("%d %d %d %d\n", m_count, c_count, x_count, i_count);

            while (m_count || c_count || x_count || i_count)
            {
                if (m_count)
                {
                    strcat(current, "M");
                    m_count--;
                }
                else if (c_count)
                {
                    switch (c_count)
                    {
                    case 9:
                        strcat(current, "CM");
                        c_count -= 9;
                        break;
                    case 5 ... 8:
                        strcat(current, "D");
                        c_count -= 5;
                        break;
                    case 4:
                        strcat(current, "CD");
                        c_count -= 4;
                        break;
                    default:
                        strcat(current, "C");
                        c_count -= 1;
                        break;
                    }
                }
                else if (x_count)
                {
                    switch (x_count)
                    {
                    case 9:
                        strcat(current, "XC");
                        x_count -= 9;
                        break;
                    case 5 ... 8:
                        strcat(current, "L");
                        x_count -= 5;
                        break;
                    case 4:
                        strcat(current, "XL");
                        x_count -= 4;
                        break;
                    default:
                        strcat(current, "X");
                        x_count -= 1;
                        break;
                    }
                }
                else
                {
                    switch (i_count)
                    {
                    case 9:
                        strcat(current, "IX");
                        i_count -= 9;
                        break;
                    case 5 ... 8:
                        strcat(current, "V");
                        i_count -= 5;
                        break;
                    case 4:
                        strcat(current, "IV");
                        i_count -= 4;
                        break;
                    default:
                        strcat(current, "I");
                        i_count -= 1;
                        break;
                    }
                }
            }
            printf("[Output]: %s\n", current);
            goto repeat;
        default:
            log = "[Logs]\n[Warning!]\tThat is not in the Option!!\n[ERROR]\t\tPlease Try Again!\n";
            break;
        }
    } while (iOption > 0);

    return 0;
}