#include "iostream"
#include "conio.h"
#include "queue"
#include "list"
#define M 3
using namespace std;
typedef int elemtype;
typedef struct Tree
{
	elemtype data;
	struct Tree *left, *right;
}*Btree, btree;
/*typedef struct B_Tree
{
	vector<elemtype> data;
	list<struct B_tree*> node;
}*B_tree, B_ttree;*/
typedef struct Heap
{
	elemtype data;
	struct Tree *left, *right, *father;
}*Heaptree, Heapttree;
class tree
{
public:
	tree();
	~tree();
	void create(Btree &p);
	void pretravel(Btree p);
	void midtravel(Btree p);
	void postravel(Btree p);
	void kill(Btree p);
	void levtravel();
	Btree head;
};
class bstree : public tree 
{
public:
	bstree();
	~bstree();
	void create(Btree &p, elemtype a);
	bool search(Btree p, elemtype a);
	bool dele(Btree &p, elemtype a);
};
/*class heap_tree : public tree
{
public:
	heap_tree();
	~heap_tree();
	void insert(Heaptree &p, Heaptree &front, elemtype a);
	void adjust_small(Heaptree &p);
	void adjust_big(Heaptree &p);
	void sort();
	Heaptree root;

};
class b_tree 
{
public:
	b_tree();
	~b_tree();
	void insert();
	void split(B_Tree &p, int localtion);
	bool dele();
	B_Tree root;
};
class bplus_tree : public b_tree
{
	
};*/