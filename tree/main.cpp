#include <iostream>
using namespace std;
#include "Tree.h"
#include "BinaryTree.h"

void print( ElemType &e ){
    std::cout<< e;
}
void test( Node *Test ) {
    Test = NULL;
}
int main() {
//    Node *doTest = new Node;
//    doTest->data = 'A';
//    test( doTest );


//    Tree test;
//    test.create();
//    Node *root = &test.getRoot();

    BinaryTree bishu;
    bishu.create();
    bishu.levelTraverse( print );
//    test.childSwap( root );
//    char ch = 'f';
//    Node* parent = test.parent( 'f' );
//    Tree subtree;
//    subtree.create();
//    Node root = test.getRoot();
//    Node * subtreeNode = & subtree.getRoot();
//    test.insertSubtree( root.childNode, subtreeNode, 1 );
//    char ch = 'f';
//    Node* get = test.locate( ch );
//    test.preorderTraverse( print );
//    cout << endl;
//    std::cout<<std::endl;
//    test.postorderTraverse( print );
//    int depth = test.depth();
//    int leaves = test.countLeaf();
//    Tree get;
//    get = test;
//    Tree get2 = test;
//    test.levelOrderTraverse( print );
//    test.clear();
    return 0;
}