#include <stdio.h>

int maxUsingIfElse(int num1, int num2) {
    int max;

    if (num1 > num2) {
        max = num1;
    } else {
        max = num2;
    }

    return max;
}
int maxUsingTernaryOperator(int num1, int num2) {
    int max = (num1 > num2) ? num1 : num2;
    return max;
}

int main() {
    int a = 100, b = 200;
    int result = maxUsingIfElse(a, b);
    printf("The maximum of %d and %d is: %d\n ", a, b, result);
    printf("using if-else function \n");
    printf("\n");
    int result1 = maxUsingTernaryOperator(a, b);
    printf("The maximum of %d and %d is: %d\n", a, b, result1);
    printf("using ternary operator");
    
    return 0;
}