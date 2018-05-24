flex scanner.l
g++ lex.yy.c -lfl -o scanner.out
./scanner.out input.c
