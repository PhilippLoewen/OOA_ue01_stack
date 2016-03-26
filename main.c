#include <stdio.h>
#include <string.h>
#include "stack.h"


int main() {

    stack_t *stacki = createStack();
    int error;
    char ara[50];
    char *pch;
    char delimiter[] = " ";
    float tmp1, tmp2, tmp3;
    fgets(ara, 50, stdin);
    /* Remove trailing newline, if there. */
    if ((strlen(ara)>0) && (ara[strlen (ara) - 1] == '\n'))
        ara[strlen (ara) - 1] = '\0';
    pch = strtok(&ara[0], delimiter);
    while (pch != NULL) {
        if (*pch == '+' || *pch == '-' || *pch == '*' || *pch == '/') {
            tmp1 = top(stacki);
            pop(stacki);
            tmp2 = top(stacki);
            pop(stacki);

            switch (*pch) {
                case '+':
                    push(stacki, tmp1 + tmp2);
                    break;
                case '-':
                    push(stacki, tmp2 - tmp1);
                    break;
                case '*':
                    push(stacki, tmp1 * tmp2);
                    break;
                case '/':
                    push(stacki, tmp2 / tmp1);
                    break;
                default:
                    printf("%s", "\nUnerlaubtes Symbol eingegeben.\n");
                    break;
            }
        }
        else {
            error = sscanf(pch, "%f", &tmp3);
            if (error == 0) {
                printf("%s", "\nUnerlaubtes Symbol eingegeben.\n");
            }
            push(stacki, tmp3);
        }
        pch = strtok(NULL, delimiter);
    }

    printf("\n%4.3f", top(stacki));

    destroyStack(stacki);

    return 0;
}