#pragma once
#ifndef __C_STR__
#define __C_STR__
#include <stdbool.h>
#include <string.h>
/*
  在字符串中, 查找字符第N次出现位置
*/

bool find_char_in_str(char *str, char sub_str, int offset, int *pos)
{
    bool res = false;
    *pos = 0;

    int src_len = strlen(str);
    if (offset >= src_len) {
        *pos = 0;
        return res;
    }
    for (int i = offset; i < src_len; i++) {
        if (str[i] == sub_str) {
            *pos = i;
            res = true;
            break;
        }
    }
    return res;
}



/*
  在字符串中, 查找字符串第N次出现位置
*/
bool find_str_in_str(char *str, char *sub_str, int offset, int *pos)
{
    bool res = false;
    *pos = 0;
    if (strlen(str) + offset < strlen(sub_str))
        return res;

    for (int i = offset; i < strlen(str); i++) {
        int match_times = 0;
        for (int j = 0; j < strlen(sub_str); j++) {
            if (i + j < strlen(str) && str[i + j] == sub_str[j]) 
                match_times++;
            else 
                break;
        }
        if (match_times == strlen(sub_str)) {
            *pos = i;
            res = true;
            break;
        }
    }
    return res;
}

#endif //__C_STR__

