#include "tree.h"
tree::tree()
{
	head = new btree;
	head->data = 0;
	head->left = NULL;
	head->right = NULL;
}
void tree::create(Btree &p)
{
	p = new btree;
	cin>>p->data;
	if(p->data)
	{
		create(p->left);
		create(p->right);
	}
	else
	{
		p = NULL;
	}
}
void tree::pretravel(Btree p)
{
	if(p)
	{
		cout<<p->data<<" ";
		pretravel(p->left);
		pretravel(p->right);
	}
}
void tree::midtravel(Btree p)
{
	if(p)
	{
		midtravel(p->left);
		cout<<p->data<<" ";
		midtravel(p->right);
	}	
}
void tree::postravel(Btree p)
{
	if(p)
	{
		postravel(p->left);
		postravel(p->right);
		cout<<p->data<<" ";
	}
}
void tree::levtravel()
{
	queue<Btree> q;
	Btree p = NULL;
	q.push(head);
	while(!q.empty())
	{
		p = q.front();
		if(p->left)
		{
			q.push(p->left);
		}
		if(p->right)
		{
			q.push(p->right);
		}
		cout<<p->data<<" ";
		q.pop();
	}
}
void tree::kill(Btree p)
{
	if(p)
	{
		kill(p->left);
		kill(p->right);
		delete p;
		p = NULL;
	}
}
tree::~tree()
{
	kill(head);
}
/*int main()
{
	tree t;
	t.create(t.head);
	t.pretravel(t.head);
	cout<<endl;
	t.midtravel(t.head);
	cout<<endl;
	t.postravel(t.head);
	cout<<endl;
	t.levtravel();
	_getch();
	return 0;
}*/