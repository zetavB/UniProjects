OBJS = main.cpp polinomio.cpp
CC = g++
DEBUG = -g
CFLAGS = -Wall $(DEBUG) -pedantic -c
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = main
INCLUDE = ../include/
BUILD = ../build/$(TARGET)

all:
	@$(CC) $(LFLAGS) $(OBJS) -I$(INCLUDE) -o $(BUILD)
	@echo Success! Use make run to execute.

run:
	@$(BUILD)

clean:
	@\rm -f *.o $(BUILD)
	@echo Binary deleted
