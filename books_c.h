#include "books.h"

T_Record* Books[MAX_MEMBERS]; 
int _count = 0;

int b_is_available(){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(Books[i]==NULL) return 1;
    }
    return 0;
}

int b_first_available(){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(Books[i]==NULL) return i;
    }
    return -1;
}

int b_count(){
    return _count;
}

void b_create(int n,char* bn, char* sn, int pr, char* sp,char* s,char* de,char*pw){
    int index = b_first_available();
    Books[index] = (T_Record*)malloc(sizeof(T_Record));
    T_Record* p = Books[index];
    p->no = n+1;	
    strcpy(p->book_name, bn);
    strcpy(p->seller_name, sn);  
    p->price = pr;
    strcpy(p->seller_phone, sp);
    strcpy(p->subject, s);
    strcpy(p->department, de);
    strcpy(p->password, pw);
    _count++;
}

T_Record* b_search_by_name(char* bn){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(Books[i] && strcmp(Books[i]->book_name, bn)==0) return Books[i];
    }
    return NULL;
}

char* b_to_string(T_Record* p){
    static char str[80];
    sprintf(str, "[%d] %s / %d / %s / %s / %s", p->no,p->book_name,p->price, p->seller_phone,p->seller_name, p->subject);
    return str;
}

void b_get_all(T_Record* a[]){
    int i, c=0;
    for(i=0; i<MAX_MEMBERS; i++){
        if(Books[i]){
            a[c]=Books[i];
            c++;
        }
    }
}

char* b_getbookname(T_Record* p){
    return p->book_name;
}

char* b_getsellerphone(T_Record* p){
    return p->seller_phone;
}

char* b_getsellername(T_Record* p){
    return p-> seller_name;
}

char* b_getsubject(T_Record* p){
    return p->subject;
}

char* b_getdepartment(T_Record* p){
    return p->department;
}

int b_getprice(T_Record* p){
    return p->price;
}

char* b_getpassword(T_Record* p){
    return p->password;
}
int b_getno(T_Record* p){
	return p->no;
}
