#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#define SIZE 10

//��ǥ����
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//���̺� ��ȣ
void num(int x, int y) {
	int i;
	for (i = 1; i<10; i++) {
		gotoxy(x + 2, y + 2);
		printf("%d�� �¼�", i);
		x += 25;
		if (i % 3 == 0)
			x = 0, y += 11;
	}gotoxy(3, 35);
}

//���ڸ�
void table2(int x, int y) {
	gotoxy(x, y);
	printf("�������������\n");
	gotoxy(x, y + 1);
	printf("��       ���ڸ�       ��\n");
	gotoxy(x, y + 2);
	printf("��                    ��\n");
	gotoxy(x, y + 3);
	printf("��                    ��\n");
	gotoxy(x, y + 4);
	printf("��                    ��\n");
	gotoxy(x, y + 5);
	printf("��                    ��\n");
	gotoxy(x, y + 6);
	printf("��                    ��\n");
	gotoxy(x, y + 7);
	printf("��                    ��\n");
	gotoxy(x, y + 8);
	printf("��                    ��\n");
	gotoxy(x, y + 9);
	printf("��                    ��\n");
	gotoxy(x, y + 10);
	printf("�������������\n");
}

//�����
void table1(int x, int y) {
	gotoxy(x, y);
	printf("�������������\n");
	gotoxy(x, y + 1);
	printf("��       �����       ��\n");
	gotoxy(x, y + 2);
	printf("��                    ��\n");
	gotoxy(x, y + 3);
	printf("��                    ��\n");
	gotoxy(x, y + 4);
	printf("��                    ��\n");
	gotoxy(x, y + 5);
	printf("��                    ��\n");
	gotoxy(x, y + 6);
	printf("��                    ��\n");
	gotoxy(x, y + 7);
	printf("��                    ��\n");
	gotoxy(x, y + 8);
	printf("��                    ��\n");
	gotoxy(x, y + 9);
	printf("��                    ��\n");
	gotoxy(x, y + 10);
	printf("�������������\n");
}

//���̺� 0�̸� ���ڸ�
void all(int table[10]) {
	int i, x = 0, y = 0;

	for (i = 1; i<10; i++) {
		if (table[i] <= 0) {
			table2(x, y);
		}
		else {
			table1(x, y);
		}
		x += 24;
		if (i % 3 == 0) {
			x = 0, y += 11;
		}
	}
}

//ȭ�鿡 �ݾ��� ��Ÿ���� �Լ�
void bill(int x, int y, int table[10]) {

	int i;
	for (i = 1; i<10; i++) {
		if (table[i]>0) {
			gotoxy(x, y);
			printf("�ݾ� : %d", table[i]);
		}
		x += 24;
		if (i % 3 == 0) {
			x = 3, y += 11;
		}
	}
}

//���
void bann() {
	system("cls");
	printf("----------------------------------------------------------------------------��\n");
	printf("|      ��    ��    ��    ��      �ڡڡڡ�        ��      ��     ��       ��  |\n");
	printf("|    �ڡڡ�  ��  �ڡڡ�  ��      ��              ��      ��     ��       ��  |\n");
	printf("|    �ڡڡ�  ��  �ڡڡ�  ��      �ڡڡڡ�        ��      ��     ��       ��  |\n");
	printf("|      ��    ��    ��    ��                      ��  �ڡڡ�     ��       ��  |\n");
	printf("|                        ��         ��           ��      ��    �� ��     ��  |\n");
	printf("|    �ڡڡڡ�    �ڡڡڡ�      �ڡڡڡڡڡ�    ��  ��    ��   ��   ��    ��  |\n");
	printf("|          ��          ��                    ��      ��  ��                  |\n");
	printf("|    �ڡڡڡ�    �ڡڡڡ�      �ڡڡڡڡڡ�              ��    �ڡڡڡڡ�    |\n");
	printf("|    ��          ��                      ��              ��            ��    |\n");
	printf("|    �ڡڡڡ�    �ڡڡڡ�                ��              ��    �ڡڡڡڡ�    |\n");
	printf("|                                        ��                    ��            |\n");
	printf("|                                                              �ڡڡڡڡ�    |\n");
	printf("|____________________________________________________________________________|\n");
	Sleep(2000);
}

//�޴� ����ü
struct Menu {
	int one;
	int two;
	int three;
	int four;
};

