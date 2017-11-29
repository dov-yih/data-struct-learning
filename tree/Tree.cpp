//
// Created by yidafu on 2017/11/9.
//
#include <iostream>
#include <stack>
#include "Tree.h"

using namespace std;

Tree::Tree() {
    this->root = NULL;
}
Tree::Tree( Tree &rhs ) {
//    this->root = NULL;
    this->_copy( this->root, rhs.root);
}

Tree::~Tree() {
    this->clear( );
}

char* Tree::_preordeCreate( Node* &TNode, char *preorder) {
    if ( *preorder == FLAG ) {
        TNode = NULL;
    } else {
        TNode = new Node;
        TNode->data = *preorder;
        preorder = this->_preordeCreate( TNode->childNode, ++ preorder );
        preorder = this->_preordeCreate( TNode->nextSibling, ++ preorder );
    }
    return preorder;
}

char* Tree::_preordeCreate(Node **TNode, char *inorder) {

    if ( *inorder == FLAG ) {
        TNode = NULL;
    } else {
        *TNode = new Node;
        (*TNode)->data = *inorder;
        ++ inorder;
        inorder = this->_preordeCreate( (*TNode)->childNode, ++ inorder );
        inorder = this->_preordeCreate( (*TNode)->nextSibling, ++ inorder );
    }
    return inorder;
}

bool Tree::create() {
//    char line[ CREATE_LENGTH ];
//    cin.getline( line, CREATE_LENGTH );
//    char *line = "abe#f##c#dg#h#j####";
//    char *line = "ab#cd#ei#j##g##h###";
//    char *line = "ab##c##";
    char *line = "abd##e##cf##g##";
    this->_preordeCreate( this->root, line );
    return true;
}

Node& Tree::getRoot() {
    return *this->root;
}

void Tree::_desdroy( Node* &TNode ) {
    if( TNode ) {
        this->_desdroy( TNode->childNode );
        this->_desdroy( TNode->nextSibling );
        delete TNode;
    }
}
void Tree::clear() {
    this->_desdroy( this->root );
    this->root = NULL;
}

bool Tree::deleteSubtree(Node* &TNode, int degree) {
    Node* &child = TNode->childNode;
    int count = 1;
    while( child && count < degree) {
        child = child->nextSibling;
        ++ count;
    }
    if ( child ) {
        Node* toDel = child;
        child = NULL;
        this->_desdroy( toDel );
        return true;
    } else {
        return false;
    }
}

bool Tree::insertSubtree( Node* &TNode, Node* &toInsert, int degree ) {
    Node* &child = TNode;
    int count = 1;
    while ( child && count < degree ) {
        child = child->nextSibling;
        ++ count;
    }
//     这里是 Node* (-_-)
    Node* tmpSave = child->nextSibling;
    child->nextSibling = toInsert;
    toInsert->nextSibling = tmpSave;
    return true;
}

bool Tree::isEmpty() {
    return this->root == NULL;
}
int Tree::_depth(Node *&TNode) {
    if ( TNode ) {
        int childDepth = this->_depth( TNode->childNode );
        int siblingDepth = this->_depth( TNode->nextSibling );
        return ++ childDepth > siblingDepth ? childDepth : siblingDepth;
    } else {
        return 0;
    }
}
int Tree::depth() {
    this->_depth( this->root );
}

int Tree::_countLeaf( Node* &TNode ) {
    if( TNode ) {
        int childLeaves = this->_countLeaf( TNode->childNode );
        int silingLeaves = this->_countLeaf( TNode->nextSibling );
        // 树叶存在判定：只有当 childNode 指针为空的时候，该节点才是树叶
        if ( ! TNode->childNode ) {
            ++ childLeaves;
        }
        return childLeaves + silingLeaves;
    } else {
        return 0;
    }
}
int Tree::countLeaf() {
    return this->_countLeaf( this->root );
}
Node* Tree::_locate( Node* &TNode, ElemType &e ) {
    if ( !TNode ) {
        return TNode;
    }
    Node* toRet;
    if ( TNode->data == e ) {
        return TNode;
    }
    toRet = this->_locate( TNode->childNode, e );
    if ( toRet ) {
        return toRet;
    }
    toRet  = this->_locate( TNode->nextSibling, e);
    return toRet;
}
Node* Tree::locate( ElemType &e) {
    return this->_locate( this->root, e );
}
void Tree::_copy( Node* &TNodeThis, Node* &TNodeRhs ) {
    if( TNodeRhs == NULL ) {
        TNodeThis = NULL;
    } else {
        TNodeThis = new Node;
        TNodeThis->data = TNodeRhs->data;
        this->_copy( TNodeThis->childNode , TNodeRhs->childNode );
        this->_copy( TNodeThis->nextSibling, TNodeRhs->nextSibling );
    }
}

