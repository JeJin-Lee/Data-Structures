#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
}Node;

int main(){
    Node *head = NULL;      
    Node *tail = NULL;      
    Node *cur = NULL;
    
    Node *newNode = NULL;
    int readData;
    
    while(1){
        printf("자연수 입력: ");                
        scanf("%d", &readData);
        if(readData<1)
            break;
        
        newNode (Node*)malloc(sizeof(Node));        // 노드의 생성            
        newNode->data = readData;                   // 노드에 데이터 저장
        newNode->next = NULL;                       // 노드의 next를 NULL로 초기화
        
        if(head==NULL)                              // 첫 번째 노드라면
            head = newNode;                         // 첫 번째 노드를 head가 가리키게 함
        else                                        // 두 번째 이후 노드라면
            tail->next = newNode;                   
            
        tail = newNode;                             // 노드의 끝을 tail이 가리키게 함
    }
    printf("\n");
    
    //입력 받은 데이터의 출력 과정//
    printf("입력 받은 데이터의 전체 출력! \n");
    if(head==NULL)
        printf("저장된 자연수가 존재하지 않습니다. \n");
    else{
        cur = head;                             // cur이 리스트의 첫 번째 노드를 가리킨다
        printf("%d ", cur->data);               // 첫 번째 데이터 출력
        
        while(cur->next != NULL){               // 연결된 노드가 존재한다면
            cur = cur->next;                    // cur이 다음 노드를 가리키게 함
            printf("%d ", cur->data);           // cur이 가리키는 노드를 출력한다
        }
    }
    printf("\n\n");
    
    //메모리의 해제 과정//
    if(head==NULL)
        return 0;                               // 삭제할 노드가 존재하지 않는다
    else{
        Node *delNode = head;
        Node *delNextNode = head->next;
        
        printf("%d을 삭제합니다. \n", head->data);
        free(delNode);                          // 첫 번째 노드 삭제
        
        while(delNextNode != NULL){             // 두 번째 이후 노드 삭제를 위한 반복문
            delNode = delNextNode;
            delNextNode = delNextNode->next;
            
            printf("%d을 삭제합니다. \n", delNode->data);
            free(delNode);
        }
    }
    return 0;
}
