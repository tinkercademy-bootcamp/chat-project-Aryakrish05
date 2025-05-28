.PHONY: all clean

all: make_dir build/client build/server

make_dir:
	mkdir -p build

build/client: build/client_main.o build/socket_creation.o build/tcp_echo_client.o
	g++ $^ -o $@
build/server: build/server_main.o build/socket_creation.o build/tcp_echo_server.o
	g++ $^ -o $@

build/client_main.o: client_main.cpp
	g++ -c $^ -o $@

build/socket_creation.o: cpp_files/socket_creation.cpp
	g++ -c $^ -o $@
build/tcp_echo_client.o: cpp_files/tcp_echo_client.cpp
	g++ -c $^ -o $@

build/server_main.o: server_main.cpp
	g++ -c $^ -o $@

build/tcp_echo_server.o:cpp_files/tcp_echo_server.cpp
	g++ -c $^ -o $@

clean:
	rm -rf build