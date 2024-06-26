#include <stdio.h>
#include <math.h>
#include <string.h>
#define ull unsigned long long int
#define lli long long int

int Decimal_to_Binary(int decimal)
{
    ull binary = 0;
    int count = 0;
    int rem = 0;
    while (decimal != 0)
    {
        rem = decimal % 2;
        ull tmp = pow(10, count);
        binary += rem * tmp;
        decimal /= 2;
        count++;
    }
    return binary;
}

lli Binary_to_Decimal(char binary[])
{
    lli decimal = 0;
    for (int i = 0; i < strlen(binary); i++)
    {
        if (binary[i] == '1')
            decimal += 1 << (strlen(binary) - i - 1);
    }
    return decimal;
}

void CRC(char data[], char gen_poly[])
{
    int length_gen = strlen(gen_poly);
    lli generator_dec = Binary_to_Decimal(gen_poly);
    lli data_dec = Binary_to_Decimal(data);
    lli dividend = data_dec << (length_gen - 1);
    int shift_bits = (int)ceill(log2l(dividend + 1)) - length_gen;
    lli check_value;
    while ((dividend >= generator_dec) || (shift_bits >= 0))
    {
        check_value = (dividend >> shift_bits) ^ generator_dec;
        dividend = (dividend & ((1 << shift_bits) - 1)) | (check_value << shift_bits);
        shift_bits = (int)ceill(log2l(dividend + 1)) - length_gen;
    }
    lli final_data = (data_dec << (length_gen - 1)) | dividend;
    printf("Check value or CRC: %d\n", Decimal_to_Binary(dividend));
    printf("Data to be sent:  %d", Decimal_to_Binary(final_data));
}

int main()
{
    char dataword[20];
    printf("Enter the data to be transmitted: ");
    scanf("%s", dataword);
    char generator[20];
    printf("\nEnter the generator polynomial: ");
    scanf("%s", generator);
    CRC(dataword, generator);
    return 0;
}
