#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//필요하면 header file 추가 가능

//
// argv[1]: 레코드 파일명
//

#define ID_LENGTH 20
#define NAME_LENGTH 80
#define STUDENT_RECORD_SIZE (ID_LENGTH + NAME_LENGTH)

int main(int argc, char **argv)
{
	// 표준입력으로 받은 레코드 파일에 저장되어 있는 전체 레코드를 "순차적"으로 읽어들이고, 이때
	// 걸리는 시간을 측정하는 코드 구현함
	struct student {
		char id[ID_LENGTH];
		char name[NAME_LENGTH];
	} student;
	off_t fileSize;
	int numOfStudents;
	int fd;
	int i;

	if(argc != 2) {
		fprintf(stderr, "usage : %s <file>\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) < 0) {
		fprintf(stderr, "open error for %s\n", argv[1]);
		exit(1);
	}

	if((fileSize = lseek(fd, 0, SEEK_SET)) < 0) { // lseek 사용하면 파일 끝까지 메모리에 올라오지 않는지? -> stat 구조체 이용하여 파일 사이즈 구해보기
		fprintf(stderr, "lseek error\n");
		exit(1);
	}

	lseek(fd, 0, SEEK_SET);
	numOfStudents = (int)(fileSize / STUDENT_RECORD_SIZE);
	for(i = 0; i < numOfStuendts; ++i) {
		if (read(fd, &student, STUDENT_RECORD_SIZE) <= 0)
			break;
#ifdef DEBUG
		printf("id : %s, name : %s\n", student.id, student.name);
#endif
	}

	printf("#records: %d timecost: us\n" numOfStudents);

	exit(0);
}