#!/bin/sh

assert_equal () {
	diff "$1" "$2" || printf "F: \"%s\" != \"%s\"\n" $1 $2
}

# Single argument, positive number
cat ./test/1.txt | ./prep > ./test/out.txt

assert_equal "./test/1.default.ref" "./test/out.txt"

cat ./test/1.txt | ./prep -- > ./test/out.txt

assert_equal "./test/1.lua.ref" "./test/out.txt"

cat ./test/2.txt | ./prep > ./test/out.txt

assert_equal "./test/2.default.ref" "./test/out.txt"
