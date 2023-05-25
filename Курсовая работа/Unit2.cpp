//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//�����---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	for (int i=1; i < Form5->StringGrid1->RowCount; i++) {
			Form5->StringGrid1->Rows[i]->Clear();//������� ������ �������
		}
	Form5->StringGrid1->RowCount=2;//������������ �������������� ���������� ����� � �������

	bool flagsearch = false;//���� ������
	Form4->Show();//�������� �����

	int k = 1;//������� ����� ��� ������� � ����������� ������
	AnsiString searchString="";//�������������� ������ ��� �����������, ���� �� ��� � �������������� ������� ��������� ������
	for(int i = 1; i < Form4->StringGrid1->RowCount; i++)
	{
		for(int j = 1; j < Form4->StringGrid1->ColCount; j++)
		{
			if(Form4->StringGrid1->Cells[j][i].SubString(1,(Edit1->Text).Length())==Edit1->Text)//���� � ������ ������� ���� ���������, ������� ���� �����
			{
				if(searchString != Form4->StringGrid1->Rows[i]->Strings[0].Trim()){//���� ������� ������ ������� ��� �� �������� � �������������� �������
					Form5->StringGrid1->Rows[k]=Form4->StringGrid1->Rows[i];//���������� ��������� ������ � �������������� �������
					searchString=Form4->StringGrid1->Rows[i]->Strings[0].Trim();//���������� ��������� ������
					Form5->StringGrid1->RowCount=Form5->StringGrid1->RowCount+1;//����������� ���������� ����� � �������������� �������
					k++;//��������� �� ��������� ������ �������������� �������
					flagsearch=true;//���� ������
				}
			}
		}
	}
	if (flagsearch == false) {//���� �� ����� ����������
		ShowMessage("�� ������ ����� '" + Edit1->Text + "'");
	}
	else{
		Form5->Show();//���������� ����� � ��������
	}
}
//������� �� ��������� ������� � ������� Enter---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {Button1-> SetFocus();}
}
//������������� ����� �� ��������� ����---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
	Edit1->SetFocus();
}
//��������� � ������� ������� ��, ��� ����-------------------------------------------------------------------------
void __fastcall TForm2::Edit1Exit(TObject *Sender)
{
	AnsiString text = Edit1->Text;//�������� ������� ����� � edit
	text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1);//������������� ������ ����� � ������� �������
	Edit1->Text = text;//��������� ����� � edit
}
//---------------------------------------------------------------------------

