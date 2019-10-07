#include <stdio.h>
#include <stdlib.h>

void print_as_bytes(unsigned char n);

int main()
{
    unsigned char m = 4, n = 3;
    //print_as_bytes(89);

    printf("%u\n", ((~((~0) << m)) << n) & 0xFF);
    print_as_bytes((((~((~0) << m)) << n) & 0xFF));
    print_as_bytes(0xAA);
    print_as_bytes(0xFF);
    return 0;
}

void print_as_bytes(unsigned char n)
{
    unsigned short rest = 0;
    unsigned short size_of_bytes = 0;
    unsigned short help_num = 0;
    unsigned short * to_reverse;

    help_num = n;
    while(1)
    {
        help_num = help_num / 2;
        if (help_num == 0)
        {

            break;
        }
        size_of_bytes++;
    }

    to_reverse = (unsigned short*) malloc((size_of_bytes + 1) * sizeof(unsigned short));

    for (int i = 0; i <= size_of_bytes; i++)
    {
        rest = n % 2;
        n = n / 2;
        to_reverse[i] = rest;
    }

    size_of_bytes++;

    while(size_of_bytes)
    {
        printf("%u", to_reverse[size_of_bytes - 1]);
        size_of_bytes--;
    }
    printf("\n");
    free(to_reverse);
}
