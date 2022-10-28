
TARGET = lorentz

# Project structure
BIN = ./bin
LIB = ./lib
SRC = ./src

SRCS = $(shell find $(SRC) -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

# Project output
OUT = $(BIN)/$(TARGET)

# Project dependencies
GLFW_PATH = $(LIB)/glfw


# Project building
CXX = /usr/bin/clang++

CXXFLAGS  = -std=c++20
CXXFLAGS += -Wall -Wextra

LDFLAGS   = -lm -lstdc++ -lGL -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor
LDFLAGS  += $(GLFW_PATH)/src/libglfw3.a 

INCFLAGS  = -I$(SRC)
INCFLAGS += -I$(GLFW_PATH)/include

all: $(TARGET) start

lib:
	cd $(LIB)/glfw && cmake . && make

$(TARGET): $(OBJS)
	@mkdir -p $(BIN)
	$(CXX) $^ -o $(OUT) $(LDFLAGS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -o $@ $< 

start:
	@$(OUT)

clean:
	@rm -rfv $(OBJS) $(OUT) 

.PHONY: start clean lib
