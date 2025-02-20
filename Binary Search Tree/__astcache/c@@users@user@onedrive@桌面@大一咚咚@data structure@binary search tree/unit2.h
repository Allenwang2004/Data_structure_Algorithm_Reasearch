﻿//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TMemo *Memo1;
	TButton *Button8;
	TButton *Button9;
	TGroupBox *GroupBox1;
	TEdit *Edit4;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit5;
	TButton *Button3;
	TGroupBox *GroupBox2;
	TLabel *Label5;
	TEdit *Edit2;
	TButton *Button4;
	TGroupBox *GroupBox3;
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TCheckBox *CheckBox1;
	TGroupBox *GroupBox5;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TCheckBox *CheckBox2;
	TImage *Image1;
	TScrollBox *ScrollBox1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
