#define NAME_LEN    30
#define PHONE_LEN   30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

typedef struct __namecard{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
}NameCard;

NameCard *MakeNameCard(char *name, char *phone){
    NameCard *card = malloc(sizeof(NameCard));
    strcpy(card->name, name);
    strcpy(card->phone, phone);
    return card;
}

void ShowNameCardInfo(NameCard *pcard){
    printf("이름 : %s\n", pcard->name);
    printf("전화번호부 %s\n", pcard->phone);
}

int NameCompare(NameCard *pcard, char *name){
    strcpy(pcard->name, name);
}

void ChangePhoneNum(NameCard *pcard, char *phone){
    strcpy(pcard->phone, phone);
}
