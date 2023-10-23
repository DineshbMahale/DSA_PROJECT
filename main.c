#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "utils.h"


//TrieNode* root = make_trienode('\0');
//KeyWord Arrays .....
char *FloraFaunakeywords[9] = {"flora","fauna","apple","mango","banana","mangrove","lion","tiger","rabbit"};
char *Songskeywords[5] = {"ed","taylor","selena","kishore","lata"};
char *Sportskeywords[7] = {"sports","football","volleyball","basketball","cricket","tennis","golf"};

void search(TrieNode *root,char *str1,int flag);
void autouSggestions(TrieNode *root,char* currPrefix);

// Main Driver program
int main ()
{
    TrieNode* root = make_trienode('\0');
    int choice = 0;
    int choice2 = 0;
    int choice3 = 0;
    char str1[1000];

    while(choice != 3)
    {
        printf("\n\nSelected Your Choice : \n");
        printf("\n 1.Generate data files"
               "\n 2.Search"
               "\n 3.Exit..");
        printf("\n Enter Your Selected Choice : ");
        scanf("%d", &choice);
        //printf("choice = %d",choice);

        switch(choice)
        {
        case 1:
            printf("Writing File Contents....");
            int file1,file2,file3;
            file1 = generateFloraFaunaFile();
            file2 = generateSongsFile();
            file3 = generateSportsFile();
            if(file1 == 1 && file2 == 1 && file3 == 1){
                printf("Contents written in Files successfully !\n");
            }
            else{
                printf("Some Error Occurred");
            }
            break;

        case 2:
            choice2 = 0;
            while(choice2 != 4)
            {
                printf("\n\nSelected Your Choice : \n");
                printf("\n 1.FloraAndFauna"
                       "\n 2.Songs"
                       "\n 3.Sports"
                       "\n 4.Back to Main Menu");
                printf("\n Enter Your Selected Choice : ");
                scanf("%d", &choice2);

                char ch[0];
                switch(choice2)
                {
                case 1:
                    //print
                    root = readFloraFaunaFile();
                    ch[0] = 'Y';
                    while(ch[0] != 'N' && ch[0] != 'n'){
                        printf("Enter a string to search for:");
                        fgets(str1, sizeof str1, stdin);
                        scanf("%[^\n]s",str1);
                        for(int i = 0; str1[i] != '\0'; i++)
                            str1[i] = tolower(str1[i]);
                        printf("\nYour string: %s",str1);
                        //printf("\nYour string: %s",str1);
                        search(root,str1,1);
                        printf("\n\n Do you want to continue searching in this domain? (Y/N) : \n");
                        //fflush(stdin);
                        scanf("%s", ch);
                    }
                    
                    free_trienode(root);
                    destroyHash();
                    break;

                case 2:
                    root = readSongsFile();
                    ch[0] = 'Y';
                    while(ch[0] != 'N' && ch[0] != 'n'){
                        printf("Enter a Singer to search for:");
                        fgets(str1, sizeof str1, stdin);
                        scanf("%[^\n]s",str1);
                        for(int i = 0; str1[i] != '\0'; i++)
                            str1[i] = tolower(str1[i]);
                        printf("\nYour string: %s",str1);
                        search(root,str1,2);
                        printf("\n\n Do you want to continue searching in this domain? (Y/N) : \n");
                        //fflush(stdin);
                        scanf("%s", ch);
                    }
                    free_trienode(root);
                    destroyHash();
                    break;

                case 3:
                    root = readSportsFile();
                    ch[0] = 'Y';
                    while(ch[0] != 'N' && ch[0] != 'n'){
                        printf("Enter any sports to search for:");
                        fgets(str1, sizeof str1, stdin);
                        scanf("%[^\n]s",str1);
                        for(int i = 0; str1[i] != '\0'; i++)
                            str1[i] = tolower(str1[i]);
                        printf("\nYour string: %s",str1);
                        search(root,str1,3);
                        printf("\n\n Do you want to continue searching in this domain? (Y/N) : \n");
                        //fflush(stdin);
                        scanf("%s", ch);
                    }
                    free_trienode(root);
                    destroyHash();
                    break;

                case 4:
                    printf("\n Back to Main Menu \n");
                    break;

                default:
                    printf("Select a valid choice!");
                    break;
                }
            }
            break;
        case 3:
            exit(1);
            break;

        default:
            printf("Select a valid choice!");
            break;
        }
    }
    return 0;
}

void search(TrieNode *root,char *str1,int flag)
{
    char newString[10][10];
    int i,j,ctr,len;
    int flag1 = 0;
    j=0;
    ctr=0;
    for(i=0; i<=(strlen(str1)); i++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(str1[i]==' '||str1[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=str1[i];
            j++;
        }
    }
    switch(flag){
    case 1:
        for(i=0; i < ctr; i++)
        {
            len = (sizeof(FloraFaunakeywords)/sizeof(FloraFaunakeywords[0]));
            for(int k=0; k<len; k++)
            {
                if(strcmp(FloraFaunakeywords[k],newString[i])==0)
                {
                    //printf("%s\n",newString[i]);
                    flag1 = 1;
                    print_search(root,newString[i]);
                }
            }
        }
        break;

    case 2:
        for(i=0; i < ctr; i++)
        {
            len = (sizeof(Songskeywords)/sizeof(Songskeywords[0]));
            for(int k=0; k<len; k++)
            {
                if(strcmp(Songskeywords[k],newString[i])==0)
                {
                    //printf("%s\n",newString[i]);
                    flag1 = 1;
                    print_search(root,newString[i]);
                }
            }
        }
        break;

    case 3:
        for(i=0; i < ctr; i++)
        {
            len = (sizeof(Sportskeywords)/sizeof(Sportskeywords[0]));
            for(int k=0; k<len; k++)
            {
                if(strcmp(Sportskeywords[k],newString[i])==0)
                {
                    //printf("%s\n",newString[i]);
                    flag1 = 1;
                    print_search(root,newString[i]);
                }
            }
        }
        break;

    }


    if(flag1 == 0){
        printf("\nSorry no such word found!! \nDid you mean:\n");
        for(i=0; i < ctr; i++)
            autouSggestions(root,newString[i]);
    }
    return;
}

void autouSggestions(TrieNode *root,char* currPrefix)
{
    TrieNode* temp = root;
    int position;

    for(int i=0; currPrefix[i]!='\0'; i++)
    {
        position = currPrefix[i] - 'a';
        //printf("position = %d",position);
        if (temp->children[position] == NULL){
                break;
        }

        temp = temp->children[position];
    }

    if (temp != NULL && temp->is_leaf == 1)
        printf("%s\n",currPrefix);

    for (int j = 0; j < MAX; j++){
        if (temp->children[j]) {
            char child = 'a' + j;
            autouSggestions(temp->children[j],(strncat(currPrefix, &child, 1)));
        }
    }
}





