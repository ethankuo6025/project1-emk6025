#include <stdio.h>
#include <stdlib.h>

/*
1. What are the types of p, pp, *pp, and **pp? What objects do they refer to?

1.  p is an integer pointer, refers to the address of an integer object.
    pp is the pointer for an integer pointer, refers to the address of an address. 
    *pp dereferences pp, and would be the integer pointer equal to p. 
    **pp is the integer found after dereferencing p, the integer value at location p. 
 
2. Explain the difference among p, &p, *p, a, and &a. You do not need to reproduce formal C
type-system terminology, but your explanation must distinguish an address from the object
stored at that address.

2.  p is an integer pointer, stores the memory address of an integer. &p is the address of p itself, 
    aka the address at which the integer's address is stored. *p dereferences p, aka the integer
    value stored at address p. a is an integer array with 4 elements, and &a is the memory address 
    for the start of that array.

3. What does p + 1 mean? If p has numeric address A, is the numeric address of p + 1 normally
A + 1? Explain.

3. p+1 is the address of the object immediately after p. 1 in this case refers to the size of 
the type of object that p is pointing to. for example if p is a char, p+1 would be the next 
immediate char after p, aka the numeric address A+1. if p is a integer, 4 bytes, then p+1 would be A+4. 

4. Predict the three integers printed by the first printf call.

4.  10 30 30 (not 10 20 6, forgot to consider the update() function)

5. For each of the following, state whether the object itself resides on the stack, heap, or elsewhere:
a, p, pp, local, heap, and the struct pair returned by malloc. In particular, distinguish the
pointer variable heap from the object to which it points.

5.  a:     stack
    p:     stack
    pp:    stack
    local: stack
    heap:  stack
    *heap: heap

6. Explain why malloc(sizeof *heap) is preferable to writing a numeric allocation size. What do
sizeof(heap) and sizeof(*heap) measure?

6. easier to maintain as it's one less thing to go wrong. sizeof(heap) would measure the number 
of bytes that the heap value itself is, aka the address. sizeof(*heap) would measure the size of 
the object that is stored at the address of heap. 

Next, edit pointer.c as follows:
(a) Dynamically allocate an array of 100 struct pair objects without hard-coding the size of
struct pair.

(b) Initialize element i to contain x = i and y = 2i using pointer or array notation.

(c) Free the allocation correctly.

*/

struct pair {
    int x;
    int y;
};

static void update(int *p, struct pair *q)
{
    *p += 10;
    q->y = *p;
}

int main(void)
{
    int a[4] = {10, 20, 30, 40};
    int *p = a;
    int **pp = &p;

    struct pair local = {1, 2};
    struct pair *heap = malloc(sizeof *heap);
    if (heap == NULL)
        return 1;

    heap->x = 5;
    heap->y = 6;

    update(&a[1], heap);

    printf("%d %d %d\n", *p, *(*pp + 1), heap->y);
    printf("local = {%d, %d}\n", local.x, local.y);

    /* TODO (Part I): dynamically allocate an array of 100 struct pair
       objects, initialize element i to {i, 2*i}, and free it. */
    struct pair *arr = malloc(sizeof (struct pair) * 100);
    for (int i = 0; i<100; i++){
        arr[i].x = i;
        arr[i].y = 2*i;
    }
    free(heap);
    free(arr);
    return 0;
}
