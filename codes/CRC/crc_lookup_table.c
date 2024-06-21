#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

byte crctable[256];

void compute_look_up_table()
{
    const byte generator = 0x1D;
    for (int dividend = 0; dividend < 256; dividend++)
    {
        byte curr = (byte)dividend;
        for (byte bit = 0; bit < 8; bit++)
        {
            if ((curr & 0x80) != 0)
            {
                curr <<= 1;
                curr ^= generator;
            }
            else
            {
                curr <<= 1;
            }
        }
        crctable[dividend] = curr;
    }
}

byte compute_crc(const byte *bytes, size_t length)
{
    byte crc = 0;
    for (size_t i = 0; i < length; i++)
    {
        byte data = (byte)(bytes[i] ^ crc);
        crc = (byte)(crctable[data]);
    }
    return crc;
}

int main()
{
    compute_look_up_table();

    byte data[] = {0x01, 0x02};
    size_t length = sizeof(data) / sizeof(data[0]);

    byte crc = compute_crc(data, length);
    printf("%d", crc);
    printf("crc value: 0x%02X\n", crc);

    return 0;
}
