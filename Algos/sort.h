//
//  sort.h
//  Algos
//
//  Created by Pushkar Ratnalikar on 8/19/15.
//  Copyright (c) 2015 I. All rights reserved.
//

#ifndef Algos_sort_h
#define Algos_sort_h

#include <queue>
#include <vector>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <cassert>
#include <functional>

using namespace std;

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

void GenerateNumbers(int n, vector<int>& output){
    assert(n > 0);
    int arr[] = {2, 3, 5, 7};
    priority_queue<int, vector<int>, greater<int> > q(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int prev = 0;
    while(output.size() < n){
        int m = q.top();
        q.pop();
        if(prev != m){
            output.push_back(m);
            for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
                q.push(m * arr[i]);
            }
            prev = m;
        }
    }
}

#endif
