#include <stdio.h>
#include <string.h>
#include "parser.h"

static FILE *log_file = NULL;

int parser_init(const char *file_name) {
    if (file_name == NULL || *file_name == '\0') {
        fprintf(stderr, "Error: Invalid or empty file name provided.\n");
        return -1;
    }

    fprintf(stderr, "Debug: Attempting to open file: %s\n", file_name);
    log_file = fopen(file_name, "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error: Failed to open file: %s. Check if file exists or is readable.\n", file_name);
        return -2;
    }

    fprintf(stderr, "Debug: File %s opened successfully.\n", file_name);
    return 0;
}


void parser_filter(LogLevel level) {
    if (log_file == NULL) {
        fprintf(stderr, "Error: Log file is not opened.\n");
        return;
    }

    char line[LOG_MAX_LINE_LENGTH];
    char level_str[16];

    int result = snprintf(level_str, sizeof(level_str), "[%s]", log_level_names[level]);
    if (result < 0 || result >= (int)sizeof(level_str)) {
        fprintf(stderr, "Error: Failed to format log level string.\n");
        return;
    }

    rewind(log_file);

    while (fgets(line, sizeof(line), log_file)) {
        if (strstr(line, level_str) != NULL) {
            fputs(line, stdout);
        }
    }

    fflush(stdout);
}


void parser_close(void) {
    if (!log_file) {
        return;
    }

    if (fclose(log_file) != 0 ) {
        fprintf(stderr, "Error: Log file close failed\n");
    }

    log_file = NULL;
}