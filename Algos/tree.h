//
//  tree.h
//  Algos
//
//  Created by Pushkar Ratnalikar on 8/19/15.
//  Copyright (c) 2015 I. All rights reserved.
//

#ifndef Algos_tree_h
#define Algos_tree_h
template<typename T = int>
struct tree{
public:
    T data;
    tree* left;
    tree* right;
    tree(T _data){data  =   _data;}
};

/*struct tree* create_tree(){
    struct root* = new tree(0);
    return root;
}*/

#endif
