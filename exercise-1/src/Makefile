all: client server
#you need not specify build/ ? Why ?
client: tcp_echo_client.cc
	mkdir -p build
#-p creates a new directory if it doesn't exist only, no error is thrown
	g++ tcp_echo_client.cc -o build/client

server: tcp_echo_server.cc
	mkdir -p build
	g++ tcp_echo_server.cc -o build/server

clean:
	rm -rf build
