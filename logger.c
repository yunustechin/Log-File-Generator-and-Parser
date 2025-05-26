#include <stdio.h>
#include <sys/stat.h>
#include "logger.h"
#include "utils.h"

static FILE *log_file = NULL;

int log_init(const char *file_prefix) {
    char file_name[256];
    char date_str[16];
    mkdir(LOG_DIR);

    if (current_date(date_str) !=0) {
        return -1;
    }

    if (file_prefix == NULL) {
        file_prefix = "";
    }

    snprintf(file_name, sizeof(file_name), "%s/%s_%s.log", LOG_DIR, file_prefix, date_str);

    log_file = fopen(file_name, "a");
    if (log_file == NULL) {
        return -1;
    }

    return 0;
}


void log_write(LogLevel level, const char *message) {
    if (log_file) {
        if (log_file == NULL || message == NULL) {
            return;
        }

        char timestamp[32];
        if (current_timestamp(timestamp,sizeof(timestamp)) != 0) {
            timestamp[0] = '\0';
        }

        fprintf(log_file, "[%s] [%s] %s\n", timestamp, log_level_names[level], message);
        fflush(log_file);
    }
}


void log_close(void) {
    if (!log_file) {
        return;
    }

    if (fclose(log_file) != 0 ) {
        fprintf(stderr, "Error: Log file close failed\n");
    }

    log_file = NULL;
}
