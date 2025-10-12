#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define __NR_set_array  451
#define __NR_get_array  452

int main(int argc, char *argv[]) {
    int index, value, result;

    if (argc == 4 && strcmp(argv[1], "set") == 0) {
        index = atoi(argv[2]);
        value = atoi(argv[3]);
        result = syscall(__NR_set_array, index, value);
        printf("result : %d\n", result);

    } else if (argc == 3 && strcmp(argv[1], "get") == 0) {
        index = atoi(argv[2]);
        result = syscall(__NR_get_array, index);
        printf("result : %d\n", result);

    } else {
        printf("Usage : %s set <index> <value>\n", argv[0]);
        printf("        %s get <index>\n", argv[0]);
        return -1;
    }

    return 0;
}