int main() {

	int sel, submit, table[10] = { 0 };
	struct Menu tblmenu[10] = { 0 }; //����ü
	int choice = 0, payment = 0, cash = 0, card = 0, won = 0, ordnb = 0;
	int price = 0, add = 0, plus = 0;
	int m1[10] = { 0 }, m2[10] = { 0 }, m3[10] = { 0 }, m4[10] = { 0 }; //����ü�� ���
	int i, x = 5, y = 3;

	bann();

	system("mode con cols=80 lines=70");

	system("cls"); //ȭ��Ŭ����

	all(table); //���̺����� ��Ÿ��
	num(0, 0); //���̺��ȣ�� ��Ÿ��

	while (1) {
		printf("\n\n 1. �Խ� \n 2. ��� \n 3. ��� \n 4. ���� \n 5. ���α׷� ���� \n\n ��� ���� : ");
		scanf_s("%d", &sel);

		//�Խ�
		if (sel == 1) {
			printf("\n\t�¼� ��ȣ�� �Է��ϼ��� : ");
			while (1) {
				scanf_s("%d", &choice);
				if (choice < 10) {
					printf("\n\t�ɼ��� �����ϼ���.\n");
					printf("\t\t============================================\n");
					printf("\t\t== 1. 1�ϱ�  5000��  2. 3�ϱ�  14000��    ==\n");
					printf("\t\t== 3. 7�ϱ� 30000��  4.30�ϱ� 140000��    ==\n");
					printf("\t\t== 0. �Ϸ�                                ==\n");
					printf("\t\t============================================\n\n");
					printf("\t\t�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
					printf("\t\t�ڡ�           ��  ��  ��                 ��\n");
					printf("\t\t�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
					break;
				}
				else {
					printf("\n�¼� ��ȣ�� �ٽ� �Է��ϼ���\n");
				}
			}

			while (1) {
				printf("\t\t");
				scanf_s("%d", &submit);
				switch (submit) {
				case 1:
					printf("\t\t1�� 5000��\n");
					printf("\t\t���� : ");
					scanf_s("%d", &ordnb);
					price += 5000 * ordnb;
					m1[choice] += ordnb;
					break;
				case 2:
					printf("\t\t3�� 14000��\n");
					printf("\t\t���� : ");
					scanf_s("%d", &ordnb);
					price += 14000 * ordnb;
					m2[choice] += ordnb;
					break;
				case 3:
					printf("\t\t7�� 30000��\n");
					printf("\t\t���� : ");
					scanf_s("%d", &ordnb);
					price += 30000 * ordnb;
					m3[choice] += ordnb;
					break;
				case 4:
					printf("\t\t30�� 140000��\n");
					printf("\t\t���� : ");
					scanf_s("%d", &ordnb);
					price += 140000 * ordnb;
					m4[choice] += ordnb;
					break;
				case 0:
					printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
					printf("\t\t�հ� : %d \n\n", price);
					printf("\t\t��� �Ϸ�\n\n");
					printf("============================================================\n");
					printf("�ƹ�Ű�� �����ø� ����ȭ������ �Ѿ�ϴ�");
					_getch();
				default:
					printf("�ٽ� �����ϼ���\n");
					break;
				}

				if (submit == 0)
					break;
			}
			table[choice] += price;
			price = 0;
		}

		//���
		else if (sel == 2) {
			printf("\t�¼� ��ȣ�� �Է��ϼ��� : ");
			scanf_s("%d", &choice);
			printf("\n���� �ݾ� : %d", table[choice]);
			printf("\t���� ������ �����ϼ��� (1. ���� 2.ī��) : ");
			scanf_s("%d", &payment);

			if (payment == 1) {
				printf("\n\t���� �ݾ� : ");
				scanf_s("%d", &won);
				if (won < 0) {
					printf("\t�ٽ� �Է����ּ���.");
				}
				else if (won - table[choice] >= 0) {
					printf("\n\a\t�Ž��� �� : %d \n\n", won - table[choice]);
					printf("\t\t\t\t�����Ϸ�!!!\n");
				}
				else if (won - table[choice] < 0) {
					add = table[choice] - won;
					while (1) {
						printf("\t\t%d���� �����ž��մϴ�\n", add);
						printf("\t�߰��� ���� �ݾ� : ");
						scanf_s("%d", &plus);
						add -= plus;
						if (add <= 0) {
							break;
						}
					}
					printf("\n\a\t�Ž��� �� : %d \n", -add);
					printf("\t\t\t\t�����Ϸ�!!!\n");
				}

				cash += table[choice];
			}

			else if (payment == 2) {
				printf("\a�����Ϸ�");
				card += table[choice];
			}
			printf("\n�ƹ�Ű�� �����ø� ����ȭ������ �Ѿ�ϴ�");

			m1[choice] = 0;
			m2[choice] = 0;
			m3[choice] = 0;
			m4[choice] = 0;

			tblmenu[choice].one = m1[choice];
			tblmenu[choice].two = m2[choice];
			tblmenu[choice].three = m3[choice];
			tblmenu[choice].four = m4[choice];

			table[choice] = 0;
			_getch();
		}

		//���
		else if (sel == 3) {
			{
				printf("\n���̺� ��ȣ�� �Է��ϼ��� : ");
				scanf_s("%d", &choice);
				printf("\n\t�ɼ��� �����ϼ���.\n");
				printf("\t\t============================================\n");
				printf("\t\t== 1. 1�ϱ�  5000��  2. 3�ϱ�  14000��    ==\n");
				printf("\t\t== 3. 7�ϱ� 30000��  4.30�ϱ� 140000��    ==\n");
				printf("\t\t== 0. �Ϸ�                                ==\n");
				printf("\t\t============================================\n\n");
				printf("\t\t�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
				printf("\t\t�ڡ�           ��  ��  ��                 ��\n");
				printf("\t\t�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");

				while (1) {
					printf("\t\t");
					scanf_s("%d", &submit);
					switch (submit) {
					case 1:
						printf("\t\t1�� 5000��\n");
						printf("\t\t���� : ");
						printf("\t\t");
						scanf_s("%d", &ordnb);
						if (m1[choice] < ordnb)
						{
							printf("\t��� ������ ��� ������ �Ѿ����ϴ�.\n");
						}
						else
						{
							price += 5000 * ordnb;
							m1[choice] -= ordnb;
						}break;
					case 2:
						printf("\t\t3�� 14000��\n");
						printf("\t\t���� : ");
						printf("\t\t");
						scanf_s("%d", &ordnb);
						if (m2[choice] < ordnb) {
							printf("\t��� ������ ��� ������ �Ѿ����ϴ�.\n");
						}
						else {
							price += 14000 * ordnb;
							m2[choice] -= ordnb;
						}
						break;
					case 3:
						printf("\t\t7�� 30000��\n");
						printf("\t\t���� : ");
						printf("\t\t");
						scanf_s("%d", &ordnb);
						if (m3[choice] < ordnb)
						{
							printf("\t��� ������ ��� ������ �Ѿ����ϴ�.\n");
						}
						else {
							price += 30000 * ordnb;
							m3[choice] -= ordnb;
						}break;
					case 4:
						printf("\t\t30�� 140000��\n");
						printf("\t\t���� : ");
						printf("\t\t");
						scanf_s("%d", &ordnb);
						if (m4[choice] < ordnb)
						{
							printf("\t��� ������ ��� ������ �Ѿ����ϴ�.\n");
						}
						else {
							price += 140000 * ordnb;
							m4[choice] -= ordnb;
						}break;
					case 0:
						printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
						printf("  �հ� : - %d \n\n", price);
						printf("\a  ��� �Ϸ�\n\n");
						printf("============================================================\n");
						printf("�ƹ�Ű�� �����ø� ����ȭ������ �Ѿ�ϴ�");
						_getch();
					default:
						printf("�ٽ� �����ϼ���\n");
						break;
					}

					if (submit == 0)
						break;
				}
				table[choice] += price;
				price = 0;
			}
		}
		else if (sel == 4) {
			printf("�� ����� : %d", cash + card);
			printf("ī�� ����� : %d", card);
			printf("���� ����� : %d \n", cash);
			printf("�ƹ�Ű�� �����ø� ����ȭ������ �Ѿ�ϴ�");
			_getch();
		}
		else if (sel == 5) {
			break;
		}
		system("cls");
		all(table);
		bill(3, 8, table);
		num(0, 0);
		tblmenu[choice].one = m1[choice];
		tblmenu[choice].two = m2[choice];
		tblmenu[choice].three = m3[choice];
		tblmenu[choice].four = m4[choice];

		for (i = 1; i<10; i++) {
			if (tblmenu[i].one > 0) {
				gotoxy(x, y);
				printf("1�ϱ� %i", tblmenu[i].one);
			}
			x += 24;
			if (i % 3 == 0) {
				x = 5, y += 11;
			}
		}
		x = 5, y = 3;

		for (i = 1; i<10; i++) {
			if (tblmenu[i].two > 0) {
				gotoxy(x, y + 1);
				printf("3�ϱ� %i", tblmenu[i].two);
			}
			x += 24;
			if (i % 3 == 0) {
				x = 5, y += 11;
			}
		}
		x = 5, y = 3;
		for (i = 1; i<10; i++) {
			if (tblmenu[i].three > 0) {
				gotoxy(x, y + 2);
				printf("7�ϱ� %i", tblmenu[i].three);
			}
			x += 24;
			if (i % 3 == 0) {
				x = 5, y += 11;
			}
		}
		x = 5, y = 3;

		for (i = 1; i<10; i++) {
			if (tblmenu[i].four > 0) {
				gotoxy(x, y + 3);
				printf("30�ϱ� %i", tblmenu[i].four);
			}
			x += 24;
			if (i % 3 == 0) {
				x = 5, y += 11;
			}
		}
		x = 5, y = 3;
		gotoxy(3, 36);
	}
}
