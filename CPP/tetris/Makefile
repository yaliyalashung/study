#Makefile for Tetris project

CXX := g++
CXXFLAGS := -g -Wall -std=c++11
TARGET := main.exe
SRC := main.cpp Display.cpp GameEngine.cpp
OBJS := $(SRC:.cpp=.o)
INCLUDES := -I.

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(SRC)

clean:
	del /Q *.o *.exe 2>nul || true