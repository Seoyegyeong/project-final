#include "books.h"
#include <string.h>

T_Record* Books[MAX_MEMBERS]; 
int _count = 0;

int b_is_available(){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
	#ifdef DEBUG
		printf("[RECORD] DEBUGGING processing\n");
	#endif
        if(Books[i]==NULL) return 1;
    }
    return 0;
}

int b_first_available(){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(Books[i]==NULL) return i;
	#ifdef DEBUG
	printf("[RECORD] %d finding NULL for saving",i);
	#endif
	
    }
    return -1;
}

int b_count(){
    #ifdef DEBUG
	printf("[REOCRD] return count number of books\n");
    #endif
    return _count;
}

void b_update(T_Record* p, int pr,char* s,char* de){
    p->price = pr;
    strcpy(p->subject, s);
    strcpy(p->department, de);
#ifdef DEBUG
	printf("[RECORD] update scuccess for \n price: %d\nsubject %s\ndepartment: %s\n",p->price,p->subject,p->department);
#endif
}


void b_create(int n,char* bn, char* sn, int pr, char* sp,char* s,char* de,char*pw){
    int index = b_first_available();
    Books[index] = (T_Record*)malloc(sizeof(T_Record));
    T_Record* p = Books[index];
    strcpy(p->book_name, bn);
    strcpy(p->seller_name, sn);  
    p->price = pr;
    strcpy(p->seller_phone, sp);
    strcpy(p->subject, s);
    strcpy(p->department, de);
    strcpy(p->password, pw);
    _count++;
#ifdef DEBUG
	printf("[RECORD] CREATE SUCCESS, Bookname: %s, Bookprice: %d, BookSeller: %s\n",p->book_name,p->price,p->seller_name);

#endif
}

T_Record* b_search_by_name(char* bn){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(Books[i] && strcmp(Books[i]->book_name, bn)==0) return Books[i];
#ifdef DEBUG
	printf("[RECORD] SUCCESS SEARCH, going %d books\n",i);
#endif	
    }
    return NULL;
}

char* b_to_string(T_Record* p){
    static char str[80];
    #ifdef DEBUG
	printf("[RECORD] record to string success\n");
   #endif
    sprintf(str, "[%d] %s / %d / %s / %s / %s", p->no,p->book_name,p->price, p->seller_phone,p->seller_name, p->subject);
	return str;
}

void b_get_all(T_Record* a[]){
    int i, c=0;
    for(i=0; i<MAX_MEMBERS; i++){
        if(Books[i]){
            a[c]=Books[i];
            c++;
	    #ifdef DEBUG
		printf("[RECORD] record is gettering %d\n",i);
	    #endif
        }
    }
}

void b_delete(T_Record* p){
		int i, index;
		for(i=0; i<MAX_MEMBERS; i++)
				if(Books[i]==p) {
						index=i;
						break;
				}
		free(p);
		Books[index] = NULL;
		_count--;

#ifdef DEBUG
	printf("[RECORD] record deleting");
#endif
}

void b_sort(T_Record* a[]){
	int i,j;
	for(i=0;i<MAX_MEMBERS;i++){
		if(Books[i]){
			a[i] = Books[i];
			#ifdef DEBUG
			printf("[RECORD] Found Books in i[%d]\n",i);
			#endif
			for(j=i;j<MAX_MEMBERS;j++){
        		if(Books[j]){
				#ifdef DEBUG
				printf("[RECORD] Found Books in j[%d]\n",i);
				printf("string compare with i and j result : %d",strcmp(a[i]->book_name,Books[j]->book_name));
				#endif
					if(strcmp(a[i]->book_name,Books[j]->book_name)==1){
						a[i] = Books[j];
						#ifdef DEBUG
						printf("[RECORD] (%d).%s -saved",i,a[i]->book_name);
						#endif
					}
				}
			}
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
#ifdef debug
   printf("getting price");
#endif
    return p->price;
}

char* b_getpassword(T_Record* p){
#ifdef debug
   prinf("getting password");
#endif
   return p->password;
}
int b_getsno(T_Record* p){
#ifdef debug 
   printf("get no is now started");
#endif
    return p->no;
}

