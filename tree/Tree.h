//
// Created by yidafu on 2017/11/9.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H
#define ElemType char
#define FLAG '#'
#define CREATE_LENGTH 100
struct Node {
    Node *childNode;
    ElemType data;
    Node *nextSibling;
};
class Tree {
protected:
    Node *root;
private:
    void _desdroy( Node* &TNode );
    char* _preordeCreate( Node* &TNode, char *inorder );
    char* _preordeCreate( Node* *TNode, char *inorder );
    int _depth( Node* &TNode );
    int _countLeaf( Node* &TNode );
    Node* _locate( Node* &TNode, ElemType &e );
    void _copy( Node* &TNodeThis, Node* &TNodeRhs );
    Node* _parent( Node * &TNode, ElemType &e);
    void _preorderRecurseTraverse( Node* &TNode, void (* visit)(ElemType &e) );
    void _postorderTraverseRecursion( Node* &TNode, void (* visit)(ElemType &e) );
    void _preorderStackTraverseBook( Node* &TNode, void (* visit)(ElemType &e) );
    void _preorderStackTraverse( Node* &TNode, void (* visit)(ElemType &e) );
    void _postorderStackTraverse( Node* &TNode, void (* visit)(ElemType &e) );
    void _levelOrderRecurseTraverse( Node* &TNode, void (* visit)(ElemType &e) );
    void _levelOrderStackTraverse( Node* &TNode, void (* visit)(ElemType &e) );
public:
    Tree();
    Tree( Tree &rhs );
    ~Tree();
    bool create();
    bool isEmpty();
    Node& getRoot();
    int depth();
    Node* locate( ElemType &e);
    Node* parent( ElemType &e);
//    bool copy();
    bool deleteSubtree( Node* &TNode, int degree );
    bool insertSubtree( Node* &thisTNode, Node* &toInsert, int degree );
    void clear( );
    int countLeaf();
    void preorderTraverse( void (* visit)(ElemType &e) );
    void postorderTraverse( void (* visit)(ElemType &e) );
    void levelOrderTraverse( void (* visit)( ElemType &e));
    Tree & operator = ( Tree &rhs );
    void childSwap(Node* &TNode);
};

#endif //TREE_TREE_H
