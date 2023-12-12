#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[1024] = {0};
    int sum = 0;
    int next;
    while (scanf("%1024s", buf) != EOF) {
        next = 0;
        for (int i = 0; i < 1024 && buf[i] != '\0'; i++) {
            if (buf[i] <= '9' && buf[i] >= '0') {
                next += (buf[i] - '0')*10;
                break;
            }   
        }
        for (int i=strlen(buf)-1; i >= 0; --i) {
            if (buf[i] <= '9' && buf[i] >= '0') {
                next += (buf[i] - '0');
                break;
            }
        }
        sum += next;
        printf("next: %d\n", next);

    }
    printf("sum: %d\n", sum);
}