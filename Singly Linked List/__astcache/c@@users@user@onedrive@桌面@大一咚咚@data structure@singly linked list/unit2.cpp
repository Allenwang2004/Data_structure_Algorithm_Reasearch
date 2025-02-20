﻿//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int flag;
struct node
{
	int data;
	struct node *next ,*link;
};

struct node *first, *last ,*temp;

struct node *top;

struct node *NewNode(int element)
{
	struct node *p;
	p = (struct node *) malloc (sizeof(struct node));
	p->data = element;
	p->next = NULL;
	return p;
}

struct QueueNode
{
	char data;
	struct QueueNode *next;
};

struct QueueNode *front, *rear;

struct QueueNode *NewQNode(char element)
{
	struct QueueNode *p;
	p = (struct QueueNode *) malloc (sizeof(QueueNode));
	p->data = element;
	p->next = NULL;
	return p;
}

void InsertAfter(struct node *p, int element)
{
	struct node *x;
	x = (struct node *) malloc (sizeof(struct node));
	if(p == NULL)
	{
		first = x;
		x->next = NULL;
		return;
	}
	x->next = p->next;
	p->next = x;
}

void Insertasfirst(int element)
{
	struct node *p = NewNode(element);
	p->next = first->next;
	first->next = p;
	if(last == first)
		last = p;
}

void Insertaslast(int element)
{
	struct node *p = NewNode(element);
	p->next = last->next;
	last->next = p;
	last = p;
}

void printdata(struct node *first)
{
	struct node *p;
	String list="";
	for(p = first->next; p!=first; p=p->next)
		list += IntToStr(p->data)+"==>";
	Form2->Memo1->Lines->Add(list+"||");
}

struct node* Findtarget(int target)
{
	struct node *p;
	for(p=first->next;(p!=first and p->data!=target); p=p->next);
	if(p==first)
		return NULL;
	else
		return p;
}

struct node* Findtargetbefore(int target)
{
	struct node *p,*q;
	for(q=first, p=first->next;(p!=first and p->data!=target); q=p, p=p->next);
	if(p==first)
		return NULL;
	else
		return q;
}

void Insertafter( int element,struct node *x)
{
	struct node *p = NewNode(element);
	p->next = x->next;
	x->next = p;
}

void deleteafter(struct node *x)
{
	struct node *p = x->next;
	x->next = p->next;
	if(p==last)
        last=x;
	free(p);
}

void clearlist(struct node *first)
{
	struct node *p;
	for(p=first->next;p!=first;p=first->next)
	{
		first->next = p->next;
		free(p);
	}
    last = first;
}

void reverse(struct node *first)
{
	struct node *r,*s,*t;
	r=first->next;
	last=first->next;
	s=first;
	while(r!=first)
	{
		t=s;
		s=r;
		r=r->next;
		s->next = t;
	}
	first->next = s;
}

void push(int element)
{
	struct node *p = NewNode(element);
	p->next = top->next;
	top->next = p;
}

void printstack(struct node *first)
{
	struct node *p;
	String list="";
	for(p = first->next; p!=first; p=p->next)
		list += IntToStr(p->data)+"==>";
	Form2->Memo8->Lines->Add(list+"||");
}

int pop()
{
	struct node *p = top->next;
	if(p == top)
		return -1;
	int result = p->data;
	top->next = p->next;
	free(p);
    return result;
}

void reversestack(struct node *top)
{
	struct node *r,*s,*t;
	r=top->next;
	s=top;
	while(r!=top)
	{
		t=s;
		s=r;
		r=r->next;
		s->next = t;
	}
	top ->next = s;
}

void Addqueue(char element)
{
	struct QueueNode *p;
	p = NewQNode(element);
	p->next = front ->next;
	front ->next =p;
}

char Deletequeue()
{
	struct QueueNode *p;
	char element;
	if(front ->next == rear)
		return '#';
	else
	{
		p = front->next;
		front->next = p->next;
		element = p->data;
		free(p);
		return element;
    }
}

void printqueue(struct QueueNode *front)
{
	struct QueueNode *p;
	String list="";
	for(p = front->next; p!=rear; p=p->next)
		list += IntToStr(p->data)+"==>";
	Form2->Memo6->Lines->Add(list+"||");
}

void reversequeue(struct QueueNode *front)
{
	struct QueueNode *r,*s,*t;
	r=front->next->next;
	s=front->next;
	t=front;
	while(r->next!=front)
	{
		t=s;
		s=r;
		r=r->next;
		s->next = t;
	}
	r->next = s;
	front->next->next = front;
	front->next=r;
	rear = front;
    front = r;

}

void printdata2(struct node *first)
{
	struct node *p;
	String list="";
	for(p = first->next; p!=first; p=p->next)
		list += IntToStr(p->data)+"==>";
	Form2->Memo2->Lines->Add(list+"||");
}

void printdata3(struct node *first)
{
	struct node *p;
	String list="";
	for(p = first->next; p!=temp; p=p->next);
	for(p = temp->next; p!=last; p=p->next)
		list += IntToStr(p->data)+"==>";
    list += IntToStr(p->data)+"==>";
	Form2->Memo2->Lines->Add(list+"||");
}

void printdata4(struct node *first)
{
	struct node *p;
	String list="";
	for(p = first->next; p!=first; p=p->next)
		list += IntToStr(p->data)+"==>";
	Form2->Memo3->Lines->Add(list+"||");
}

void printdata(struct node *first,struct node *x)
{
	struct node *p;
	String list1="";
	String list2="";
	for(p = first->next; p!=x; p=p->next)
		list1 += IntToStr(p->data)+"==>";
	Form2->Memo3->Lines->Add("List 1 : "+list1+"||");
	for(p = x; p!=first; p=p->next)
		list2 += IntToStr(p->data)+"==>";
	Form2->Memo3->Lines->Add("List 2 : "+list2+"||");
}

