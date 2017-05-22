Quine verification:

gcc quine.c
./a.out > quine2.c
diff quine.c quine2.c

Concept:

https://stackoverflow.com/questions/105725/how-to-write-a-self-reproducing-code-prints-the-source-on-exec

Inspiration:

https://github.com/mame/quine-relay
