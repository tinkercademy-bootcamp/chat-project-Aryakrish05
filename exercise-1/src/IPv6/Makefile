all: client server

client: tcp_echo_client.cc
	mkdir -p build
	g++ tcp_echo_client.cc -o build/client

server: tcp_echo_server.cc
	mkdir -p build
	g++ tcp_echo_server.cc -o build/server

clean:
	rm -rf build
