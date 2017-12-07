ifeq ($(mode), debug)
    # Отладочная сборка: добавим генерацию отладочной информации
    CFLAGS += -g3
endif

ifeq ($(mode), release)
    # Финальная сборка: исключим отладочную информацию и утверждения (asserts)
    CFLAGS += -DNDEBUG -g0
endif

main.exe: main.o createnode.o insert.o apply.o getnum.o createdot.o tick.o rotateright.o helpfunc.o rotateleft.o balance.o insertavl.o
	gcc -o main.exe createnode.o insert.o apply.o getnum.o createdot.o tick.o rotateright.o helpfunc.o rotateleft.o balance.o insertavl.o main.o
main.o: main.c main.h createnode.h insert.h apply.h getnum.h createdot.h tick.h rotateright.h helpfunc.h rotateleft.h balance.h insertavl.h
	gcc -std=c99 -Wall -Werror -c main.c
insertavl.o: insertavl.c insertavl.h main.h insert.h balance.h
	gcc -std=c99 -Wall -Werror -c insertavl.c
balance.o: balance.c balance.h main.h helpfunc.h rotateleft.h rotateright.h
	gcc -std=c99 -Wall -Werror -c balance.c
rotateleft.o: rotateleft.c rotateleft.h main.h helpfunc.h
	gcc -std=c99 -Wall -Werror -c rotateleft.c
rotateright.o: rotateright.c rotateright.h main.h helpfunc.h
	gcc -std=c99 -Wall -Werror -c rotateright.c
helpfunc.o: helpfunc.c helpfunc.h main.h
	gcc -std=c99 -Wall -Werror -c helpfunc.c
tick.o: tick.c tick.h
	gcc -std=c99 -Wall -Werror -c tick.c
createdot.o: createdot.c createdot.h apply.h main.h
	gcc -std=c99 -Wall -Werror -c createdot.c
getnum.o: getnum.c getnum.h createnode.h insert.h main.h helpfunc.h
	gcc -std=c99 -Wall -Werror -c getnum.c
apply.o: apply.c apply.h main.h helpfunc.h
	gcc -std=c99 -Wall -Werror -c apply.c
insert.o: insert.c insert.h main.h createnode.h
	gcc -std=c99 -Wall -Werror -c insert.c
createnode.o: createnode.c createnode.h main.h
	gcc -std=c99 -Wall -Werror -c createnode.c

clean:
	rm *.o *.exe