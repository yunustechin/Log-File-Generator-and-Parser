CC = gcc
CFLAGS = -Wall -g -O2
TARGET = logtool
SRCS = main.c logger.c parser.c utils.c logs_def.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all