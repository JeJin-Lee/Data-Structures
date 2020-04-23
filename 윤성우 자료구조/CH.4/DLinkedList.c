#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0 

typedef int LData;

typedef struct _node{
    LData data;
    struct _node *next;
}Node;

typedef struct _LinkedList{
    Node *head;
    Node *cur;
    Node *before;
    int numOfData;
    int (*comp)(Ldata d1, Ldata d2);
}LinkedList;

typedef LinkedList List;

void ListInit(List *plist){         // 초기화 하는 함수
    plist->head = (Node*)malloc(sizeof(Node));      //더미노드의 생성!
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data){
    if(plist->comp == NULL)         // 정렬기준이 마련되지 않았다면
        FInsert(plist, data);       // 머리에 노드를 추가
    else                            // 정렬기준이 마련되었다면
        SInsert(plist, data);       // 정렬기준에 의거하여 노드를 추가
}                                   // 노드의 추가는 comp에 무엇이 저장되어 있느냐에 따라 진행이 된다

void FInsert(List *plist, LData data){
    Node newNode = (Node*)malloc(sizeof(Node));     // 새 노드 생성
    newNode->data = data;                           // 새 노드에 데이터 저장
    
    newNode->next = plist->head->next;              // 새 노드가 다른 노드를 가리키게 함
    plist->head->next = newNode;                    // 더미 노드가 새 노드를 가리키게 함
    
    (plist->numOfData)++;                           // 저장한 노드의 수를 하나 증가시킴
}

void SInsert(List *plist, LData data){
    Node *newNode = (Node*)malloc(sizeof(Node));        // 새로운 노드 생성
    Node *pred = plist->head;                           // pred는 더미노드를 가리킴
    newNode->data = data;
    
    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
        pred = pred->next;
    
    newNode->next = pred->next;
    pred->next = newNode;
    
    (plist->numOfData)++;
}


// 데이터 조회
int LFirst(List *plist, LData *pdata){
    if(plist->head->next == NULL)               // 더미노드가 NULL을 가리킨다면
        return FALSE;
    plist->before = plist->head;                // before은 더미노드를 가리키게 함
    plist->cur = plist->head->next;             // cur은 첫 번째 노드를 가리키게 함
    
    *pdata = plist->cur->data;                  // 첫 번째 노드의 데이터를 반환
    return TRUE;    
}

int LNext(List *plist, LData *pdata){
    if(plist->cur->next == NULL)
        return FALSE;
    plist->before = plist->cur;             // cur이 가리키던 것을 before가 가리킴
    plist->cur = plist->cur->next;          // cur은 그 다음 노드를 가리킴
    
    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist){
    Node *rpos = plist->cur;
    LData rdata = rpos->data;
    
    plist->before->next = plist->cur->next;     // 소멸 대상을 리스트에서 제거
    plist->cur = plist->before;                 // cur이 가리키는 위치를 재조정
    
    free(rpos);                                 // 리스트에서 제거된 노드의 소멸  
    (plist->numOfData)--;                       // 저장된 데이터의 수 하나 감소
    return rdata;                               // 제거된 노드의 데이터 반환
}
//before의 위치를 하나 당길 필요는 없다. 어차피 Lnext함수에서 before의 위치를 새로 지정하기 떄문

// 연결리스트에서의 정렬기준 설정과 관련된 부분

/* SetSortRule 함수가 호출되면서 정렬의 기준이 리스트의 멤버 comp에 등록되면
SInsert 함수 내에서는 comp에 등록된 정렬의 기준을 근거로 데이터를 정렬하여 저장한다 */

void SetSortRule(List *plist, int(*comp)(LData d1, Ldata d2)){      //리스트의 멤버 comp를 초기화하는 함수 
    plist->comp = comp;
}
