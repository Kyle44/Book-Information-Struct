/*   
File: book_info_heap.c
Author: Kyle Fritz
Date Modified: 3/29/15
*/

#include<stdio.h>
#include <string.h>
#include"book_info_heap.h"

static book_info ARRAY[20];
static int OPEN_BLOCK = 0;

void init_heap(){
  int w = 0;
  while(w < 20){
  // size is 50
  strncpy(ARRAY[w].title, "\0", sizeof(ARRAY[w].title));
  // size is 40
  strncpy(ARRAY[w].author, "\0", sizeof(ARRAY[w].author));
  w++;
  }

  // copy of first open space, so I can add to the copy while keeping OPEN_BLOCK intact
  int copyBlock = OPEN_BLOCK;
  copyBlock++;
  int k = 0;
  while(k < 20){
      ARRAY[k].year_published = copyBlock;
      copyBlock++;
      k++;
  }
  
}

book_info *new_book_info(){
  // add to OPEN_BLOCK for next free space
  OPEN_BLOCK++;
	
  // if OPEN_BLOCK + 1 is available b/c you added before this, but are going to use OPEN_BLOCK - 1
  // Won't work for a year_published of 100 or greater
  if(OPEN_BLOCK != 21 && ARRAY[OPEN_BLOCK -1].year_published < 100){
    return &ARRAY[OPEN_BLOCK-1];
  }
  else{
    OPEN_BLOCK = 0;
    int r = 0;
    while(r < 20){
      if(ARRAY[r].year_published < 100){
	return &ARRAY[OPEN_BLOCK];;
      }
      else{
	r++;
	OPEN_BLOCK++;
      }
    }
  }
  return NULL;
}

// Deletes a book from the array
void del_book_info(book_info* book){
  // Couldn't figure out how to compare "\0" with title or author, so if year is < 100
  //  then error will occur
  if(book->year_published < 100){
    printf("This cannot be deleted, there is no information here.\n");
    exit(1);
  }
  strncpy(book->title, "\0", sizeof(book->title));
  strncpy(book->author, "\0", sizeof(book->author));
  // Make year_published < 20 for next loop
  book->year_published = 0;

  // copy of first open space, so I can add to the copy while keeping OPEN_BLOCK intact
  int copyBlock = OPEN_BLOCK;
  int k = 0;
  while(k < 20){
    if(ARRAY[k].year_published < 100){
      ARRAY[k].year_published = copyBlock;
      copyBlock++;
    }
    k++;
  }

}

void dump_heap(){
  printf("*** BEGIN HEAP DUMP ***\n");
  printf("head = %d\n", OPEN_BLOCK);
  int i = 0;
  while(i < 20){
    printf(" %d :  %d, %s, %s\n", i, ARRAY[i].year_published, ARRAY[i].title, ARRAY[i].author);
    i++;
  }
  printf("*** END HEAP DUMP ***\n");
}
