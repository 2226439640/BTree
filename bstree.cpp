#include "tree.h"
bstree::bstree()
{
	head = NULL;
}
void bstree::create(Btree &p, elemtype a)
{
	if(!p)
	{
		p = new btree;
		p->data = a;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		(a > p->data) ? create(p->right, a) : create(p->left, a);
	}
}
bool bstree::search(Btree p, elemtype a)
{
	if(a == p->data)
	{
		return true;
	}
	else if(p == NULL)
	{
		return false;
	}
	else
	{
		(a > p->data) ? search(p->right, a) : search(p->left, a); 
	}
}
bool bstree::dele(Btree &p, elemtype a)
{
	if(p->data == a)
	{
		if(NULL == p->left && NULL == p->right)
		{
			delete p;
			p = NULL;
			return true;
		}
		else if(NULL == p->left && p->right)
		{
			Btree q = p->right;
			p->data = p->right->data;
			p->right = p->right->right;
			p->left = p->right->left;
			delete q;
			q = NULL;
			return true;
		}
		else if(p->left && NULL == p->right)
		{
			Btree q = p->left;
			p->data = p->left->data;
			p->right = p->left->right;
			p->left = p->left->left;
			delete q;
			q = NULL;
			return true;
		}
		else
		{
			Btree q = p->left;
			while(q->left)
			{
				q = q->left;
			}
			p->data = q->data;
			if(q->right)
			{
				q->data = q->right->data;
				q = q->right;
				delete q;
				q = NULL;
			}
			else
			{
				delete q;
				q = NULL;
			}
		}
		return true;
	}
	else if(!p)
	{
		return false;
	}
	else
	{
		(a > p->data) ? dele(p->right, a) : dele(p->left, a); 
	}
}
bstree::~bstree()
{
	kill(head);
}
/*int main()
{
	bstree t;
	int a, b, c;
	cin>>a;
	while(a != -1)
	{
		t.create(t.head, a);
		cin>>a;
	}
	t.pretravel(t.head);
	cout<<endl;
	t.midtravel(t.head);
	cout<<endl;
	t.postravel(t.head);
	cout<<endl;
	t.levtravel();
	cout<<endl;
	cin>>b;
	(false == t.search(t.head, b)) ? cout<<"未找到" : cout<<"已找到";
	cout<<endl;
	cin>>c;
	(false == t.dele(t.head, c)) ? cout<<"未找到" : cout<<"已删除";
	t.midtravel(t.head);
	cout<<endl;
	_getch();
	return 0;
}                */                     