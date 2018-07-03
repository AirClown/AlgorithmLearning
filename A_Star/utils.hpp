
#include<stdio.h>
#include<Windows.h>
#include<math.h>

using namespace std;

struct Position {
	int x;
	int y;
	int G;
	int H;
	Position *parent;
	Position *next;
};

class List {
public:
	void Add(int x, int y, Position *parent);
	void AddOne(Position *point);
	void Delet(int x, int y);
	Position *Find(int x, int y);
	Position* FindMin();
	void Change(int x, int y, Position *parent);
	Position *LastOne();
	void printList();
	void DestroyList();
	List();

private:
	Position *head;
};