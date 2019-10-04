#include <stdio.h>
#include <stdlib.h>

int check_number(long number);

int main()
{
    long input_number;
    printf("Insert long number\n");
    scanf("%ld", &input_number);
    printf("The result is: %d\n",check_number(input_number));
    getchar();
    return 0;
}

int check_number(long number)
{
    int numb_of_digits = 0;
    long tmp = number;
    char * string_number;
    while(tmp != 0)
    {
        tmp = tmp / 10;
        ++numb_of_digits;
    }

    string_number = (char*) malloc(numb_of_digits * sizeof(char));
    sprintf(string_number, "%ld", number);
    for (int i = 0; i < (numb_of_digits - 1); i++)
    {
        char bigger, smaller;
        if (string_number[i] < string_number[i+1])
        {
            smaller = string_number[i];
            bigger = string_number[i+1];
        }
        else
        {
            bigger = string_number[i];
            smaller = string_number[i+1];
        }
        if ((bigger - smaller) < 2)
            continue;
        else
            return 0;
    }
    printf("\n");
    return 1;
}
