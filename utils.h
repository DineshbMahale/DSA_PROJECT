#ifndef TEST_H__
#define TEST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26
#define MAX2 100
#define NUMBER_OF_STRING 5
#define MAX_STRING_SIZE 100

typedef struct person
{
    int key;
    char title[MAX2];
    char *str;
    char info[NUMBER_OF_STRING][MAX_STRING_SIZE];
}person;


struct TrieNode {
    char data;
    struct TrieNode* children[MAX];
    int is_leaf;
    int key;
};

typedef struct TrieNode TrieNode;


TrieNode* make_trienode(char data);
void free_trienode(TrieNode* node);
TrieNode* delete_trie(TrieNode* root, char* word);
TrieNode* insert_Trie(TrieNode* root, person);

void print_trie(TrieNode* root);
void print_search(TrieNode* root, char* word);

TrieNode* readSongsFile();
TrieNode* readSportsFile();
TrieNode* readFloraFaunaFile();

#endif /* TEST_H__*/

