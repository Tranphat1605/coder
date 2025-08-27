#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char s[1000];

char* chuanhaotu(char *s) {
    if (s[0] != '\0') { 
        s[0] = toupper(s[0]);
        for (int i = 1; i < strlen(s); i++) {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}

int main() {
    fgets(s, 1000, stdin);
    
  
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    char *token = strtok(s, " ");
    while (token != NULL) {
        printf("%s ", chuanhaotu(token));
        token = strtok(NULL, " ");
    }
    
    return 0;
}
