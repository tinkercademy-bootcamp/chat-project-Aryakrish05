.PHONY: all clean

all: make_dir src/build/client src/build/server

make_dir:
	mkdir -p src/build

src/build/client: src/build/client_main.o src/build/socket_creation.o src/build/tcp_echo_client.o
	g++ $^ -o $@
src/build/server: src/build/server_main.o src/build/socket_creation.o src/build/tcp_echo_server.o
	g++ $^ -o $@

src/build/client_main.o: src/client_main.cpp
	g++ -c $^ -o $@

src/build/socket_creation.o: src/socket_creation/socket_creation.cpp
	g++ -c $^ -o $@
src/build/tcp_echo_client.o: src/tcp_echo_client/tcp_echo_client.cpp
	g++ -c $^ -o $@

src/build/server_main.o: src/server_main.cpp
	g++ -c $^ -o $@

src/build/tcp_echo_server.o: src/tcp_echo_server/tcp_echo_server.cpp
	g++ -c $^ -o $@

clean:
	rm -rf src/build