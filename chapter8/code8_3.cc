#include <iostream>
#include <vector>

using namespace std;
struct Node
{
    Node *next;
    string name;
    Node(string name_ = " ") : next(NULL), name(name_) {}
}

void
insert(Node *v, Node *p)
{
    v->next = p->next;
    p->next = v;
}