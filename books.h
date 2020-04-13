#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 5      // 저장할 수 있는 회원 레코드 최대 갯수

// 회원 정보 레코드의 데이터 타입을 정의함
typedef struct book_sell{
    int no;
    char book_name[30];
	char seller_name[20];
	int price;
	char seller_phone[20];
	char subject[20];
	char department[20];
	char password[20];

} T_Record;

// 라이브러리 함수 원형을 선언함
int b_is_available();      
int b_first_available();    
int b_count();              
void b_create(int n,char* bn, char* sn, int pr, char* sp,char* s,char* de,char*pw); 
T_Record* b_search_by_name(char* n);                
//void b_update(T_Record* p, int pr, char* sp, char* s,char* pw); 
//void b_delete(T_Record* p);     
void b_get_all(T_Record* a[]);  
char* b_to_string(T_Record* p); 
char* b_getbookname(T_Record* p);
char* b_getsellername(T_Record* p);    
int b_getprice(T_Record* p);
char* b_getsellerphone(T_Record* p);
char* b_getsubject(T_Record* p);
char* b_getdepartment(T_Record* p);
char * b_getpassword(T_Record *p);
int b_getno(T_Record *p);  
