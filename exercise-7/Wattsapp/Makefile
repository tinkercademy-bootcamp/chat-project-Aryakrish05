all: make_dir build/server

make_dir:
	mkdir -p build

build/server: build/main.o build/Server_channel.o build/Server_client.o build/utils.o build/Server.o
	g++ $^ -o $@

build/main.o: main.cpp
	g++ -c $^ -o $@

build/Server_channel.o: Server_channel.cpp
	g++ -c $^ -o $@

build/Server_client.o: Server_client.cpp
	g++ -c $^ -o $@

build/utils.o: utils.cpp
	g++ -c $^ -o $@

build/Server.o: Server.cpp
	g++ -c $^ -o $@

make clean:
	rm -rf build