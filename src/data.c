#include "data.h"


uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
    uint8_t *start = ptr; // Store the starting address
    // Handle negative numbers
    if(data<0){
        *ptr++ = '-';
        data = -1*data;
    }
    
    uint8_t buffer[33]; // Maximum length for base 2
    uint8_t *bufferPtr = buffer;
    do {
        uint32_t remainder = data % base;
        *bufferPtr++ = (remainder < 10) ? (remainder + '0') : (remainder + 'A' - 10);
        data /= base;
    } while (data != 0);

    // Copy the converted string in reverse order to the output pointer
    while (bufferPtr != buffer) {
        *ptr++ = *--bufferPtr;
    }

    *ptr = '\0'; // Add null terminator
    return ptr - start; // Return the length of the converted data
}


int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int8_t sign = 1;

    if (*ptr == '-') {
        sign = -1;
        ptr++;
    }

    while (digits > 0) {
        uint8_t digit = *ptr++;
        digits--;

        if (digit >= '0' && digit <= '9') {
            digit -= '0';
        } else if (digit >= 'A' && digit <= 'F') {
            digit -= 'A' - 10;
        } else if (digit >= 'a' && digit <= 'f') {
            digit -= 'a' - 10;
        } else {
            break; // finish parsing
        }
        result = result * base + digit;
    }

    return result * sign;
}
