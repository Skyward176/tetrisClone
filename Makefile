main: ./src/main.cpp
	g++ ./src/main.cpp -o ./bin/main
clean:
	rm -f ./src/main.cpp
