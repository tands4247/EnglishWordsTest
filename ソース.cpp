//�p�P��e�X�g
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct tango {
	char english[20];
	char japan[30];
	int no;		//�����ƂȂ鐔�����i�[
};


bool hantei(int ans, int a);
FILE* fp1(void);
FILE* fp2(void);
FILE* fp3(void);


int main() {
	int true_n = 0;			//���𐔂�ێ�
	int false_n = 0;		//�s���𐔂�ێ�
	int false_list[20] = { 0 };	//�s�����̃��X�g��z��ŕێ�
	int tango_c;
	int ans;
	char str[25];
	FILE* (* pm[4])(void);	//�֐��|�C���^�̔z��̐錾

	//�֐��|�C���^�����ꂼ��̊֐����w���悤�ɂ���
	pm[0] = fp1;
	pm[1] = fp2;
	pm[2] = fp3;
	pm[3] = fp3;


	srand((unsigned int)time(NULL));	//��������ɗ����̌��𐶐�


	tango all_a[100];	//�t�@�C�����̑S�Ă̒P����i�[
	tango a[100];		//�t�@�C�����̑S�Ă̒P�� all_a ����ꕔ�̒P����i�[
		

	printf("1�`4�̒��Ŏg�p����P��Z�b�g�́H�i1�`4����́j");
	int num;
	scanf_s("%d", &num);
	FILE* fp = (pm[num - 1])();		//�֐��|�C���^�ŌĂяo���֐����w��A�߂�l�̃t�@�C���|�C���^���AFILE*�^��fp�ɓn��


	int all_a_c = 0;
	while (fscanf(fp, "%s%s", all_a[all_a_c].english, all_a[all_a_c].japan) != EOF) {
		all_a_c++;		//�S�Ă̒P�ꐔ���J�E���g�BEOF�܂őS�Ă̒P����t�@�C���������
	}
	fclose(fp);


	printf("�P��ꗗ��\�����܂����H�iyes�c1  no�c0�j");
	scanf_s("%d", &num);
	if (num == 1) {
		for (int i = 0; i < all_a_c; i++) {
			printf("%-30s%s", all_a[i].english, all_a[i].japan);
			printf("\n");
		}
	}
	else
		printf("�\�����܂���\n");


	printf("�����L�[�������Ă�������\n");
	scanf("%s", str);	//�����L�[�����͂��ꂽ��R���\�[���N���A
	system("cls");		//�R���\�[���N���A

	printf("%d�̉p�P�ꂪ����܂��B\n����e�X�g���܂����H�F", all_a_c);
	scanf("%d", &tango_c);



	//�S�Ă̒P�ꂪ�i�[����Ă���all_a�������_���Ńe�X�g��tango_c��a[]�ɃR�s�[�B�Ȍ�Aa[]�����ƂɃe�X�g���Ă���
	for (int i = 0; i < tango_c; i++) {
		a[i] = all_a[rand() % (all_a_c + 1)];		//all_a�z��̓Y�����͗���(0�`�S�Ă̒P�ꐔall_a_c)
	}

	for (int i = 0; i < tango_c; i++) {
		a[i].no = 1 + rand() % 4;		//no�����o�ɂ͐����ƂȂ鐔��1�`4�̂����ꂩ���i�[����
	}


	
	//�_�~�[�����
	char dummy[100][30];
	fp = fopen("dummy.txt", "r");
	int dummy_c = 0;
	while (fscanf(fp, "%s", dummy[dummy_c]) != EOF) {
		dummy_c++;
	}
	fclose(fp);



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

			printf("%d��.  %s\n", k + 1, a[k].english);

			//�I�����̕\��
			for (int j = 1; j < 5; j++) {
				if (j == a[k].no) {
					printf("  (%d) %s\t", j, a[k].japan);
				}
				else
					printf("  (%d) %s\t", j, dummy[rand() % dummy_c]);

			}
			printf("\n\n");

			printf("�����𔼊p�����œ��͂��ĉ������F");
			scanf_s("%d", &ans);
			if (hantei(ans, a[k].no)) {
				printf("�����I\n\n\n\n");
				true_n++;		//����
			}
			else {
				printf("�u�b�u�[\n");
				printf("%-20s%s\n\n\n", a[k].english, a[k].japan);
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
				printf("%-20s\t%s\n", a[false_list[h]].english, a[false_list[h]].japan);	//�z��̓Y����������q�ɂȂ��Ă��邱�Ƃɒ���
			}
			

			printf("�K���ȃL�[����͂��Ă�������");
			scanf("%s", str);	//�����L�[�����͂��ꂽ��R���\�[���N���A
			system("cls");		//�R���\�[���N���A


			printf("\n�S�␳������܂ŏI���܂���\n\n\n\n\n\n");
			printf("��%d���E���h\n\n", ++raound);
		}

	}
	
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
�p�P��e�X�g
�p�P���\�����A�P�`�S�̊Y��������{���I�����ăe�X�g���s��
�p��Ɠ�{��󂪂��ƂȂ�悤�\���̔z��𗘗p����
�p�P��Ɠ��{���̃Z�b�g�͂������̃t�@�C���̒������I�сA�ǂݍ���
1�`4�̑I�����̂�����͐����Ƃ��A����ȊO��3�̓_�~�[�f�[�^�Ƃ��ĕs�����ɂ���
�_�~�[�f�[�^��dummy.txt����ǂݍ���
�t�@�C����ҏW���邱�ƂŃI���W�i���̉p�P��e�X�g������
*/


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