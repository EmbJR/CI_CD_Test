#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define func(x,y)   (x,y)


struct Node
{
    uint8_t Value;
    uint8_t Data[10];
    struct Node* ptr;
};

typedef struct Node MainNode;

MainNode* MainDatabase;

void AddDatabase(uint8_t val, uint8_t *Data)
{
    MainNode* BackupNode = MainDatabase;

    MainNode* newNode = (MainNode*)malloc(sizeof(MainNode));
    newNode->Value = val;
    memcpy((char*)newNode->Data, (char *)Data, sizeof(MainDatabase->Data));//
    newNode->ptr = NULL;

    if(MainDatabase == NULL)
    {
        MainDatabase = newNode;
    }
    else
    {
        while(BackupNode->ptr != NULL)
        {
            BackupNode = BackupNode->ptr;
        }
        BackupNode->ptr = newNode;
    }
}



void printDatabase(struct Node* Obj)
{
    struct Node* DatabaseObj = Obj;
    while(DatabaseObj != NULL)
    {
        printf("\r\n------------------\r\n");
        printf("Value = %d  ", DatabaseObj->Value);
        printf("Data = %s\r\n", DatabaseObj->Data);
        DatabaseObj = DatabaseObj->ptr;
    }
}

void searchDatabases()
{

}


int main()
{
    AddDatabase(1, "Jaydeep");
    AddDatabase(2, "Gulab");
    AddDatabase(3, "Sauryaraj");
    AddDatabase(4, "Bhupatsinh");
    AddDatabase(5, "Shardaba");
    AddDatabase(6, "Pratiksha");

    printDatabase(MainDatabase);


}
