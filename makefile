CC = g++ 
BUILD = build
BIN = debug.exe
%.o : %.cpp
	$(CC) -c $< -o "$(BUILD)\\$@" 
main.o : main.cpp
clean: 
	cd  $(BUILD) && rm -f *.o *.exe
all: main.o
	$(CC) -g "$(BUILD)\\*.o" -o "$(BUILD)\\$(BIN)" 
run:
	cmd /c start cmd /k .\$(BUILD)\\$(BIN)