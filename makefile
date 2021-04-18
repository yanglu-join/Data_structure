data_structure.exe: main.o Sqlist.o
	g++ *.o -o $@
%.o:%.c
	g++ -c $< -o $@
clean:
	rm -rf *.o data_structure.exe
