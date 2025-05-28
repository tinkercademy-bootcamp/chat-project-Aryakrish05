.PHONY: all clean
CXX:=g++
CXX_FLAGS:= -fsanitize=address
#CXX_FLAGS:=-S -fsanitize=address
LD_FLAGS:= -fsanitize=address
all: build/client build/server

build/client: tcp_echo_client.cc
	mkdir -p build
	$(CXX) $(CXX_FLAGS) tcp_echo_client.cc -o build/client $(LD_FLAGS)

build/server: tcp_echo_server.cc
	mkdir -p build
	$(CXX) $(CXX_FLAGS) tcp_echo_server.cc -o build/server $(LD_FLAGS)

clean:
	rm -rf build
