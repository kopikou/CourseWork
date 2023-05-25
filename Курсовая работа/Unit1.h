//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.WinXCalendars.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit5;
	TEdit *Edit7;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *Button1;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit9;
	TComboBox *ComboBox1;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit5KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit7KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit5Exit(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit9KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit9Exit(TObject *Sender);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall Edit7Exit(TObject *Sender);
	void __fastcall ComboBox1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DateTimePicker1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DateTimePicker2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
