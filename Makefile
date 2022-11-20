build_all:
	mkdir -p build

	clang -O0 -g -Wall -Werror -fsanitize=address sort.c test_sort.c -o build/test_sort.out

	clang -O0 -g -Wall -Werror -fsanitize=address linear_search.c test_linear_search.c -o build/test_linear_search.out

	clang -O0 -g -Wall -Werror -fsanitize=address vec.c test_vec.c -o build/test_vec.out

test: build_all
	./build/test_sort.out
	./build/test_linear_search.out
	./build/test_vec.out




