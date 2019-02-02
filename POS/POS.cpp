#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#define SIZE 10

//좌표설정
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//테이블 번호
void num(int x, int y) {
	int i;
	for (i = 1; i<10; i++) {
		gotoxy(x + 2, y + 2);
		printf("%d번 좌석", i);
		x += 25;
		if (i % 3 == 0)
			x = 0, y += 11;
	}gotoxy(3, 35);
}

//빈자리
void table2(int x, int y) {
	gotoxy(x, y);
	printf("□□□□□□□□□□□□\n");
	gotoxy(x, y + 1);
	printf("□       빈자리       □\n");
	gotoxy(x, y + 2);
	printf("□                    □\n");
	gotoxy(x, y + 3);
	printf("□                    □\n");
	gotoxy(x, y + 4);
	printf("□                    □\n");
	gotoxy(x, y + 5);
	printf("□                    □\n");
	gotoxy(x, y + 6);
	printf("□                    □\n");
	gotoxy(x, y + 7);
	printf("□                    □\n");
	gotoxy(x, y + 8);
	printf("□                    □\n");
	gotoxy(x, y + 9);
	printf("□                    □\n");
	gotoxy(x, y + 10);
	printf("□□□□□□□□□□□□\n");
}

//사용중
void table1(int x, int y) {
	gotoxy(x, y);
	printf("■■■■■■■■■■■■\n");
	gotoxy(x, y + 1);
	printf("■       사용중       ■\n");
	gotoxy(x, y + 2);
	printf("■                    ■\n");
	gotoxy(x, y + 3);
	printf("■                    ■\n");
	gotoxy(x, y + 4);
	printf("■                    ■\n");
	gotoxy(x, y + 5);
	printf("■                    ■\n");
	gotoxy(x, y + 6);
	printf("■                    ■\n");
	gotoxy(x, y + 7);
	printf("■                    ■\n");
	gotoxy(x, y + 8);
	printf("■                    ■\n");
	gotoxy(x, y + 9);
	printf("■                    ■\n");
	gotoxy(x, y + 10);
	printf("■■■■■■■■■■■■\n");
}

//테이블값 0이면 빈자리
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

//화면에 금액을 나타내는 함수
void bill(int x, int y, int table[10]) {

	int i;
	for (i = 1; i<10; i++) {
		if (table[i]>0) {
			gotoxy(x, y);
			printf("금액 : %d", table[i]);
		}
		x += 24;
		if (i % 3 == 0) {
			x = 3, y += 11;
		}
	}
}

//배너
void bann() {
	system("cls");
	printf("----------------------------------------------------------------------------ㄱ\n");
	printf("|      ★    ★    ★    ★      ★★★★        ★      ★     ★       ★  |\n");
	printf("|    ★★★  ★  ★★★  ★      ★              ★      ★     ★       ★  |\n");
	printf("|    ★★★  ★  ★★★  ★      ★★★★        ★      ★     ★       ★  |\n");
	printf("|      ★    ★    ★    ★                      ★  ★★★     ★       ★  |\n");
	printf("|                        ★         ★           ★      ★    ★ ★     ★  |\n");
	printf("|    ★★★★    ★★★★      ★★★★★★    ★  ★    ★   ★   ★    ★  |\n");
	printf("|          ★          ★                    ★      ★  ★                  |\n");
	printf("|    ★★★★    ★★★★      ★★★★★★              ★    ★★★★★    |\n");
	printf("|    ★          ★                      ★              ★            ★    |\n");
	printf("|    ★★★★    ★★★★                ★              ★    ★★★★★    |\n");
	printf("|                                        ★                    ★            |\n");
	printf("|                                                              ★★★★★    |\n");
	printf("|____________________________________________________________________________|\n");
	Sleep(2000);
}

//메뉴 구조체
struct Menu {
	int one;
	int two;
	int three;
	int four;
};

