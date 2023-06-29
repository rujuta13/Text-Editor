#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<stdbool.h>
#define sizetrie 26
#define MAX_WORD_LENGTH 20
#define MAX_WORDS 10000


typedef struct TrieNode{
    char data[1000];
    int index;
    bool isTerminal;
    struct TrieNode ** children;
}TrieNode;

TrieNode* init();
void insert_helper(TrieNode *root, char *key, int i);
void insert(TrieNode *t, char *key);
void display_compress_trie(TrieNode *t,char *buffer, int depth);
TrieNode* compress_trie(TrieNode *root);
void auto_complete_2nd_step_compressed_version(TrieNode *t,char *buffer, int depth, char array_of_strings[][MAX_WORD_LENGTH], int *ind);
void auto_complete(TrieNode *root,char *key);
TrieNode* auto_complete_iteration_1st_step_compressed_version(TrieNode *root,char *key, char *buffer, int *depth);
void auto_complete_compressed_version(TrieNode *root,char *key, char array_of_strings[][MAX_WORD_LENGTH], int *ind);
void display_trie(TrieNode* root, char* buffer, int depth) ;
int count_nodes(TrieNode *t);
void initializeArray(char arr[][MAX_WORD_LENGTH], int rows);
