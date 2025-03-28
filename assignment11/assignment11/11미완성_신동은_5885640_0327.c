#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�л� ������ ������ ����ü �̸� ����
#define NAME_LENGTH 20

//�л� ���� ����ü
typedef struct StdInfo {
	char name[NAME_LENGTH];
	int id;
	int score;
	struct StdInfo* next;
}Student;

int main() {
    //�л���, ���� ����Ʈ, �۾���, ���� ���� ��� ����
	int stdn;
	Student* head = NULL;
	Student* current = NULL;
	Student* new_std;

	printf("����� �л� ������ �Է��Ͻó���? ");
	scanf_s("%d", &stdn);
    //���� ���� ����
	getchar();
	
    //�л� ���� �Է� ����
	for (int i = 0; i < stdn; i++) {
        //��� �Ҵ�
		new_std = (Student*)malloc(sizeof(Student));
		if (new_std == NULL)
		{
			perror("�޸� �Ҵ� ����");
			return 1;
		}
		new_std->next = NULL;

		printf("[%d] �л��� ������ �Է��ϼ��� (�̸� �й� ����): ", i+1);
		scanf_s("%s %d %d", new_std->name, (rsize_t)sizeof(new_std->name), & new_std->id, &new_std->score);
		getchar();

        //��� �߰�
		if (head == NULL) {
			head = new_std;
			current = new_std;
		}
        else {
            current->next = new_std;
            current = new_std;
        }
    }

    // �й� �˻�
    int _id;
    while (1) {
        printf("�й��� �Է��ϼ��� (0�̸� ����)? ");
        scanf_s("%d", &_id);
        getchar();

        if (_id == 0) {
            break;
        }

        current = head;
        int found = 0;

        //���� ����Ʈ �ݺ��Ͽ� �й� �˻�
        while (current != NULL) {
            if (current->id == _id) {
                printf("%s %d %d\n", current->name, current->id, current->score);
                //�˻� ����
                found = 1;
                break;
            }
            //���� ���� �̵�
            current = current->next;
        }

        //�˻� ���н� �޼��� ���
        if (!found) {
            printf("�ش� �й��� �л��� �����ϴ�.\n");
        }
    }

    // ���� �Ҵ� �޸� ����
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