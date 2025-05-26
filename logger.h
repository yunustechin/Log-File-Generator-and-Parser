#ifndef LOGGER_H
#define LOGGER_H
#include "logs_def.h"

// Initializes and opens the log file
int log_init(const char *file_prefix);

// Writes a log message with the specified level
void log_write(LogLevel level, const char *message);

// Closes the log file
void log_close(void);

#endif
