#include"data.h"
#include <stddef.h>
#include <stdio.h>
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base){
    uint8_t length = 1;
    //handle signed value
    if(data<0){
        data = -1*data;
        //add '-'?
    }

    uint8_t* temp = ptr;

    while(data>=0){
        uint8_t remainder = data % base;
        
        if(remainder<=9){
            *temp = remainder + '0';
        }
        else{
            *temp = remainder + 'A';
        }
        temp ++;
        length ++;
        data = data/base;
    }

    return length;
    
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    if(ptr == NULL){
        return 0;
    }

    int32_t output = 0;
    
    for(int ix = 0; ix<digits; ix++){
        uint8_t value = *ptr;
        int32_t digit;

        if (value >= '0' && value <= '9') {
            digit = value - '0';
        } else if (value >= 'A' && value <= 'F') {
            digit = value - 'A' + 10;
        } else if (value >= 'a' && value <= 'f') {
            digit = value - 'a' + 10;
        } 

        output = output*base + digit;
        ptr ++;
    }
    return output;


}