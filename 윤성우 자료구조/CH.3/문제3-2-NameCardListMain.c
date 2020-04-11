#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(){
    List list;
    NameCard *pcard;
    ListInit(&list);
    
    pcard = MakeNameCard("STEVE", "010-1234-5678");
    LInsert(&list, pcard);
    
    pcard = MakeNameCard("DAVID", "010-3456-7890");
    LInsert(&list, pcard);
    
    pcard = MakeNameCard("SUSAN", "010-2345-6789");
    LInsert(&list, pcard);
    
    if(LFirst(&list, &pcard)){
        if(!NameCompare(pcard, "STEVE")){
            ShowNameCardInfo(pcard);
        }
        else{
            while(LNext(&list, &pcard)){
                if(!NameCompare(pcard, "STEVE")){
                    ShowNameCardInfo(pcard)
                    break;
                }
            }
        }
    }
    // 남은 두 명도 위와 같음
    
    
    // 모든 사람의 정보 출력하기
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    
    if(LFirst(&list, &pcard)){
        ShowNameCardInfo(pcard);
        
        while(LNext(&list, &pcard))
            ShowNameCardInfo(pcard);
    }
    return 0;
}
