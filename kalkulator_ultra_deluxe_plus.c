#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void help(){
    printf("-- S.U.P.E.R. Calculator Manual Page --\nUsage: OPERATOR OPERAND1 OPERAND2 (e.g ADD 1 2)\n");
    printf("List of Operators:\nADD  - Adition\nSUB  - Subtraction\nMULT - Multiplication\nDIV  - Division\nMOD  - Modulus\n");
    printf("FACT - Factorial (One Operand)\nPERM - Permutation\nCOMB - Combination\nGCD  - Great Common Divisor\nLCM  - Least Common Multiplier\n");
    printf("HELP - Open Manual Page\nQuit - Close Program\nName of the command aren't case sensitive\nCLI Arguments input are also available\n");
}

void lower(char string[]){
    for (int i = 0; i < strlen(string); i++){
        if(string[i] < 97){
            string[i] += 32;
        }
    }
}

void lowerTo(const char string[], char output[]){
    for (int i = 0; i < strlen(string); i++){
        if(string[i] < 97){
            output[i] = string[i] + 32;
        }
    }
}

int abs(int n){
    return (n < 0)? -n : n;
}

int fact(int n){
    return (n < 2)? 1 : n * fact(n-1);
}
int permLoop(int n, int r, int i){
    return (i <= n-r+1)? i : i * permLoop(n, r, i-1);
}
int perm(int n, int r){
    return permLoop(n, r, n);
}
int comb(int n, int r){
    return perm(n, r)/fact(r);
}

float add(float a, float b){
    return a+b;
}
float sub(float a, float b){
    return a-b;
}
float mult(float a, float b){
    return a*b;
}
float divs(float a, float b){
    return a/b;
}
int mod(int a, int b){
    return a%b;
}

int gcdLoop(int a, int b){
    if (a == b) return a;
    if (a%2 == 0 && b%2 == 0) return 2*gcdLoop(a>>1,b>>1);
    if (a%2 == 0 && b%2 != 0) return gcdLoop(a>>1,b);
    if (a%2 != 0 && b%2 == 0) return gcdLoop(a,b>>1);
    if (a > b) return gcdLoop(b, a-b);
    return gcdLoop(a, b-a);
}
int gcd(int a, int b){
    if (a == 0) return b;
    if (b == 0) return a;
    return gcdLoop(a, b);
}
int lcm(int a, int b){
    return abs(a*b)/gcd(a,b);
}

void init(){
    printf("-- Welcome to SUPER ULTRA PLUS EXTENDED RENEWED CALCULATOR! --\n");
}

int processor(char *fun, float a, float b){
    float res;
    if (!strcmp(fun,"fact")) res = fact(trunc(a));
    else if (!strcmp(fun,"perm")) res = perm(trunc(a), trunc(b));
    else if (!strcmp(fun,"comb")) res = comb(trunc(a), trunc(b));
    else if (!strcmp(fun,"gcd") || !strcmp(fun,"fpb")) res = gcd(trunc(a), trunc(b));
    else if (!strcmp(fun,"lcm") || !strcmp(fun,"kpk")) res = lcm(trunc(a), trunc(b));
    else if (!strcmp(fun,"add") || !strcmp(fun,"sum")) res = add(a, b);
    else if (!strcmp(fun,"sub") || !strcmp(fun,"min")) res = sub(a, b);
    else if (!strcmp(fun,"mult") || !strcmp(fun,"times")) res = mult(a, b);
    else if (!strcmp(fun,"div")){
        if(b != 0) res = divs(a, b);
        else {
            printf("ERROR: Division by zero\n");
            return 1;
        }
    }
    else if (!strcmp(fun,"mod")) res = mod(a, b);
    else {
        printf("ERROR: Invalid input.\nType HELP to open the manual page\n");
        return 1;
    }
    printf("Result: %.4f\n", res);
    return 0;
}

int inputManager(){
    char fun[5];
    printf("> "); scanf("%5s", fun); lower(fun);
    if (!strcmp(fun,"quit") || !strcmp(fun,"exit") || !strcmp(fun,"q")){
        return 1;
    } else if (!strcmp(fun,"help")){
        help();
        return 0;
    }
    float a; scanf("%f", &a);
    if (!strcmp(fun,"fact")){ 
        processor(fun, a, 0);
        return 0;
    }
    else {
        float b; scanf("%f", &b); 
        processor(fun, a, b);
        return 0;
    }
}

int loop(){
    fflush(stdin);
    if(inputManager()) return 0;
    return loop();
}

int manualInput(){
    printf("Type your input here or type HELP for guide and QUIT to exit\n");
    return loop();
}

int argInput(char *fun, float a, float b){
    printf("Generating result from cli arguments...\n");
    if(processor(fun, a, b)) return 1;
    return 0;
}

int main(int argc, char const *argv[]){
    int status;
    init();
    if (argc > 2){
        char fun[5];
        lowerTo(argv[1], fun);
        if (argc == 3){
            if (!strcmp(argv[1], "fact")){
                printf("Error: incorrect number of arguments");
                status = 1;
            }
            status = argInput(fun, atof(argv[2]), 0);
        } else {
            status = argInput(fun, atof(argv[2]), atof(argv[3]));
        }
    } else {
        status = manualInput();
    }
    if (status){
        printf("-- Program Terminated with Error --\n");
        return 1;
    }
    printf("-- Program Terminated Succesfully --\n");
    return 0;
}