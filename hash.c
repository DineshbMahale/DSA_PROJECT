#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"

int hashCode(int key) {
   return key % SIZE;
}

struct DataItem searchH(int key) {
   int hashIndex = hashCode(key);
   //printf("\nhash Index =  %d",hashIndex);

   //move in array until empty
   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key){

        //printf("str = %d",hashArray[hashIndex]->key);
        struct DataItem data = *(hashArray[hashIndex]);
        //printf("str = %s",data.title);
        //printf("\n uyg hash Index = %d",hashIndex);
        return data;
      }

      ++hashIndex;

      hashIndex %= SIZE;
      
   }

}

void insertdata(person input) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->key = input.key;

   if(input.title == NULL){
        printf(" NULL");
   }

   strcpy(item->title,input.title);

   int len = strlen(input.str) +1;
   //char str[len];
   //for(int i=0;i<5;i++){
    //strcpy(srt,*(input.str));
   //}
   //strcpy(str,(input.str));
   //printf(" ff");
   //printf("str =  %s  ",str);
   item->str = (char *)malloc(len);
   strcpy((item->str),(input.str));
   for(int i=0;i<5;i++){
     strcpy(item->info[i],input.info[i]);
   }
   //printf("item->str =  %s  ",item->str);

   int hashIndex = hashCode(input.key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //next cell
      ++hashIndex;

      hashIndex %= SIZE;
   }

   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   //dummyItem->data = NULL;
   dummyItem->key = -1;

   int key = item->key;

   //get the hash
   int hashIndex = hashCode(key);

   //move in array until empty
   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex];


         hashArray[hashIndex] = dummyItem;
         return temp;
      }

      ++hashIndex;

      hashIndex %= SIZE;
   }

   return NULL;
}

void displayHash() {
   int i = 0;

   for(i = 0; i<SIZE; i++) {

      if(hashArray[i] != NULL)
         printf(" (%d,%s)",hashArray[i]->key,hashArray[i]->title);
      else
         printf(" -- ");
   }

   printf("\n");
}

void destroyHash(){
	int i = 0;

	   for(i = 0; i<SIZE; i++) {

	      if(hashArray[i] != NULL)
		 delete(hashArray[i]);
	      //else
		 //printf("");
	   }

	   printf("Hash Destryed\n");
   
}




