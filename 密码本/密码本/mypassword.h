#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
struct USERINFO
{
    char Website[20];
    char Username[20];
    char Password[20];
};
extern int Count;
extern int Maxsize;
extern USERINFO* new_p;
void ShowMenu();
void Change(struct USERINFO* p);
void Add(struct USERINFO* p);
void Dele(struct USERINFO* p);
void SeeAll(struct USERINFO* p);
void Search(struct USERINFO* p);
void Check(struct USERINFO* p, struct USERINFO* new_p);


