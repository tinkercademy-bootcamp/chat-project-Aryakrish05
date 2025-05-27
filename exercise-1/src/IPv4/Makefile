all: client server
#you need not specify build/ ? Why ?
#here the make first tries to build all which has dependencies client and server
#it checks to build client and server and if there are any changes then it recompiles
client: tcp_echo_client.cc
	mkdir -p build
#-p creates a new directory if it doesn't exist only, no error is thrown
	g++ tcp_echo_client.cc -o build/client

server: tcp_echo_server.cc
	mkdir -p build
	g++ tcp_echo_server.cc -o build/server

clean:
	rm -rf build
