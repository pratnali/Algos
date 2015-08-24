//
//  bitmap.h
//  Algos
//
//  Created by Pushkar Ratnalikar on 8/19/15.
//  Copyright (c) 2015 I. All rights reserved.
//

#ifndef Algos_bitmap_h
#define Algos_bitmap_h

/*
 * Fixed-size array of bits. (Intended for storage management.)
 *
 * Functions:
 *     bitmap_create  - allocate a new bitmap object.
 *                      Returns NULL on error.
 *     bitmap_getdata - return pointer to raw bit data (for I/O).
 *     bitmap_alloc   - locate a cleared bit, set it, and return its index.
 *     bitmap_mark    - set a clear bit by its index.
 *     bitmap_unmark  - clear a set bit by its index.
 *     bitmap_isset   - return whether a particular bit is set or not.
 *     bitmap_destroy - destroy bitmap.
 */

#define WORD_BIT 32
#define BITS_PER_WORD (WORD_BIT)
#define WORD_TYPE unsigned int
#define DIVRPUNDUP(a,b) (((a) + (b)-1)/(b))

struct BitMap{
private:
    unsigned* data;
    size_t nbits;
    size_t words;
public:
    BitMap(int _nbits):nbits(_nbits){
        words = (nbits + BITS_PER_WORD - 1)/ BITS_PER_WORD;
        data    =   (WORD_TYPE*) malloc(words * sizeof(WORD_TYPE));
        bzero(data, nbits);
        for(int i = 0; i < words; ++i)
            data[i] = (WORD_TYPE)0x0;
        /*if(words >  nbits / BITS_PER_WORD){
            size_t overbits    = (words*BITS_PER_WORD) - nbits ;
            assert(overbits < BITS_PER_WORD && overbits > 0);
            for(int i =0; i < overbits; ++i){
                data[words-1] |= ((WORD_TYPE)0x1) << i;
            }
        }*/
    }
    void translate(int index,  int& idx, WORD_TYPE& mask){
        idx =   index / BITS_PER_WORD;
        int offset = index % BITS_PER_WORD;
        mask    =  1 << offset;
    }
    bool isset(int index){
        int idx;
        WORD_TYPE mask;
        translate(index, idx, mask);
        return (data[idx-1] & mask);
    }
    void print(){
        int idx;
        for(size_t i = 0; i < words; i++){
            for(size_t j = 0; j < 32; j++){
                idx = (i* BITS_PER_WORD) + j;
                printf("%d", isset(idx));
                if(((j+1) % 8) == 0)
                    printf(" ");
            }
            printf("\n");
        }
    }
    void mark(int index){
        assert(index < nbits);
        int idx;
        WORD_TYPE mask;
        translate(index, idx, mask);
        data[idx-1] |= mask;
    }
    void clear(int index){
        assert(index < nbits);
        int idx;
        WORD_TYPE mask;
        translate(index, idx, mask);
        data[idx-1] &= ~mask;
    }
    
    ~BitMap(){free(data);}
    
};
#endif
