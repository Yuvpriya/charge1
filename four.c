#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
struct Node{
    char letter;
    bool wordComp;
    bool isRoot;
    struct Node* previous;
    struct Node* childNodes[27];
 }trie;
 struct Node* root;
 int sizeOfDic = 0;
bool check(const char* word)
{
    char currChar = ' ';
    currChar = word[0];
    struct trieNode* currNode = root;
    for(int i = 0; currChar != '\0'; i++)
    {
        currChar = word[i];
        if(currChar == '\0')
        {
            break;
        }
        else if(!isalpha(currChar)&&currChar != 39)
        {
            return false;
        }
        else if(currChar != 39)
        {
            currChar = tolower(currChar);
            if(currNode->childNodes[currChar - 'a'] != NULL)
            {
                currNode = currNode->childNodes[currChar - 'a'];
            }
            else
            {
                return false;
            }
        }
        else if(currChar == 39)
        {
            if(currNode->childNodes[26] != NULL)
            {
                currNode = currNode->childNodes[26];
            }
            else
            {
                return false;
            }
        }
    }
    if(currChar == '\0' && currNode->wordComp){
        return true;
    }else{
        return false;
    }
}

bool load(const char* dictionary)
{
    root = calloc(1,sizeof(struct trieNode));
    int cLettCount = 0;
    int tWordCount = 0;
     root->isRoot = true;
    struct trieNode* currNode = root;
    struct trieNode* prevNode;
    FILE* dic = fopen(dictionary, "r");
    char currChar = 1;
    while(currChar != EOF){

        cLettCount = 0;
        currNode = root;
        currChar = 1;
        for(int j = 0;  currChar != '\n'; j++){
            currChar = fgetc(dic);
            if(currChar == '\n'|| currChar == EOF)
            {
                break;
            }
            
   else if(!isalpha(currChar) && currChar != 39)
            {
                printf("Nonalpha char %c detected. Quiting...\n", currChar);
                return false;
            }
  
            else if(isalpha(currChar) || currChar== 39)
            {
                bool isNull = false;
                if(currChar == 39){
                    if(currNode->childNodes[26] == NULL)
                    {
                        isNull = true;
                        currNode->childNodes[26] = calloc (1,sizeof (trie));
                    }
                    prevNode = currNode;
                    currNode = currNode->childNodes[26];
                }
                else
                {
      
                    if(currNode->childNodes[currChar - 'a'] == NULL)
                    {
                        isNull = true;
                        currNode->childNodes[currChar - 'a'] = calloc (1,sizeof (trie));
                    }
                    prevNode = currNode;
                    currNode = currNode->childNodes[currChar - 'a'];
                }
                if(isNull)
                {
                     currNode->previous = prevNode;
                     currNode->isRoot = false;
                     currNode->letter = currChar;
                     currNode-> wordComp = false;
                }else if(!isNull){
                }
            }
        }
        if(currChar == EOF){
                break;
        }
        else if(currChar == '\n'){
            currNode -> wordComp = true;
            tWordCount++;
        }
    }
    fclose(dic);
    sizeOfDic = tWordCount;
    return true;
}
int size(void)
{
    return sizeOfDic;
}

int noloadHelper(struct trieNode* currNode)
{
    for(int i = 0; i < 27; i++)
    {
        if(currNode->childNodes[i] !=NULL)
        {
            uoloadHelper(currNode->childNodes[i]);
        }
    }
        free(currNode);
        return 0;
}

bool noload(void)
{
    noloadHelper(root);
    return true;
}
