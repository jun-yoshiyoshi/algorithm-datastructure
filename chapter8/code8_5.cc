#include <iostream>

using namespace std;

struct Node
{
    Node *prev, *next;
    string name;
    Node(string name_ = " ") : prev(NULL), next(NULL), name(name_) {}
};