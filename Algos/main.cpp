//
//  main.cpp
//  Algos
//
//  Created by Pushkar Ratnalikar on 8/19/15.
//  Copyright (c) 2015 I. All rights reserved.
//

#include <iostream>
#include "sort.h"
#include "bitmap.h"
#include "tree.h"

bool isBitSet(unsigned int& num, int idx){
    return (num & (unsigned int)0x1 << idx)? true:false;
}

void tobin(unsigned n){
    for(unsigned  i = 1 << 31; i > 0; i = i/2){
        (n & i) ? printf("1") : printf("0");
    }
}

int main(int argc, const char * argv[]) {
    
    /*vector<int> output;
    GenerateNumbers(1, output);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, "  "));
    cout << "\n----------------------------" <<  endl;
    output.clear();
    GenerateNumbers(15, output);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, "  "));
    cout << "\n----------------------------" <<  endl;
    unsigned int x = 1;
    char* a = (char*)&x;
    printf("%d\n",*a);*/
    
    /*BitMap x(150);
    x.print();
    x.mark(140);
    printf("%d\n", x.isset(4));
    printf("%d\n", x.isset(140));
    printf("%d\n", x.isset(141));*/
    
    unsigned int  x= 8176;
    int cnt = 0;
    for(; x; x &= (x-1),cnt++){}
    
    x=8176;
    tobin(x);
    return 0;
    
}
