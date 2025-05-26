#ifndef LOGS_DEF_H
#define LOGS_DEF_H

// Directory for log files
#define LOG_DIR "Logs/"

// Maximum length of a log line
#define LOG_MAX_LINE_LENGTH 256

// Buffer size for date string (YYYYMMDD + null terminator)
#define DATE_BUFFER_SIZE 9

// Buffer size for timestamp string (YYYY-MM-DD HH:MM:SS + null terminator)
#define TIMESTAMP_BUFFER_SIZE 20

// Date format for file names (e.g., 20250526)
#define DATE_FORMAT "%Y%m%d"

// Timestamp format for log entries (e.g., 2025-05-26 19:36:12)
#define TIMESTAMP_FORMAT "%Y-%m-%d %H:%M:%S"

typedef enum LogLevel{
    INFO,
    WARNING,
    ERROR
}LogLevel;

extern const char *log_level_names[3];

#endif
