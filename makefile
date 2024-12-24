CC = gcc
CFLAGS = -Wall -Wextra -std=c23

SRC = src_c/*.c


default: run

build:
	$(CC) $(SRC) $(CFLAGS) -o aoc.out

clean:
	rm ./aoc.out
exec:
	./aoc.out

run: build all clean

all:
	./aoc.out day1.txt 1
	./aoc.out day2.txt 2
	./aoc.out day3.txt 3
	./aoc.out day4.txt 4
	./aoc.out day5.txt 5
	./aoc.out day6.txt 6
	./aoc.out day7.txt 7
	./aoc.out day8.txt 8
	./aoc.out day9.txt 9
	./aoc.out day10.txt 10
	./aoc.out day11.txt 11
	./aoc.out day12.txt 12
	./aoc.out day13.txt 13
	./aoc.out day14.txt 14
	./aoc.out day15.txt 15
	./aoc.out day16.txt 16
	./aoc.out day17.txt 17
	./aoc.out day18.txt 18
	./aoc.out day19.txt 19
	./aoc.out day20.txt 20
	./aoc.out day21.txt 21
	./aoc.out day22.txt 22
	./aoc.out day23.txt 23
	./aoc.out day24.txt 24
