# Log File Generator and Parser

A lightweight C-based command-line tool for generating and parsing log files with customizable log levels (INFO, WARNING, ERROR). This project provides a robust logging system that creates timestamped log files and allows filtering of log entries based on their severity level.

## Features

- **Log Generation**: Create log files with a specified prefix and date-based naming convention (e.g., `app_20250505.log`).
- **Log Parsing**: Filter and display log entries from a file based on a specified log level.
- **Customizable Log Levels**: Supports three log levels: INFO, WARNING, and ERROR.
- **Timestamped Logs**: Each log entry includes a timestamp in the format `YYYY-MM-DD HH:MM:SS`.
- **Cross-Platform Compatibility**: Uses standard C libraries for portability.
- **Error Handling**: Robust error checking for file operations, input validation, and formatting.

## Installation

### Prerequisites
- A C compiler (e.g., `gcc`)
- GNU Make
- POSIX-compliant system (Linux, macOS, or Windows with a POSIX environment like MinGW or WSL)

### Build Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/Log-File-Generator-and-Parser.git
   cd Log-File-Generator-and-Parser
   ```
2. Build the project using the provided Makefile:
   ```bash
   make
   ```
   This will generate the `logtool` executable.
3. (Optional) Clean the build artifacts:
   ```bash
   make clean
   ```

## Usage

The `logtool` program supports two main commands: `--log` for writing logs and `--parse` for reading and filtering logs.

### Writing a Log
To write a log message to a file:
```bash
./logtool --log "Your message here" --level [INFO|WARNING|ERROR]
```
- Example:
  ```bash
  ./logtool --log "Application started successfully" --level INFO
  ```
  This creates a log file in the `Logs/` directory (e.g., `Logs/app_20250505.log`) with an entry like:
  ```
  [2025-05-05 19:36:12] [INFO] Application started successfully
  ```

### Parsing a Log
To parse a log file and filter by log level:
```bash
./logtool --parse <file_path> --level [INFO|WARNING|ERROR]
```
- Example:
  ```bash
  ./logtool --parse Logs/app_20250505.log --level ERROR
  ```
  This displays all log entries with the `ERROR` level from the specified file.

### Help
To display usage instructions:
```bash
./logtool
```

## Project Structure

```
log-file-generator-and-parser/
├── Logs/                  # Directory for generated log files
├── main.c                 # Main program logic and command-line interface
├── logger.c               # Log file creation and writing functions
├── logger.h               # Logger function declarations
├── parser.c               # Log file parsing and filtering functions
├── parser.h               # Parser function declarations
├── utils.c                # Utility functions for timestamp and date handling
├── utils.h                # Utility function declarations
├── logs_def.c             # Log level definitions and constants
├── logs_def.h             # Log level enum and constants
├── Makefile               # Build script
└── README.md              # Project documentation
```

## Contributing

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a feature branch (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -m "Add your feature"`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Open a Pull Request.

Please ensure your code follows the project's coding style and includes appropriate error handling.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For questions or feedback, please open an issue on the GitHub repository.