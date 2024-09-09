#include <stdio.h>
#include <string.h>
int main() {
    char p[50], nterminal, a[20], b[20];
    int i = 3, j = 0;
    printf("Enter a production :");
    scanf("%s", p);  
    nterminal = p[0]; 
    if (p[i] == nterminal) { i++;
    while (p[i] != '|' && p[i] != '\0') {
        a[j++] = p[i++];
    }
    a[i]='\0';
    j = 0;
    i++; 
    while (p[i] != '\0') {
        b[j++] = p[i++];
    }
    b[j] = '\0';
    printf("\nAfter eliminating left recursion:\n");
    printf("%c -> %s%c\'\n", nterminal, b,nterminal); 
    printf("%c\' -> %s%c\' | e\n", nterminal, a, nterminal); 
}
    else {
        printf("The production has no left recursion.\n");
    }
    return 0;
}

