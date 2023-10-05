pr: main.o
	g++ main.o -o pr

main.o: main.cpp
	g++ -g -Wall -Wextra -Werror -pedantic -std=c++11 -c main.cpp

test_array.o: test_array.h test_array.cpp
	g++ -g -Wall -Wextra -Werror -pedantic -std=c++11 -c test_array.cpp

test_runner.o: test_runner.cpp
	g++ -g -Wall -Wextra -Werror -pedantic -std=c++11 -c test_runner.cpp

clean:
	rm -f *.o *.h.gch pr*
