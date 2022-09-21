#include "header.hpp"
int main(int argc, char **argv)
{
    uint16_t val = 0x400;
    uint8_t *ptr = (uint8_t *)&val;
    if (ptr[0] == 0x40)
    {
        cout << "big";
    }
    else
    {
        cout << "little";
    }
}