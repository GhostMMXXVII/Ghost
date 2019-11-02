#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
	char name[50];
	int studentNo;
	int age;
	char gender[2];
};
typedef struct student studentRec;

/**
studentRec sortRec (studentRec *classRec, int n) {
	studentRec maleStudents[10] = {0}, femaleStudents[10] = {0}, temp[1];
	int i, j;

	for(i = 0; i < n; i++){
		if(strcmp(*(classRec[i]).gender, "M") == 0) {
			strcpy(maleStudents[i].name, *(classRec[i]).name);
			maleStudents[i].studentNo = *(classRec[i]).studentNo;
			maleStudents[i].age = *(classRec[i]).age;
			strcpy(maleStudents[i].gender, *(classRec[i]).gender);
		}
		else if(strcmp(*(classRec[i]).gender, "F") == 0) {
			strcpy(femaleStudents[i].name, *(classRec[i]).name);
			femaleStudents[i].studentNo = *(classRec[i]).studentNo;
			femaleStudents[i].age = *(classRec[i]).age;
			strcpy(femaleStudents[i].gender, *(classRec[i]).gender);
		}
	}

	for(i = 0; i < n; i++) {
		if(strcmp(maleStudents[i].name, maleStudents[i + 1].name) > 0){
			temp[0] = maleStudents[i];
			maleStudents[i] = maleStudents[i + 1];
			maleStudents[i + 1] = temp[0];
		}
		if(strcmp(femaleStudents[i].name, femaleStudents[i + 1].name) > 0){
			temp[0] = femaleStudents[i];
			femaleStudents[i] = femaleStudents[i + 1];
			femaleStudents[i + 1] = temp[0];
		}
	}

	for(i = 0; i < n; i++) {
		printf("%s %d %d %s\n", maleStudents[i].name, maleStudents[i].studentNo, maleStudents[i].age, maleStudents[i].gender);
	}


}
**/

int main(int argc, char **argv){

	int N, i;
	studentRec class[N];

	/**
	if(argc != 2){
		printf("Warning: Command should have two arguments.\n"
				"Terminating program now\n
		exit(1);
	}
	*/

	FILE *inFilePtr = fopen("students.txt", "rt");
	FILE *outFilePtr = fopen(argv[1], "wt");

	fscanf(inFilePtr, "%d", &N);


	//for(i = 0; i < N; i++) {
		fscanf(inFilePtr, "%s %d %d %s", class[0].name, &class[0].studentNo, &class[0].age, class[0].gender);
	//}
	printf(" %s %d %d %s\n", class[0].name, class[0].studentNo, class[0].age, class[0].gender);
	//sortRec(&class[0], N);

	return 0;
}