void printdata2(struct node *first,struct node *x)
{
	struct node *p;
	String list1="";
	String list2="";
	for(p = first->next; p!=x; p=p->next)
		list1 += IntToStr(p->data)+"==>";
	list1 += IntToStr(p->data)+"==>";
	Form2->Memo3->Lines->Add("List 1 : "+list1+"||");
	for(p = x->next; p!=first; p=p->next)
		list2 += IntToStr(p->data)+"==>";
	Form2->Memo3->Lines->Add("List 2 : "+list2+"||");
}

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	first = NewNode(0);
	first -> next = first;
	last = first;
	top = NewNode(0);
	top ->next = top;
	front = NewQNode(0);
	rear = NewQNode(0);
	front ->next =rear;
	rear ->next = front;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	int element  = StrToInt(Edit1->Text);
	Insertaslast(element);
	printdata(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	int element  = StrToInt(Edit1->Text);
	Insertasfirst(element);
	printdata(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
	int target  = StrToInt(Edit2->Text);
	struct node *x;
	x = Findtarget(target);
	if(x)
		Form2->Memo1->Lines->Add(IntToStr(x->data)+" has been found.");
	else
		Form2->Memo1->Lines->Add(target+"has not been found.");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
	int target  = StrToInt(Edit2->Text);
	int element  = StrToInt(Edit1->Text);
	struct node *x;
	x = Findtarget(target);
	if(x)
		Insertafter(element,x);
	else
		Form2->Memo1->Lines->Add(target+"has not been found.");
	printdata(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
	int target  = StrToInt(Edit2->Text);
	int element  = StrToInt(Edit1->Text);
	struct node *x;
	x = Findtargetbefore(target);
	if(x)
		Insertafter(element,x);
	else
		Form2->Memo1->Lines->Add(IntToStr(target)+"has not been found.");
	printdata(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
	int target  = StrToInt(Edit2->Text);
	struct node *x;
	x = Findtargetbefore(target);
	if(x)
		deleteafter(x);
	else
		Form2->Memo1->Lines->Add(IntToStr(target)+"has not been found.");
	printdata(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
	int n  = StrToInt(Edit3->Text);
	int range  = StrToInt(Edit4->Text);
	int *data = new int[n];
	String line = "";
	for(int i=0; i<n; i++)
	{
		data[i] = rand()%range+1;
		line += IntToStr(data[i])+" ";
		Insertaslast(data[i]);
	}
	Form2->Memo1->Lines->Add(IntToStr(n)+" random numbers:"+line);
	printdata(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
	clearlist(first);
	printdata(first);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button9Click(TObject *Sender)
{
	int element  = StrToInt(Edit5->Text);
	push(element);
	printstack(top);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button10Click(TObject *Sender)
{
	int result = pop();
	if (result != -1)
		printstack(top);
	else
		Form2->Memo8->Lines->Add("Stack is empty");
	Edit7->Text = "pop result = " + IntToStr(result);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button12Click(TObject *Sender)
{
	int element  = StrToInt(Edit6->Text);
	Addqueue(element);
	printqueue(front);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click(TObject *Sender)
{
	char result = Deletequeue();
	if (result != '#')
		printqueue(front);
	else
		Form2->Memo6->Lines->Add("Queue is empty");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button13Click(TObject *Sender)
{
	reverse(first);
	printdata(first);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button14Click(TObject *Sender)
{
	int n  = StrToInt(Edit8->Text);
	int range  = StrToInt(Edit9->Text);
	int *data = new int[n];
	String line = "";
	for(int i=0; i<n; i++)
	{
		data[i] = rand()%range+1;
		line += IntToStr(data[i])+" ";
		Insertaslast(data[i]);
	}
	temp = last;
	Form2->Memo2->Lines->Add("List 1 : "+line);
	printdata2(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button15Click(TObject *Sender)
{
	int n  = StrToInt(Edit10->Text);
	int range  = StrToInt(Edit11->Text);
	int *data = new int[n];
	String line = "";
	for(int i=0; i<n; i++)
	{
		data[i] = rand()%range+1;
		line += IntToStr(data[i])+" ";
		Insertaslast(data[i]);
	}
	Form2->Memo2->Lines->Add("List 2 : "+line);
	printdata3(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button16Click(TObject *Sender)
{
	Form2->Memo2->Lines->Add("Result : ");
	printdata2(first);
	clearlist(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::PageControl1Change(TObject *Sender)
{
	clearlist(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button17Click(TObject *Sender)
{
	clearlist(first);
	int n  = StrToInt(Edit12->Text);
	int range  = StrToInt(Edit13->Text);
	int *data = new int[n];
	String line = "";
	for(int i=0; i<n; i++)
	{
		data[i] = rand()%range+1;
		line += IntToStr(data[i])+" ";
		Insertaslast(data[i]);
	}
	Form2->Memo3->Lines->Add("List : "+line);
	printdata4(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
	flag = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
	flag = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button18Click(TObject *Sender)
{
	int temp  = StrToInt(Edit14->Text);
	struct node *x;
	x = Findtarget(temp);
	if(x)
	{
        if(flag == 1)
		{
			printdata(first,x);
		}
		else
		{
			printdata2(first,x);
		}
		clearlist(first);
	}
	else
	{
		Form2->Memo3->Lines->Add(IntToStr(temp)+" has not been found.");
		Form2->Memo3->Lines->Add("Choose another target.");
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button19Click(TObject *Sender)
{
	reversestack(top);
	printstack(top);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button20Click(TObject *Sender)
{
	reversequeue(front);
	printqueue(front);
}
//---------------------------------------------------------------------------

