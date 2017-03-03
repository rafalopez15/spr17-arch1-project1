all: PersonalManagementSystem

CFLAGS = -g -O3

PersonalManagementSystem: TreeNode.o PersonalManagementSystem.o
	cc -o $@ $^

TreeNode.o: TreeNode.c TreeNode.h
	cc -c $(CFLAGS) TreeNode.c

PersonalManagementSystem.o: PersonalManagementSystem.c TreeNode.h
	cc -c $(CFLAGS) PersonalManagementSystem.c

clean:
	rm -f *.o PersonalManagementSystem

demo: PersonalManagementSystem
	(echo "Rafa"; echo "Kevin"; echo "Marco") | ./PersonalManagementSystem
