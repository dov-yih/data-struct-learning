//
// Created by yidafu on 2017/11/9.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H
#define ElemType char
#define flag '#'
struct Node{
    Node *childNode;
    ElemType data;
    Node *nextSibling;
};
class Tree {
private:

    Node *root;
public:
    Tree();
    ~Tree();
    bool create( Node &toCrate );
    bool isEmpty();
    int depth();
    int locate();
    Node parent();
    bool Copy();
    void clear( Node &to_delete);
    int countLeaf();
    void PreorderTraverse();
    void inorderTreverse();
    void postorderTreverse();

};


#endif //TREE_TREE_H
