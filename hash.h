#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

#define SIZE 100
#define NUMBER_OF_STRING 5
#define MAX_STRING_SIZE 100

struct DataItem {
    int key;
    char title[MAX2];
    char *str;
    char info[NUMBER_OF_STRING][MAX_STRING_SIZE];
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;


int hashCode(int key);
struct DataItem searchH(int key);
void insertdata(person input);
struct DataItem* delete(struct DataItem* item);
void displayHash();
void destroyHash();
