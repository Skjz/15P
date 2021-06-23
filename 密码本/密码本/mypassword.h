#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define PATH "..\\debug\\write.txt"

struct USERINFO
{
    char Website[20];
    char Username[20];
    char Password[20];
    //char IncodePassword[20];
    //char UncodePassword[20];

};


extern int Count;
extern int Maxsize;
extern USERINFO* new_p;
extern char Account[20];
extern char ThisPassword[20];
//extern Incode* cp;
extern int flag;
void ShowMenu();
void Change(struct USERINFO* p);
void Add(struct USERINFO** p);
void Dele(struct USERINFO* p);
void SeeAll(struct USERINFO* p);
void Search(struct USERINFO* p);
//void Check(struct USERINFO* p, /*struct USERINFO* new_p*/);
void Save(struct USERINFO *p,int Count);
void Read( struct USERINFO *p,int *Count);
void Uncodepassword(struct USERINFO *p);
void Incode(struct USERINFO* p,int Count);
int  Login(char *Account, char *ThisPassword);


