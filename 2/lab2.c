#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    char line[1024];
    int line_number = 0;

    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), input_file)) {
        line_number++;
        fprintf(output_file, "%4d: %s", line_number, line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
