TARGET = lorentz

# Project structure
BIN = ./bin
LIB = ./libs
SRC = ./src

SRCS = $(shell find $(SRC) -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

SYS = $(shell uname)

# Project output
OUT = $(BIN)/$(TARGET)

# Project dependencies
GLFW_PATH = $(LIB)/glfw # Static library
GLAD_PATH = $(LIB)/glad # Compile
GLM_PATH = $(LIB)/glm   # Header only
STB_PATH = $(LIB)/stb  # Header only

# Project building
CC  = clang
CXX = clang++

CXXFLAGS  = -std=c++20 -stdlib=libc++
CXXFLAGS += -Wall -Wextra -Wpedantic -Wno-c99-extensions
CXXFLAGS += -O2 -g
ifeq ($(SYS), Darwin)
CXXFLAGS += -Wno-nullability-completeness
endif

FRAMEWORK =
ifeq ($(SYS), Darwin)
FRAMEWORK += -framework OpenGL -framework Cocoa -framework IOKIT
FRAMEWORK += -framework CoreFoundation 
endif
ifeq ($(SYS), Linux)
FRAMEWORK += -lGL -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor
endif

DEFINES =
ifeq ($(SYS), Darwin)
DEFINES += -DSYS_DARWIN=1
endif
ifeq ($(SYS), Linux)
DEFINES += -DSYS_LINUX=1
endif
ifdef BEAR
DEFINES += -DBEAR=1
endif
ifdef NDEBUG 
DEFINES += -DNDEBUG=1
endif

LDFLAGS   = -lstdc++ -lm $(FRAMEWORK)
LDFLAGS  += $(GLAD_PATH)/src/glad.o 
LDFLAGS  += $(GLFW_PATH)/src/libglfw3.a 

INCFLAGS  = -I$(SRC)
INCFLAGS += -I$(GLAD_PATH)/include 
INCFLAGS += -I$(GLFW_PATH)/include
INCFLAGS += -I$(GLM_PATH)
INCFLAGS += -I$(STB_PATH)

all: $(TARGET) start

lib:
	cd $(LIB)/glfw && cmake -DCMAKE_OSX_DEPLOYMENT_TARGET=11.0 . && make
	cd $(LIB)/glad && $(CC) -O2 -o src/glad.o -Iinclude -c src/glad.c

$(TARGET): $(OBJS)
	@echo "\033[1;33mBuilding target: $@ \033[0m"
	@mkdir -p $(BIN)
	$(CXX) -o $(OUT) $^ $(LDFLAGS) 
	@echo "\033[1;33mFinished building target: $@ \033[0m \n"

%.o: %.cpp 
	@echo "\033[1;33mBuilding target: $@ \033[0m"
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCFLAGS) $(DEFINES)
	@echo "\033[1;33mFinished building target: $@ \033[0m \n"

start:
	@$(OUT)

clean:
	@rm -rfv $(OBJS) $(OUT) 

.PHONY: start clean lib
