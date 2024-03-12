/**
 * @file morse.c
 * @author fuck your mother
 * @brief 
 * @version 0.1
 * @date 2023-10-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<string.h>

// #define CODE_SIZE = 37
// #define CODE_LENGTH = 7


char* encode_morse(char* answer, char *string);
char *decode_morse(char* answer, char *string);
char *getCodes(char character);

int getIndex(char character);
int isAlpha(char character);

char *getChars(char* s);

// source info

char *letters[37] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1',
    '2', '3', '4', '5', '6', '7', '8', '9'};

// Morse strings
char codes[37][7] = {
    "._",    "_...",  "_._.",  "_..",   ".",     ".._.",  "__.",   "....",
    "..",    ".___",  "_._",   "._..",  "__",    "_.",    "___",   ".__.",
    "__._",  "._.",   "...",   "_",     ".._",   "..._",  ".__",   "_.._",
    "_.__",  "__..", "_____",  ".____", "..___", "...__", "...._", ".....", "_....",
    "__...", "___..", "____."
};

int main() {    
    char* input = "I love C in 2023";
    char* result = encode_morse(result, input);
    printf("%s\n", result);
    char* input2 = "SOS";

    return 0;
}

int isAlpha(char character) {
    if(character >= 65 && character <= 90) {
        return 1;
    }
    else {
        return 0;
    }
}

int getIndex(char character) {
    if(isAlpha(character) ) {
        return character - 65;
    }
    else {
        return character - 48 + 26;
    }
}

char *getCodes(char character) {
    int index = getIndex(character);
    return codes[index];
}

char* encode_morse(char *answer, char *string) {
    //SOS
    *answer = '\0';    
    char* space = " ";
    while (*string) {
        char *temp = getCodes(*string);
        strcat(answer, temp);
        strcat(answer, space);
        string ++;
    }
    return answer;
}

char *getChars(char* s) {
    int index = 0;
    for(int i = 0; i < 37; ++i) {
        if(strcmp(codes[i], s)) {
            index = i;
        }
    }
    char temp = letters[index];
    char str[2];
    str[0] = temp;
    str[1] = '\0';
    return str;
    
}

char* decode_morse(char* answer, char*string) {
    *answer = '/0';
    char *temp = "";
    int flag = 0;

    while(*string)
    {
        while(*string == ' ')  {
            string ++;
        }
        for(int i = 0; i < 36; i++ ) {
            for(int j = 0; j < 7; j++) {
                if (strncmp(codes[i], string, j)) {
                    strncpy(temp, string, j);
                    strcat(answer, getChars(temp));
                }
                string += j;
                break;
                flag = 1;
            }
            if(flag == 1) {
                flag = 0;
                break;
            }
        }
    }
}; 