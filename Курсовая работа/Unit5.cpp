//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//Заполнение заголовка таблицы---------------------------------------------------------------------------
void __fastcall TForm5::FormShow(TObject *Sender)
{
	Form2->Show();
	StringGrid1->Cells[1][0]="Фамилия";//Заголовок таблицы
	StringGrid1->ColWidths[1] = 200;//Размер, отводимы под слово
	StringGrid1->Cells[2][0]="Имя";
	StringGrid1->ColWidths[2] = 200;
	StringGrid1->Cells[3][0]="Отчество";
	StringGrid1->ColWidths[3] = 200;
	StringGrid1->Cells[4][0]="Дата рождения";
	StringGrid1->ColWidths[4] = 175;
	StringGrid1->Cells[5][0]="Паспортные данные";
	StringGrid1->ColWidths[5] = 240;
	StringGrid1->Cells[6][0]="Образование";
	StringGrid1->ColWidths[6] = 150;
	StringGrid1->Cells[7][0]="Должность";
	StringGrid1->ColWidths[7] = 200;
	StringGrid1->Cells[8][0]="Дата приёма на работу";
	StringGrid1->ColWidths[8] = 250;
	StringGrid1->Cells[0][0]="№";
	StringGrid1->ColWidths[0] = 50;
}
//---------------------------------------------------------------------------
