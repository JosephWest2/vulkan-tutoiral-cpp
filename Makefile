CPP_COMPILER = g++
MACRO_DEFINITIONS = -D NDEBUG
FLAGS = -std=c++2b -O2
CPP_FILES = ${shell find ./src -type f -name *.cpp}
LIB_PATHS =  -L/Users/josephwest/VulkanSDK/1.3.290.0/macOS/lib
HEADER_PATHS = -I/Users/josephwest/VulkanSDK/1.3.290.0/macOS/include
LINKED_LIBS = -lglfw -lvulkan -ldl -pthread -lX11 -lXxf86vm -lXrandr -lXi

all: ${CPP_FILES}
	${CPP_COMPILER} ${FLAGS} -o ./bin/vulkan_engine ${CPP_FILES} ${LIB_PATHS} ${HEADER_PATHS} ${LINKED_LIBS}
clean:
	rm -f ./bin/vulkan_engine
