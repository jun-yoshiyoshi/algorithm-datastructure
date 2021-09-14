#include <iostream>

using namespace std;

struct Node
{
    Node *next;
    string name;
    Node(string name_ = " ") : next(NULL), name(name_) {}
}
