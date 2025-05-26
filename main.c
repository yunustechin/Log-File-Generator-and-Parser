#include <stdio.h>
#include <string.h>
#include "logger.h"
#include "parser.h"
#include "logs_def.h"

void print_usage(void) {
    fprintf(stdout, "Log File Generator and Parser:\n");
    fprintf(stdout, "Create a log: ./logtool --log \"message\" --level [INFO|WARNING|ERROR]\n");
    fprintf(stdout, "Read the log: ./logtool --parse <file_path> --level [INFO|WARNING|ERROR]\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments.\n");
        print_usage();
        return -1;
    }

    if (strcmp(argv[1], "--log") == 0) {
        if (argc != 5 || strcmp(argv[3], "--level") != 0) {
            fprintf(stderr, "Error: Invalid log command.\n");
            print_usage();
            return -1;
        }

        LogLevel level;
        if (strcmp(argv[4], "INFO") == 0) {
            level = INFO;
        } else if (strcmp(argv[4], "WARNING") == 0) {
            level = WARNING;
        } else if (strcmp(argv[4], "ERROR") == 0) {
            level = ERROR;
        } else {
            fprintf(stderr, "Error: Invalid log level: %s\n", argv[4]);
            print_usage();
            return -1;
        }

        if (log_init("app") != 0) {
            fprintf(stderr, "Error: Logger initialization failed.\n");
            return -1;
        }

        log_write(level, argv[2]);
        log_close();
    }
    else if (strcmp(argv[1], "--parse") == 0) {
        if (argc != 5 || strcmp(argv[3], "--level") != 0) {
            fprintf(stderr, "Error: Invalid parse command.\n");
            print_usage();
            return -1;
        }

        LogLevel level;
        if (strcmp(argv[4], "INFO") == 0) {
            level = INFO;
        } else if (strcmp(argv[4], "WARNING") == 0) {
            level = WARNING;
        } else if (strcmp(argv[4], "ERROR") == 0) {
            level = ERROR;
        } else {
            fprintf(stderr, "Error: Invalid log level: %s\n", argv[4]);
            print_usage();
            return -1;
        }

        if (parser_init(argv[2]) != 0) {
            fprintf(stderr, "Error: Failed to open log file: %s\n", argv[2]);
            return -1;
        }

        parser_filter(level);
        parser_close();
    }
    else {
        fprintf(stderr, "Error: Invalid command: %s\n", argv[1]);
        print_usage();
        return -1;
    }

    return 0;
}