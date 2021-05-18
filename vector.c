#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//i have written comments near bugs ,because it was easier to give refrence rather than writing in a new txt file. kindly check it

typedef struct
{
  int *data;    
  int length;   
  int capacity; 
} vector;

vector *vector_new()
{
  vector v;
  v.data = NULL;   //it is a pointer means a memory location it can't be null//here we should create a heap using malloc()
  v.length = 0;   //correction...v.data=(int*)mallock(sizeof(int));
  v.capacity = 0; //initially capacity can't be zero because it will have ability to store atleast one element because we are giving the address of first element through v.data
  return &v;     //here we are returning a location of stack memory which will cause dangeling pointer
  //so we should use malloc fuction to create heap in this
}

void vector_push(vector *v, int n)
{
  if (v->length == v->capacity)
  {
    int new_capacity = v->capacity * 2;  //first of all initializtion of v.capacity=0 will cause new_capacity to be equal to zero which would be no use to us and if we change capacity
 //then also we are allocating excess of memory by multiplication instead we should just add one.
//after several vector_push capacity will be greater than v.length then further vector push can't be use because at starting condition is applied v.capacity==v.length
 //correction...int new capacity=v.capacity+1;
    
    int *new_data = (int *)malloc(new_capacity);  //we should  use (int*)malloc(sizeof(new_capacity));
    assert(new_data != NULL)

    for (int i = 0; i < v->length; ++i)
    {
      new_data[i] = v->data[i];   
    }

    v->data = new_data;
    v->capacity = new_capacity;
  }

  v->data[v->length] = n;
  ++v->length;
}

void vector_free(vector *v)
{
  free(v);
  free(v->data); 
}

void main()   //it may show error main must return int value
{
  vector *v = vector_new();
  vector_push(v, 107);

  int *n = &v->data[0]; 
  vector_push(v, 110);
  printf("%d\n", *n);

  free(v->data); //since  free(v.data) is included in function vector_free() therefore twice occurrence of free(v.data) may cause runtime error
  vector_free(v);//we should remove one free(v.data)
}
