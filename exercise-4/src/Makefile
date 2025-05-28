.PHONY: all clean

all: make_dir build/client build/server

make_dir:
	mkdir -p build

build/client: build/client_main.o build/socket_creation.o build/tcp_echo_client.o
	g++ build/client_main.o build/socket_creation.o build/tcp_echo_client.o -o build/client

build/server: build/server_main.o build/socket_creation.o build/tcp_echo_server.o
	g++ build/server_main.o build/socket_creation.o build/tcp_echo_server.o -o build/server

build/client_main.o: client_main.cpp
	g++ -c client_main.cpp -o build/client_main.o

build/socket_creation.o: cpp_files/socket_creation.cpp
	g++ -c cpp_files/socket_creation.cpp -o build/socket_creation.o

build/tcp_echo_client.o: cpp_files/tcp_echo_client.cpp
	g++ -c cpp_files/tcp_echo_client.cpp -o build/tcp_echo_client.o

build/server_main.o: server_main.cpp
	g++ -c server_main.cpp -o build/server_main.o

build/tcp_echo_server.o:cpp_files/tcp_echo_server.cpp
	g++ -c cpp_files/tcp_echo_server.cpp -o build/tcp_echo_server.o

clean:
	rm -rf build