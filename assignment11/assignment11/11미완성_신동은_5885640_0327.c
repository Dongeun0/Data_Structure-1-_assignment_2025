#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//학생 정보를 저장할 구조체 이름 길이
#define NAME_LENGTH 20

//학생 정보 구조체
typedef struct StdInfo {
	char name[NAME_LENGTH];
	int id;
	int score;
	struct StdInfo* next;
}Student;

int main() {
    //학생수, 연결 리스트, 작업중, 새로 생성 노드 선언
	int stdn;
	Student* head = NULL;
	Student* current = NULL;
	Student* new_std;

	printf("몇명의 학생 정보를 입력하시나요? ");
	scanf_s("%d", &stdn);
    //개행 문자 제거
	getchar();
	
    //학생 정보 입력 루프
	for (int i = 0; i < stdn; i++) {
        //노드 할당
		new_std = (Student*)malloc(sizeof(Student));
		if (new_std == NULL)
		{
			perror("메모리 할당 오류");
			return 1;
		}
		new_std->next = NULL;

		printf("[%d] 학생의 정보를 입력하세요 (이름 학번 점수): ", i+1);
		scanf_s("%s %d %d", new_std->name, (rsize_t)sizeof(new_std->name), & new_std->id, &new_std->score);
		getchar();

        //노드 추가
		if (head == NULL) {
			head = new_std;
			current = new_std;
		}
        else {
            current->next = new_std;
            current = new_std;
        }
    }

    // 학번 검색
    int _id;
    while (1) {
        printf("학번을 입력하세요 (0이면 종료)? ");
        scanf_s("%d", &_id);
        getchar();

        if (_id == 0) {
            break;
        }

        current = head;
        int found = 0;

        //연결 리스트 반복하여 학번 검색
        while (current != NULL) {
            if (current->id == _id) {
                printf("%s %d %d\n", current->name, current->id, current->score);
                //검색 성공
                found = 1;
                break;
            }
            //다음 노드로 이동
            current = current->next;
        }

        //검색 실패시 메세지 출력
        if (!found) {
            printf("해당 학번의 학생이 없습니다.\n");
        }
    }

    // 동적 할당 메모리 해제
    current = head;
    Student* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;

    return 0;
}