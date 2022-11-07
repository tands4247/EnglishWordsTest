/*
�p�P��e�X�g
�p�P���\�����A�P�`�S�̊Y��������{���I�����ăe�X�g���s���B
������1�`4�̗����𗘗p���A�����ȊO�̑I�����̓_�~�[�i�s�����j�Ƃ���B������_�~�[�t�@�C�����烉���_���őI�o����B
�p�P��Ɠ��{���̃Z�b�g�͂������̃t�@�C���̒������I�сA�ǂݍ��ށB
���̃v���O�����ł͂��������v���O�����̒��g�i���Ƀt�@�C�����j�������ς��Ȃ��čςނ悤�A
�֐��|�C���^�̔z��𗘗p���Ď��s���ɃE�B���h�E���ł̔ԍ��w��Ńt�@�C���I�����s����悤�ɂ����B
�p��Ɠ�{��󂪂��ƂȂ�悤�\���̔z��𗘗p����
�t�@�C����ҏW���邱�ƂŃI���W�i���̉p�P��e�X�g������
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//tango�^�\���̐錾
typedef struct tango {
	char english[20];	//�p�P����i�[
	char japan[30];		//�΂ƂȂ���{�����i�[
	int no;		//�����ƂȂ鐔�����i�[
};

//�֐��錾
int TangoCount(FILE* fp);
bool hantei(int ans, int a);
FILE* fp1(void);
FILE* fp2(void);
FILE* fp3(void);
FILE* decided_fp(void);

//�ϐ��i�O���[�o���Ŏg�p�j
char str[25];
tango all_a[100];	//�t�@�C�����̑S�Ă̒P����i�[


int main() {
	int true_n = 0;			//���𐔂�ێ�
	int false_n = 0;		//�s���𐔂�ێ�
	int false_list[20] = { 0 };	//�s�����̃��X�g��z��ŕێ�
	int tango_c;			//�P�ꐔ���i�[
	int ans;				//�L�[�{�[�h���͂ɂ��P�`4�̓������i�[
	
	
	srand((unsigned int)time(NULL));	//��������ɗ����̌��𐶐�

	

	FILE* fp = decided_fp();	//�w�肵���t�@�C���|�C���^��Ԃ�


	
	int all_a_c = TangoCount(fp);		//�t�@�C�����̒P�ꐔ��Ԃ�
	printf("%d�̉p�P�ꂪ����܂��B\n����e�X�g���܂����H�F", all_a_c);
	scanf("%d", &tango_c);


	tango* pa = (tango*)malloc(sizeof(tango) * tango_c);		//���I�������m��
	//�S�Ă̒P�ꂪ�i�[����Ă���all_a�������_���œ��͂����e�X�g��tango_c��a[]�ɃR�s�[�B�Ȍ�Apa[]�����ƂɃe�X�g���Ă���
	for (int i = 0; i < tango_c; i++) {
		pa[i] = all_a[rand() % (all_a_c + 1)];		//all_a�z��̓Y�����͗���(�e�X�g��������萔�������_���őI�o)
	}

	for (int i = 0; i < tango_c; i++) {
		pa[i].no = 1 + rand() % 4;		//no�����o�ɂ͐����ƂȂ鐔��1�`4�̂����ꂩ���i�[����
	}


	
	//�_�~�[�����
	char dummy[100][30];
	FILE* fp_d = fopen("dummy.txt", "r");
	int dummy_c = 0;
	while (fscanf(fp_d, "%s", dummy[dummy_c]) != EOF) {
		dummy_c++;
	}
	fclose(fp_d);



	printf("�K���ȃL�[����͂��Ă�������");
	scanf("%s", str);	//�����L�[�����͂��ꂽ��R���\�[���N���A
	system("cls");		//�R���\�[���N���A

	printf("�P��e�X�g���n�߂܂�\n�������Ǝv�������𔼊p�œ��͂��Ă�������\n\n");

	int raound = 1;
	int i = 0;
	while (true_n != tango_c) {
		true_n = 0;
		false_n = 0;
		for (int k = 0; k < tango_c; k++) {

			printf("%d��.  %s\n", k + 1, pa[k].english);

			//�I�����̕\��
			for (int j = 1; j < 5; j++) {
				if (j == pa[k].no) {
					printf("  (%d) %s\t", j, pa[k].japan);
				}
				else
					printf("  (%d) %s\t", j, dummy[rand() % dummy_c]);

			}
			printf("\n\n");

			printf("�����𔼊p�����œ��͂��ĉ������F");
			scanf_s("%d", &ans);
			if (hantei(ans, pa[k].no)) {
				printf("�����I\n\n\n\n");
				true_n++;		//����
			}
			else {
				printf("�u�b�u�[\n");
				printf("%-20s%s\n\n\n", pa[k].english, pa[k].japan);
				false_n++;		//�s����
				false_list[i++] = k;		//�s�������X�g
			}
			
		}
		printf("���𐔁F%d\t�s���𐔁F%d\n", true_n, false_n);
		


		if (true_n == tango_c)
			printf("�S�␳���ł�\n");
		else {
			printf("\n\n�ԈႦ�����Ɖ𓚂�\�����܂�\n");
			for (int h = 0; h < false_n; h++) {
				printf("%-20s\t%s\n", pa[false_list[h]].english, pa[false_list[h]].japan);	//�z��̓Y����������q�ɂȂ��Ă��邱�Ƃɒ���
			}
			

			printf("�K���ȃL�[����͂��Ă�������");
			scanf("%s", str);	//�����L�[�����͂��ꂽ��R���\�[���N���A
			system("cls");		//�R���\�[���N���A


			printf("\n�S�␳������܂ŏI���܂���\n\n\n\n\n\n");
			printf("��%d���E���h\n\n", ++raound);
		}

	}
}


//�����̃t�@�C���̒�����ǂݍ��݂����t�@�C���̃t�@�C���|�C���^��Ԃ��֐�
FILE* decided_fp(void) {
	FILE* (*pm[4])(void);	//�֐��|�C���^�̔z��̐錾

	//�֐��|�C���^�����ꂼ��̊֐����w���悤�ɂ���
	pm[0] = fp1;
	pm[1] = fp2;
	pm[2] = fp3;
	pm[3] = fp3;

	printf("1�`4�̒��Ŏg�p����P��Z�b�g�́H�i1�`4����́j");
	int num;
	scanf_s("%d", &num);
	FILE* decided_fp = (pm[num - 1])();		//�֐��|�C���^�ŌĂяo���֐����w��A�߂�l�̃t�@�C���|�C���^���AFILE*�^��fp�ɓn��

	return decided_fp;
}


int TangoCount(FILE* fp) {
	int all_a_c = 0;	//�S�Ă̒P��̐����L��


	while (fscanf(fp, "%s%s", all_a[all_a_c].english, all_a[all_a_c].japan) != EOF) {
		all_a_c++;		//�S�Ă̒P�ꐔ���J�E���g�BEOF�܂őS�Ă̒P����t�@�C���������
	}
	fclose(fp);

	int num;
	printf("�P��ꗗ��\�����܂����H�iyes�c1  no�c0�j");
	scanf_s("%d", &num);
	if (num == 1) {
		for (int i = 0; i < all_a_c; i++) {
			printf("%-30s%-30s", all_a[i].english, all_a[i].japan);
			printf("\n");
		}
	}
	else
		printf("�\�����܂���\n");


	printf("�����L�[�������Ă�������\n");
	scanf("%s", str);	//�����L�[�����͂��ꂽ��R���\�[���N���A
	system("cls");		//�R���\�[���N���A

	return all_a_c;
}


//�^�܂��͋U��Ԃ�bool�^�̊֐�
bool hantei(int ans, int a) {
	return (ans == a);	//��������������ΐ^���A�������Ȃ���΋U��Ԃ�
}


FILE* fp1(void) {
	FILE* fp = fopen("tango.txt", "r");
	if (fp == NULL)
		printf("�t�@�C�����J���܂���\n");

	return fp;
}


FILE* fp2(void) {
	FILE* fp = fopen("toeic800.txt", "r");
	if (fp == NULL)
		printf("�t�@�C�����J���܂���\n");

	return fp;
}


FILE* fp3(void) {
	FILE* fp = fopen("tango3.txt", "r");
	if (fp == NULL)
		printf("�t�@�C�����J���܂���\n");

	return fp;
}


FILE* fp4(void) {
	FILE* fp = fopen("tango3.txt", "r");
	if (fp == NULL)
		printf("�t�@�C�����J���܂���\n");

	return fp;
}






/*
�p��Ƃ��̓��{��󂪑΂ƂȂ����t�@�C���𕡐��p�ӂ���B
���ꂼ��̃t�@�C����ǂݍ��݁A�ǂݍ��񂾃t�@�C�����t�@�C���|�C���^�Ƃ��ĕԂ��֐����t�@�C�������p�ӂ���B
FILE* fp1(void);
FILE* fp2(void);�Ȃ�

���ꂼ��̊֐��̃A�h���X���i�[����֐��|�C���^��z��ŗp�ӂ���B
FILE* (*pm[])(void); 
�֐��|�C���^ pm[n] = �֐� fp
�ŁA�֐��|�C���^�̔z��Ŋ֐����Ăяo����悤�ɂ���B����ɂ��v�f�����w�肷�邾���ŏꍇ�ɉ������֐����ȒP�ɌĂяo����B
*/









//0�N���A
/*
#include<stdio.h>

typedef struct tango {
	char english[20];
	char japan[30];
	int no;		//�����ƂȂ鐔�����i�[
	int his;
};

tango all_a[100];

int main() {
	FILE* fp = fopen("tango.txt", "r");
	int all_a_c = 0;	//�S�Ă̒P��̐����L��



	while (fscanf(fp, "%s %s", all_a[all_a_c].english, all_a[all_a_c].japan) != EOF) {
		all_a_c++;
		all_a[all_a_c].no = NULL;	//NUll�̒l��0
		all_a[all_a_c].his = 0;

	}
	fclose(fp);

	FILE* fp2 = fopen("tango.txt", "w");
	for (int i = 0; i <= all_a_c; i++) {
		//all_a[i].no = NULL;
		//all_a[i].his = 0;

		fprintf(fp2, "%s %s %d %d\n", all_a[i].english, all_a[i].japan, all_a[i].no, all_a[i].his);

	}
	fclose(fp);
}
*/