int main() {

	int sel, submit, table[10] = { 0 };
	struct Menu tblmenu[10] = { 0 }; //구조체
	int choice = 0, payment = 0, cash = 0, card = 0, won = 0, ordnb = 0;
	int price = 0, add = 0, plus = 0;
	int m1[10] = { 0 }, m2[10] = { 0 }, m3[10] = { 0 }, m4[10] = { 0 }; //구조체에 사용
	int i, x = 5, y = 3;

	bann();

	system("mode con cols=80 lines=70");

	system("cls"); //화면클리어

	all(table); //테이블구조가 나타남
	num(0, 0); //테이블번호가 나타남

	while (1) {
		printf("\n\n 1. 입실 \n 2. 퇴실 \n 3. 취소 \n 4. 정산 \n 5. 프로그램 종료 \n\n 기능 선택 : ");
		scanf_s("%d", &sel);

		//입실
		if (sel == 1) {
			printf("\n\t좌석 번호를 입력하세요 : ");
			while (1) {
				scanf_s("%d", &choice);
				if (choice < 10) {
					printf("\n\t옵션을 선택하세요.\n");
					printf("\t\t============================================\n");
					printf("\t\t== 1. 1일권  5000원  2. 3일권  14000원    ==\n");
					printf("\t\t== 3. 7일권 30000원  4.30일권 140000원    ==\n");
					printf("\t\t== 0. 완료                                ==\n");
					printf("\t\t============================================\n\n");
					printf("\t\t★★★★★★★★★★★★★★★★★★★★★★\n");
					printf("\t\t★★           등  록  증                 ★\n");
					printf("\t\t★★★★★★★★★★★★★★★★★★★★★★\n");
					break;
				}
				else {
					printf("\n좌석 번호를 다시 입력하세요\n");
				}
			}

			while (1) {
				printf("\t\t");
				scanf_s("%d", &submit);
				switch (submit) {
				case 1:
					printf("\t\t1일 5000원\n");
					printf("\t\t수량 : ");
					scanf_s("%d", &ordnb);
					price += 5000 * ordnb;
					m1[choice] += ordnb;
					break;
				case 2:
					printf("\t\t3일 14000원\n");
					printf("\t\t수량 : ");
					scanf_s("%d", &ordnb);
					price += 14000 * ordnb;
					m2[choice] += ordnb;
					break;
				case 3:
					printf("\t\t7일 30000원\n");
					printf("\t\t수량 : ");
					scanf_s("%d", &ordnb);
					price += 30000 * ordnb;
					m3[choice] += ordnb;
					break;
				case 4:
					printf("\t\t30일 140000원\n");
					printf("\t\t수량 : ");
					scanf_s("%d", &ordnb);
					price += 140000 * ordnb;
					m4[choice] += ordnb;
					break;
				case 0:
					printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
					printf("\t\t합계 : %d \n\n", price);
					printf("\t\t등록 완료\n\n");
					printf("============================================================\n");
					printf("아무키나 누르시면 메인화면으로 넘어갑니다");
					_getch();
				default:
					printf("다시 선택하세요\n");
					break;
				}

				if (submit == 0)
					break;
			}
			table[choice] += price;
			price = 0;
		}

		//퇴실
		else if (sel == 2) {
			printf("\t좌석 번호를 입력하세요 : ");
			scanf_s("%d", &choice);
			printf("\n결제 금액 : %d", table[choice]);
			printf("\t결제 수단을 선택하세요 (1. 현금 2.카드) : ");
			scanf_s("%d", &payment);

			if (payment == 1) {
				printf("\n\t받은 금액 : ");
				scanf_s("%d", &won);
				if (won < 0) {
					printf("\t다시 입력해주세요.");
				}
				else if (won - table[choice] >= 0) {
					printf("\n\a\t거스름 돈 : %d \n\n", won - table[choice]);
					printf("\t\t\t\t결제완료!!!\n");
				}
				else if (won - table[choice] < 0) {
					add = table[choice] - won;
					while (1) {
						printf("\t\t%d원을 더내셔야합니다\n", add);
						printf("\t추가로 받은 금액 : ");
						scanf_s("%d", &plus);
						add -= plus;
						if (add <= 0) {
							break;
						}
					}
					printf("\n\a\t거스름 돈 : %d \n", -add);
					printf("\t\t\t\t결제완료!!!\n");
				}

				cash += table[choice];
			}

			else if (payment == 2) {
				printf("\a결제완료");
				card += table[choice];
			}
			printf("\n아무키나 누르시면 메인화면으로 넘어갑니다");

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

		//취소
		else if (sel == 3) {
			{
				printf("\n테이블 번호를 입력하세요 : ");
				scanf_s("%d", &choice);
				printf("\n\t옵션을 선택하세요.\n");
				printf("\t\t============================================\n");
				printf("\t\t== 1. 1일권  5000원  2. 3일권  14000원    ==\n");
				printf("\t\t== 3. 7일권 30000원  4.30일권 140000원    ==\n");
				printf("\t\t== 0. 완료                                ==\n");
				printf("\t\t============================================\n\n");
				printf("\t\t★★★★★★★★★★★★★★★★★★★★★★\n");
				printf("\t\t★★           등  록  증                 ★\n");
				printf("\t\t★★★★★★★★★★★★★★★★★★★★★★\n");

				while (1) {
					printf("\t\t");
					scanf_s("%d", &submit);
					switch (submit) {
					case 1:
						printf("\t\t1일 5000원\n");
						printf("\t\t수량 : ");
						printf("\t\t");
						scanf_s("%d", &ordnb);
						if (m1[choice] < ordnb)
						{
							printf("\t취소 수량이 등록 수량을 넘었습니다.\n");
						}
						else
						{
							price += 5000 * ordnb;
							m1[choice] -= ordnb;
						}break;
					case 2:
						printf("\t\t3일 14000원\n");
						printf("\t\t수량 : ");
						printf("\t\t");
						scanf_s("%d", &ordnb);
						if (m2[choice] < ordnb) {
							printf("\t취소 수량이 등록 수량을 넘었습니다.\n");
						}
						else {
							price += 14000 * ordnb;
							m2[choice] -= ordnb;
						}
						break;
					case 3:
						printf("\t\t7일 30000원\n");
						printf("\t\t수량 : ");
						printf("\t\t");
						scanf_s("%d", &ordnb);
						if (m3[choice] < ordnb)
						{
							printf("\t취소 수량이 등록 수량을 넘었습니다.\n");
						}
						else {
							price += 30000 * ordnb;
							m3[choice] -= ordnb;
						}break;
					case 4:
						printf("\t\t30일 140000원\n");
						printf("\t\t수량 : ");
						printf("\t\t");
						scanf_s("%d", &ordnb);
						if (m4[choice] < ordnb)
						{
							printf("\t취소 수량이 등록 수량을 넘었습니다.\n");
						}
						else {
							price += 140000 * ordnb;
							m4[choice] -= ordnb;
						}break;
					case 0:
						printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
						printf("  합계 : - %d \n\n", price);
						printf("\a  취소 완료\n\n");
						printf("============================================================\n");
						printf("아무키나 누르시면 메인화면으로 넘어갑니다");
						_getch();
					default:
						printf("다시 선택하세요\n");
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
			printf("총 매출액 : %d", cash + card);
			printf("카드 매출액 : %d", card);
			printf("현금 매출액 : %d \n", cash);
			printf("아무키나 누르시면 메인화면으로 넘어갑니다");
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
				printf("1일권 %i", tblmenu[i].one);
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
				printf("3일권 %i", tblmenu[i].two);
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
				printf("7일권 %i", tblmenu[i].three);
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
				printf("30일권 %i", tblmenu[i].four);
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
