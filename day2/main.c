#include <stdio.h>
#include <string.h>

const char *colors[] = {"red", "blue", "green"};
const int colors_lens[] = {3, 4, 5};

const int max_nums[] = {12, 14, 13};

int main(void)
{
    char *buf = NULL;
    size_t buflen = 0;
    int gameid = 0;
    int sum = 0;
    int powersum = 0;
    int len = 0;
    char* group_begin;
    char* next_group_begin;
    while (getline(&buf, &buflen, stdin) != EOF) {
        int works = 1;
        int max_colors[3] = {0};
        printf("buf: %s", buf);
        if (sscanf(buf, "Game %d:", &gameid) == EOF) {
            printf("sscanf error\n");
            return -1;
        }
        printf("gameid: %d\n", gameid);

        group_begin = strchr(buf, ':')+2;
        next_group_begin = strchr(group_begin, ';')+2;
        if (next_group_begin == 2) {
            next_group_begin = buf + buflen;
            next_group_begin[-2] = '\0';
        }
        while (group_begin != 2 && group_begin < buf + buflen) {
            int num = 0;
            char color[32] = {0};
            int cnums[3] = {0};
            char *p = group_begin;
            while(p >= group_begin && p < next_group_begin) {
                if (sscanf(p, "%d %32s", &num, color) != 2) {
                    break;
                }
                for (int j = 0; j < 3; j++) {
                    if (strncmp(color, colors[j], colors_lens[j]) == 0) {
                        cnums[j] += num;
                        if (num > max_colors[j]) {
                            max_colors[j] = num;
                        }
                        break;
                    }
                }
                p = strchr(p, ',')+2;
            }
            if (cnums[0] > max_nums[0] || cnums[1] > max_nums[1] || cnums[2] > max_nums[2]) {
                works = 0;
            }
            printf ("red %d, blue %d, green %d\n", cnums[0], cnums[1], cnums[2]);
            group_begin = next_group_begin;
            next_group_begin = strchr(group_begin, ';')+2;
            if (next_group_begin == 2) {
                next_group_begin = buf + buflen;
                next_group_begin[-2] = '\0';
            }
        }
        if (works) {
            sum += gameid;
        }
        int power = max_colors[0] * max_colors[1] * max_colors[2];
        printf("power: %d\n\n", power);
        powersum += power;
    }
    printf("sum: %d\n", sum);
    printf("powersum: %d\n", powersum);
}