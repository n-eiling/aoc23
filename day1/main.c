#include <stdio.h>
#include <string.h>

const char* numbers[] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

const int num_lens[] = {
    3, 3, 5, 4, 4, 3, 5, 5, 4
};

int get_num(char* buf, int pos, int len)
{
    if (buf[pos] <= '9' && buf[pos] >= '0') {
        return (buf[pos] - '0');
    }
    for (int j = 0; j < 9; j++) {
        if (len-pos >= num_lens[j] && strncmp(buf+pos, numbers[j], num_lens[j]) == 0) {
            return j+1;
        }
    }
    return -1;
}

int main(void)
{
    char buf[1024] = {0};
    int sum = 0;
    int next;
    while (scanf("%1024s", buf) != EOF) {
        next = 0;
        int len = strlen(buf);
        for (int i = 0; i < len; i++) {
            int num = get_num(buf, i, len);
            if (num != -1) {
                next = num*10;
                break;
            }
        }
        printf("next: %d\n", next);
        for (int i=len-1; i >= 0; --i) {
            int num = get_num(buf, i, len);
            if (num != -1) {
                next += num;
                break;
            }
        }
        sum += next;
        printf("next: %d\n", next);

    }
    printf("sum: %d\n", sum);
}