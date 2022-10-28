
TARGET = lorentz

# Project structure
BIN = ./bin
LIB = ./lib
SRC = ./src

SRCS = $(shell find $(SRC) -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

# Project output
OUT = $(BIN)/$(TARGET)


# Project building
CXX = /usr/bin/clang++

CXXFLAGS  = -std=c++20
CXXFLAGS += -Wall -Wextra

LDFLAGS   = -lm -lstdc++

INCFLAGS  = -iquotesrc

all: $(TARGET)

$(TARGET): $(OBJS)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN)
	$(CXX) $^ -o $(OUT) $(LDFLAGS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -o $@ $< 

start:
	@$(OUT)

clean:
	@rm -rfv $(OBJS) $(OUT) 

.PHONY: start clean
