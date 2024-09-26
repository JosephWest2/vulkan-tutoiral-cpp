CPP_COMPILER = g++
MACRO_DEFINITIONS = -D NDEBUG
FLAGS = -std=c++23 -O2
CPP_FILES = ${shell find ./src -type f -name *.cpp}
LINKED_LIBS = -lglfw -lvulkan -ldl -pthread -lX11 -lXxf86vm -lXrandr -lXi

all: ${CPP_FILES}
	${CPP_COMPILER} ${FLAGS} -o ./bin/vulkan_engine ${CPP_FILES} ${LINKED_LIBS}
clean:
	rm -f ./bin/vulkan_engine
