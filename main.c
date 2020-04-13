#include "books.h"
#include <stdbool.h>

// 애플리케이션용 함수 원형
void create_record();
void read_book_record();
void read_subject_record();
bool check_pw(T_Record *p);
void list_record();
int get_list_record(char* name, int co);

int main(){
	int menu;
	while(1){
		printf("\nMenu : 1.Create 2.Read(book_name) 3.Read(subject) 4:list 0.Quit > ");
		scanf("%d", &menu);
		printf("\n");
		switch(menu){
			case 1: 
				create_record();
				break;
			case 2: 
				read_book_record();
				break;
			case 3:
				read_subject_record();
				break;
			case 4: 
				list_record();
				break;
			case 0:
			default: 
				return 0;
		}
	}
	return 0;
}

void create_record(){
	if(b_count() == MAX_MEMBERS){
		printf("There is no space!\n");
		return;
	}
	char book_name[30], seller_phone[20], seller_name[20],subject[20],department[20],password[20];
	int price;  

	printf("Enter the book name you want to sell\n");
	printf("Name > ");
	scanf("%s", book_name);
	printf("Enter your name > ");
	scanf("%s", seller_name);
	printf("Enter your phone number > ");
	scanf("%s",seller_phone);
	printf("Enter the expect price you want to sell > ");
	scanf("%d", &price);
	printf("Enter the subject of this book > ");
	scanf("%s", subject);
	printf("Enter the department of this book > ");
	scanf("%s",department);
	printf("Enter the password of this item > ");
	scanf("%s",password);

	b_create(b_count(),book_name,seller_name,price,seller_phone,subject,department,password);

	printf("\nCreate success!\n");
}


void list_record(){
	// 전체 리스트 출력
	printf("All records.\n");
	int size = b_count();
	T_Record* bks[MAX_MEMBERS];
	b_get_all(bks);
	for(int i=0; i<size; i++){
		T_Record* p = bks[i];
		printf("%d. %s\n", i+1, b_to_string(p));
	}
}

void read_book_record(){
	int num = 0;
	char str[20];
	bool get=false;
	//검색 -> 이름 입력, 받음 
	printf("Enter the book name > ");
	scanf("%s",str);
	//없는이름 -> 없음(예외처리)
	int size = b_count();
	T_Record* bks[MAX_MEMBERS];
	b_get_all(bks);
	num = get_list_record(str,1);
	if(num >  0){
		printf("Enter the book no you want to see > ");
		scanf("%d",&num);
		for(int i=0; i<size; i++){
			T_Record* p = bks[i];
			if(num == b_getno(p)){
				printf("***Book martket*** \nBook name : %s \nBook seller: %s \nPrice: %d \nSeller Phone: %s\nSubject: %s\nDepartment: %s\n",b_getbookname(p),b_getsellername(p),b_getprice(p),b_getsellername(p),b_getsubject(p),b_getdepartment(p));  
				return;
			}
		}
	}else
		printf("\nUnregisterd name!\n");
}

void read_subject_record(){
	int num = 0;
	char str[20];
	bool get=false;
	//검색 -> 이름 입력, 받음 
	printf("Enter the subject name > ");
	scanf("%s",str);
	//없는 과목 -> 없음(예외처리)
	int size = b_count();
	T_Record* bks[MAX_MEMBERS];
	b_get_all(bks);
	num = get_list_record(str,2);
	if(num > 0){
		printf("Enter the book no you want to see > ");
		scanf("%d",&num);
		for(int i=0; i<size; i++){
			T_Record* p = bks[i];
			if(num == b_getno(p)){
				printf("***Book martket*** \nBook name : %s \nBook seller: %s \nPrice: %d \nSeller Phone: %s\nSubject: %s\nDepartment: %s\n",b_getbookname(p),b_getsellername(p),b_getprice(p),b_getsellername(p),b_getsubject(p),b_getdepartment(p));  
				return;
			}
		}
	}else
		printf("\nNo search!\n");
}

bool check_pw(T_Record *p){

	char str[20];
	printf("Enter the password of your book > ");
	scanf("%s",str);
	//없는 비밀번호 -> 없음(예외처리)
	if(strcmp(str,b_getpassword(p))== 0){
		return true;
	}
	return false;

}

int get_list_record(char* name,int co){
	int n =0;
	int size = b_count();
	T_Record* bks[MAX_MEMBERS];
	b_get_all(bks);
	for(int i=0; i<size; i++){
		T_Record* p = bks[i];
		if(co == 2){
			printf("search for subject\n");
			if(strcmp(name,b_getsubject(p)) == 0){
				printf("%s\n", b_to_string(p));
				n ++;
			}
		}else if(co == 1){
			printf("search for bookname\n");
			if(strcmp(name,b_getbookname(p)) == 0){
				printf("%s\n",b_to_string(p));
				n++;
			}
		}
	}

	return n;
}
