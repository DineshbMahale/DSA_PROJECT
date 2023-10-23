#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "hash.h"

TrieNode* make_trienode(char data) {
    TrieNode* node = (TrieNode*) calloc (1, sizeof(TrieNode));
    for (int i=0; i<MAX; i++)
        node->children[i] = NULL;
    node->is_leaf = 0;
    node->data = data;
    int key = -1;
    return node;
}

void free_trienode(TrieNode* node) {
    for(int i=0; i<MAX; i++) {
        if (node->children[i] != NULL) {
            
            free_trienode(node->children[i]);
        }
        else {
            continue;
        }
    }
    free(node);
}

TrieNode* insert_Trie(TrieNode* root, person input){

  
    TrieNode* temp = root;
    
    for (int i=0; input.title[i] != '\0'; i++) {
        if(input.title[i] == ' ')
            continue;
        int idx = (int) input.title[i] - 'a';
        
        //printf("idx = %d",idx);
        if (temp->children[idx] == NULL) {

            TrieNode* newNode = make_trienode(input.title[i]);
            temp->children[idx] = newNode;

        }
        else {
            // Word exists
            //printf("Word Exists");
        }

        temp = temp->children[idx];
    }
    temp->is_leaf = 1;
    //printf(" da %s",input.title);
    insertdata(input);
    //printf(" da %s",input.title);
    temp->key = input.key;
    return root;
}

int search_trie(TrieNode* root, char* word){
    TrieNode* temp = root;

    for(int i=0; word[i]!='\0'; i++)
    {
        int position = word[i] - 'a';
        //printf("position = %d",position);
        if (temp->children[position] == NULL)
            return 0;
        temp = temp->children[position];
    }
    if (temp != NULL && temp->is_leaf == 1)
        return temp->key;
    return 0;
}


void print_trie(TrieNode* root) {
    if (!root)
        return;
    TrieNode* temp = root;
    printf("%c -> ", temp->data);
    for (int i=0; i<MAX; i++) {
        print_trie(temp->children[i]);
    }
}

void print_search(TrieNode* root, char* word) {
    //printf("Searching for %s: ", word);
    int sr =search_trie(root, word);
    if (sr == 0)
        printf("Not Found\n");
    else{
        printf("\n");
        //printf("Found\n");
        struct DataItem data = searchH(sr);
        //printf(" gh %d",data.key);
        //printf("\n\tTitle : %s",data.title);
        printf("\n%s",data.str);
        printf("\nAdditional Info:");
        int i =0;
        while(strcmp(data.info[i],"\0\0")!=0 && i<5){
            printf("\n%s",data.info[i]);
            i++;
        }
    }
    return;
}



TrieNode* readSongsFile(){
    TrieNode* root = make_trienode('\0');
    int length,i=0;
    FILE *infile;
    struct person input;

    // Open person.dat for reading
    
    infile = fopen ("person.dat", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    fseek(infile, 0L, SEEK_END);
    length = ftell(infile);
    //printf("len = %d",length);
    //fseek(infile, 0L, SEEK_SET);
    rewind(infile);

 
    // read file contents till file end
    while(fread(&input, sizeof(struct person), 1, infile)){
                root = insert_Trie(root,input);
                
    }
    // close file
    
    fclose(infile);
    return root;

}

TrieNode* readFloraFaunaFile(){
    TrieNode* root = make_trienode('\0');
    int length,i=0;
    FILE *infile;
    struct person input;

    // Open florafauna.dat for reading
    infile = fopen ("florafauna.dat", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    fseek(infile, 0L, SEEK_END);
    length = ftell(infile);
    //printf("len = %d",length);
    //fseek(infile, 0L, SEEK_SET);
    rewind(infile);

    // read file contents till file end
    while(fread(&input, sizeof(struct person), 1, infile)){
    	    
            root = insert_Trie(root,input);
            
            
    }
    // close file
    fclose (infile);
    return root;

}

TrieNode* readSportsFile(){
    TrieNode* root = make_trienode('\0');
    int length,i=0;
    FILE *infile;
    struct person input;

    // Open sports.dat for reading
    infile = fopen ("sports.dat", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    fseek(infile, 0L, SEEK_END);
    length = ftell(infile);
    rewind(infile);

    // read file contents till file end
    while(fread(&input, sizeof(struct person), 1, infile)){

            root = insert_Trie(root,input);
    }
    // close file
    fclose (infile);
    return root;

}

/*int check_divergence(TrieNode* root, char* word) {
    TrieNode* temp = root;
    int len = strlen(word);
    if (len == 0)
        return 0;

    int last_index = 0;
    for (int i=0; i < len; i++) {
        //printf("HEREfgt");
        int position = word[i] - 'a';
        if (temp->children[position]) {
            for (int j=0; j<MAX; j++) {
                if (j != position && temp->children[j]) {
                    last_index = i + 1;
                    break;
                }
            }
            temp = temp->children[position];
        }
    }
    //printf("last_index = %d",last_index);
    return last_index;
}

char* find_longest_prefix(TrieNode* root, char* word) {
    if (!word || word[0] == '\0')
        return NULL;
    int len = strlen(word);

    char* longest_prefix = (char*) calloc (len + 1, sizeof(char));
    for (int i=0; word[i] != '\0'; i++)
        longest_prefix[i] = word[i];
    longest_prefix[len] = '\0';
    int branch_idx  = check_divergence(root, longest_prefix) - 1;
    if (branch_idx >= 0) {
        longest_prefix[branch_idx] = '\0';
        longest_prefix = (char*) realloc (longest_prefix, (branch_idx + 1) * sizeof(char));
    }

    return longest_prefix;
}

int is_leaf_node(TrieNode* root, char* word) {
    TrieNode* temp = root;
    for (int i=0; word[i]; i++) {
        int position = (int) word[i] - 'a';
        //printf("HEREfgt");
        if (temp->children[position]) {
            temp = temp->children[position];
        }
    }
    return temp->is_leaf;
}

TrieNode* delete_trie(TrieNode* root, char* word) {
    if (!root)
        return NULL;
    if (!word || word[0] == '\0')
        return root;

    if (!is_leaf_node(root, word)) {
        return root;
    }
    TrieNode* temp = root;
    char* longest_prefix = find_longest_prefix(root, word);

    if (longest_prefix[0] == '\0') {
        //printf("HEREdelete");
        free(longest_prefix);
        return root;
    }

    int i;
    for (i=0; longest_prefix[i] != '\0'; i++) {
        //printf("HEREdelete");
        //printf("  %d  ",i);
        int position = (int) longest_prefix[i] - 'a';
        if (temp->children[position] != NULL) {

            temp = temp->children[position];
        }
        else {

            free(longest_prefix);
            return root;
        }
    }
    int len = strlen(word);
    for (; i < len; i++) {
        int position = (int) word[i] - 'a';
        if (temp->children[position]) {
            TrieNode* rm_node = temp->children[position];
            temp->children[position] = NULL;
            free_trienode(rm_node);
        }
    }
    free(longest_prefix);
    return root;
}*/


