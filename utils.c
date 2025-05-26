#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "logs_def.h"

int current_timestamp(char *buffer, size_t buffer_size) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    if (tm == NULL) {
        if (buffer_size > 0) {
            buffer[0] = '\0';
        }
        fprintf(stderr, "Error: Failed to get local time.\n");
        return -1;
    }

    if (strftime(buffer, buffer_size, TIMESTAMP_FORMAT, tm) == 0) {
        if (buffer_size > 0) {
            buffer[0] = '\0';
        }
        fprintf(stderr, "Error: Failed to format timestamp.\n");
        return -2;
    }
    return 0;
}


int current_date(char *buffer) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    if (tm == NULL) {
        buffer[0] = '\0';
        fprintf(stderr, "Error: Failed to get local time.\n");
        return -1;
    }

    if (strftime(buffer, DATE_BUFFER_SIZE, DATE_FORMAT, tm) == 0) {
        buffer[0] = '\0';
        fprintf(stderr, "Error: Failed to format date.\n");
        return -2;
    }
    return 0;
}


