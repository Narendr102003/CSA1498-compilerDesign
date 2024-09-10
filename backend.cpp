#include <stdio.h>
#include <string.h>

struct Instruction {
    char op[5];   
    char arg1[5]; 
    char arg2[5]; 
    char res[5];  
};

int main() {
    int n, i;
    printf("Enter the number of three-address code instructions: ");
    scanf("%d", &n);
    struct Instruction instructions[10];
    printf("Enter the instructions in the format:\n<result> = <arg1> <op> <arg2>\n");
    for (i = 0; i < n; i++) {
        printf("Instruction %d: ", i + 1);
        scanf("%s %*s %s %s %s", instructions[i].res, instructions[i].arg1, instructions[i].op, instructions[i].arg2);
    }
    printf("\nGenerated Assembly Code:\n");
    for (i = 0; i < n; i++) {
        printf("MOV R0, %s\n", instructions[i].arg1);
        if (strcmp(instructions[i].op, "+") == 0) {
            printf("ADD R0, %s\n", instructions[i].arg2);
        } else if (strcmp(instructions[i].op, "-") == 0) {
            printf("SUB R0, %s\n", instructions[i].arg2);
        } else if (strcmp(instructions[i].op, "*") == 0) {
            printf("MUL R0, %s\n", instructions[i].arg2);
        } else if (strcmp(instructions[i].op, "/") == 0) {
            printf("DIV R0, %s\n", instructions[i].arg2);
        }
        printf("MOV %s, R0\n", instructions[i].res);
    }

    return 0;
}

