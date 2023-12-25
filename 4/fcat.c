#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

int readfile(char *filename, char find, int start) {
    FILE *file;
    int count = 0;
    char line[1024];

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count >= start) {
            if (find) {
                if (strchr(line, find)) {
                    printf("%s", line);
                }
            } else {
                printf("%s", line);
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    int opt, start = 1;
    char find = 0;

    while ((opt = getopt(argc, argv, "f:")) != -1) {
        switch (opt) {
            case 'f':
                find = *optarg;
                break;
            default:
                printf("Usage: %s [-f<character>] <file list>\n", argv[0]);
                return 1;
        }
    }

    if (optind >= argc) {
        printf("Expected file list.\n");
        return 1;
    }

    for (; optind < argc; optind++) {
        readfile(argv[optind], find, start);
        start = 1;
    }

    return 0;
}
