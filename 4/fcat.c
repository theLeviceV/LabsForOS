#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int read_file(const char *file, int lines, int line_number);
void print_lines(int fd, int lines, int line_number);

int main(int argc, char *argv[]) {
    int lines = 0;
    int line_number = 1;

    // check for options
    if (argc > 1 && argv[1][0] == '-') {
        lines = atoi(&argv[1][2]);
        argv++;
        argc--;
    }

    if (argc == 1) {
        printf("Usage: %s [-n<integer>] <file list>\n", argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        if (read_file(argv[i], lines, line_number) == -1) {
            perror("Error reading file");
            exit(1);
        }
    }

    return 0;
}

int read_file(const char *file, int lines, int line_number) {
    struct stat sb;
    if (stat(file, &sb) == -1) {
        perror("Cannot stat file");
        return -1;
    }

    if (!S_ISREG(sb.st_mode)) {
        fprintf(stderr, "%s is not a regular file\n", file);
        return -1;
    }

    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror("Cannot open file");
        return -1;
    }

    print_lines(fd, lines, line_number);

    close(fd);
    return 0;
}

void print_lines(int fd, int lines, int line_number) {
    char buffer[BUFSIZ];
    ssize_t bytes_read;
    int chars_printed = 0;

    while ((bytes_read = read(fd, buffer, BUFSIZ)) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                line_number++;
                chars_printed = 0;
            } else {
                if (lines == 0 || chars_printed < lines) {
                    putchar(buffer[i]);
                    chars_printed++;
                }
            }
        }
    }
}
