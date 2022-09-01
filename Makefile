#Directories
SOURCE = src
BUILD = bin

# Output
EXEC=$(BUILD)/main.exec

#Objects
OBJ = $(BUILD)/main.o


# SDL Compile Options
CC_SDL =-F/Library/Frameworks -framework SDL2
# SDL Linker Options
LL_SDL = -F/Library/Frameworks -framework SDL2

all: build

$(BUILD)/main.o: $(SOURCE)/main.cpp
	g++ -c $(CC_SDL) -o $(BUILD)/main.o $(SOURCE)/main.cpp

build: $(OBJ) Makefile
	g++ $(LL_SDL) -o $(EXEC) $(OBJ) -v
clean:
	rm -f $(BUILD)/*