Node* Tree::_parent(Node* &TNode, ElemType &e) {
    if ( ! TNode ) {
        return TNode;
    }
    if ( TNode->data == e ) {
        return TNode;
    } else {
        Node *toRet;
        toRet = this->_parent( TNode->childNode, e );
        if ( toRet ) {
            return TNode;
        }
        toRet = this->_parent( TNode->nextSibling, e );
        if ( toRet ) {
            return TNode;
        } else {
            return NULL;
        }
    }
}
Node* Tree::parent( ElemType &e ) {
    // @FIXME 这里存在一个问题，兄弟节点求父节点
    if ( this->root->data != e ) {
        return this->_parent( this->root->childNode, e );
    } else {
        return NULL;
    }
}

Tree & Tree::operator = (Tree &rhs) {
    this->_copy( this->root, rhs.root );
    return *this;
}
void Tree::_preorderRecurseTraverse( Node* &TNode, void (* visit)(ElemType &e) ) {
    if( TNode != NULL ) {
        visit( TNode->data );
        this->_preorderRecurseTraverse( TNode->childNode, visit );
        this->_preorderRecurseTraverse( TNode->nextSibling, visit );
    }
}

void Tree::_preorderStackTraverse(Node* &TNode, void (* visit)( ElemType &e) ) {
    stack<Node *> Traverse;
    Traverse.push( TNode );
    while ( ! Traverse.empty() ) {
        Node* topOne = Traverse.top();
        Traverse.pop();
        // 非空元素
        if( topOne ) {
            visit( topOne->data );
        } else {
            continue;
        }
        Traverse.push( topOne->nextSibling );
        Traverse.push( topOne->childNode );
    }
}

void Tree::_preorderStackTraverseBook( Node* &TNode, void (* visit)(ElemType &e) ) {
    stack<Node *> Traverse;
    Traverse.push( TNode );
    while( ! Traverse.empty() ) {
        Node* topOne = Traverse.top();
        if( topOne->childNode == NULL ) {
            Traverse.pop();
            if( topOne->nextSibling ) {
                Traverse.push( topOne->nextSibling );
            }
            visit( topOne->data );
        } else {
            Traverse.push( topOne->childNode );
        }
    }
}
void Tree::_postorderStackTraverse(Node* &TNode, void (* visit)( ElemType &e) ) {
    stack<Node *> Traverse;
    Traverse.push( TNode );
    while ( true ) {
        // 入栈操作
        Node *topOne = Traverse.top();
        Traverse.pop();
        if (!topOne) {
            if ( Traverse.empty() ) {
                break;
            }
            topOne = Traverse.top();
            Traverse.pop();
            visit(topOne->data);
            continue;
        }
        Traverse.push(topOne->nextSibling);
        Traverse.push(topOne);
        Traverse.push(topOne->childNode);
    }
}

void Tree::preorderTraverse( void (* visit)( ElemType &e) ) {
    this->_preorderRecurseTraverse( this->root, visit );
    std::cout<<std::endl;
    this->_preorderStackTraverse( this->root, visit );
    std::cout << std::endl;
    this->_preorderStackTraverseBook( this->root, visit );
}

void Tree::_postorderTraverseRecursion( Node* &TNode, void (* visit)(ElemType &e) ) {
    if( TNode != NULL ) {
        this->_postorderTraverseRecursion( TNode->childNode, visit );
        visit( TNode->data );
        this->_postorderTraverseRecursion( TNode->nextSibling, visit );
    }
}
void Tree::postorderTraverse( void (* visit)( ElemType &e) ) {
    this->_postorderTraverseRecursion( this->root, visit );
    std::cout<<std::endl;
    this->_postorderStackTraverse( this->root, visit );
}

void Tree::_levelOrderRecurseTraverse(Node *&TNode, void (* visit)(ElemType &e)) {
    if( TNode ){
        visit( TNode->data );
        this->_levelOrderRecurseTraverse( TNode->nextSibling, visit );
        this->_levelOrderRecurseTraverse( TNode->childNode, visit );
    }
}

void Tree::_levelOrderStackTraverse(Node* &TNode, void (* visit)(ElemType &e)) {
//    stack Traverse;

}
void Tree::levelOrderTraverse(void (* visit)(ElemType &e)) {
    this->_levelOrderRecurseTraverse( this->root, visit );
}