# Log File Generator and Parser

This project is a tool designed to generate and parse log files. It is written in C, focusing on performance and efficiency.

## Features
- **Log File Generation**: Creates log files in a specified format.
- **Log Parsing**: Reads and analyzes log files based on specific criteria.
- **Customizable Format**: Allows users to define the log format.
- **Fast and Lightweight**: Optimized for minimal system resource consumption.

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/username/Log-File-Generator-and-Parser.git
   cd Log-File-Generator-and-Parser
   ```
2. Compile the project:
   ```sh
   gcc -o log_parser log_parser.c
   ```
3. Run the program:
   ```sh
   ./log_parser
   ```

## Usage
### Generating a Log File
```sh
./log_parser -g output.log
```
This command generates a log file named `output.log`.

### Parsing a Log File
```sh
./log_parser -p output.log
```
This command reads and analyzes the `output.log` file.

## Example Log Format
```txt
[2025-04-02 14:35:10] [INFO] System started.
[2025-04-02 14:40:15] [ERROR] Connection error occurred.
```

## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.
