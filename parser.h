#ifndef PARSER_H
#define PARSER_H
#include "logs_def.h"

// Initializes and opens the log file for parsing
int parser_init(const char *file_name);

// Filters and prints log entries for the specified level
void parser_filter(LogLevel level);

// Closes log files
void parser_close(void);

#endif
