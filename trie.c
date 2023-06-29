#include "trie.h"
TrieNode* init(){
    TrieNode *t = (TrieNode*)malloc(sizeof(TrieNode));
     t->index = 0;
    t->data[t->index] = '\0';
    t->isTerminal = false;
    t->children = (TrieNode**)malloc((sizeof(TrieNode*))*sizetrie);
    for (int i = 0; i < sizetrie; i++)
    {
        t->children[i] = NULL;
        /* code */
    }
    return t;
}

void insert_helper(TrieNode *root, char *key, int i){
    if (i == strlen(key)){
        root->isTerminal = true;
        return;
    }

    int ind = key[i] - 'a';
    TrieNode* child;
    if (root->children[ind]!=NULL){
        child = root->children[ind];
    }

    else{
        child = init();
        child->data[child->index] = key[i];
        child->index++;
        child->data[child->index] = '\0';
        root->children[ind] = child;
    }

    insert_helper(child,key,i+1);
    return;
}

void insert(TrieNode *t, char *key){
    insert_helper(t,key,0);
    return;

}

void display_compress_trie(TrieNode *t,char *buffer, int depth){
    if (!t){
        return;
    }

    TrieNode *child;
    for (int i = 0; i < sizetrie; i++)
    {     
        if (t->children[i]){
            child = t->children[i];
            int j = 0;
            while (j<child->index)
            {        
                buffer[depth++] = child->data[j];
                j++;
            }


            if(child->isTerminal){
                buffer[depth] = '\0';
                printf("%s\n",buffer);
            }

            display_compress_trie(child,buffer,depth);
             for (int i = 0; i < child->index; i++)
                {
                    depth--;
                }
            
        }
    }
    
    return;
}



TrieNode* compress_trie(TrieNode *root){
    if (!root) return root;
    TrieNode*child = NULL;
    for (int i = 0; i < sizetrie; i++)
    {
        if (root->children[i]){
            child = root->children[i];
            child =  compress_trie(child);
            root->children[i] = child;
            if (root->data[0] == '\0'){
                return root;
            }
        }
    }

    int childCount = 0;
    for (int i = 0; i < sizetrie; i++)
    {
        if (root->children[i]){
            childCount++;
            child = root->children[i];
            if (childCount>1) return root;
        }
    }

    if (childCount == 1){
        for (int i = 0; i < child->index; i++)
        {
            root->data[root->index++] = child->data[i];
        }

        root->data[root->index] = '\0';
        root->isTerminal  = child->isTerminal;
        for (int i = 0; i < sizetrie; i++)
        {
            root->children[i] = child->children[i];
        }
        free(child);        
    }
    return root ;
}


void auto_complete_2nd_step_compressed_version(TrieNode *t,char *buffer, int depth, char store[][MAX_WORD_LENGTH], int *ind){
    if (!t){
        return;
    }
    

    if (t->isTerminal){
        buffer[depth] = '\0'; 
        strcpy(store[*(ind)],buffer);
        (*(ind))++;
    }

    TrieNode *child;
    for (int i = 0; i < sizetrie; i++)
    {
        if (t->children[i]){
            child = t->children[i];
            int j = 0;
            while (j<child->index)
            {
                buffer[depth++] = child->data[j];
                j++;
            }

            auto_complete_2nd_step_compressed_version(child,buffer,depth,store,ind);
             for (int i = 0; i < child->index; i++)
             {
                    depth--;
             }    
        }
    }
    return;
}

TrieNode* auto_complete_iteration_1st_step_compressed_version(TrieNode *root,char *key, char *buffer, int *depth){
     if (!root) return root;
    int j = 0;
    while(j<strlen(key)){
        int ind = key[j] - 'a';
        if (root->children[ind]){
            root = root->children[ind];
            int m = 0;
            while(m<root->index){
                buffer[(*depth)++] = root->data[m++];
            }
        }
        j++;
    }
    buffer[(*depth)] = '\0';
    return root;
}


void auto_complete_compressed_version(TrieNode *root,char *key, char store[][MAX_WORD_LENGTH], int *ind){

    // updates the root as well as buffer, after this function is executed 
    // key contains just 1 char and root is updated

    char buffer[MAX_WORD_LENGTH];
    int depth = 0;
    TrieNode*first = auto_complete_iteration_1st_step_compressed_version(root,key,buffer,&depth);

    if ((!first) || first->data[0] == '\0') {
		return;
    }

    auto_complete_2nd_step_compressed_version(first,buffer,depth,store,ind);
    return;
}

void display_trie(TrieNode* root, char* buffer, int depth) {

    if (root->isTerminal) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }
    
    for (int i = 0; i < sizetrie; i++) {
        if (root->children[i] != NULL) {
            buffer[depth] = 'a' + i;
            display_trie(root->children[i], buffer, depth + 1);
        }
    }
}

int count_nodes(TrieNode *t){

    if (!t) return 0;
    int ct = 0;
    for (int i = 0; i < sizetrie; i++)
    {
        if (t->children[i]) ct+=count_nodes(t->children[i]);
        /* code */
    }
    return 1+ct;  
}

void initializeArray(char arr[][MAX_WORD_LENGTH], int rows) {
    int i;
    for (i = 0; i < rows; i++) {
        strcpy(arr[i], ""); // Initialize each string with an empty string
    }
}
