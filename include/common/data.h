#ifndef __DATA_H__
#define __DATA_H__

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

#endif