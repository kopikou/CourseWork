//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "About.h"
#include <iostream>
#include <fstream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}

//������ �������� � ���������� �������---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
	Form3= new TForm3(this);//���������� ��������
	Form3->ShowModal();//����� ��������
	Form3->Free();//�������� �����
	fill();//���������� ��������� �������
}

//����� ��������� �����---------------------------------------------------------------------------
void __fastcall TForm4::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (flag) {//���� ��������� ���������
		if(filename=="")//���� ���� �� �����������
		{
			switch (MessageDlg("�� ������ ��������� ��������� � �����?",mtConfirmation,mbYesNoCancel,0)) {
			case mrYes: N6Click(Sender);//��������� ���
			case mrNo: Application->Terminate();//������� �����
			}
		}
		else//���� ���� ��� ����������
		{
			switch (MessageDlg("�� ������ ��������� ��������� � �����?",mtConfirmation,mbYesNoCancel,0)) {
			case mrYes: N5Click(Sender);//���������
			case mrNo: Application->Terminate();//������� �����
		   }
		}
	   
   }
}

//����->�������: �������� ������ �����---------------------------------------------------------------------------
void __fastcall TForm4::N2Click(TObject *Sender)
{
	if (flag) {//���� ��������� ���������
		switch (MessageDlg("�� ������ ��������� ��������� � �����?",mtConfirmation,mbYesNoCancel,0)) {
		case mrYes:
			{
				N5Click(Sender);//���������
				createnew();//�������� ������ �����
				break;
			}
		case mrNo:
			{
				createnew();//�������� ������ �����
				break;
			}
		}
	}
	else{//���� �� ���� ���������
		createnew();//�������� ������ �����
    }
}
//������ ������������: �������� ������ �����---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton1Click(TObject *Sender)
{
	N2Click(Sender);//����� ������� �������� ������ �����
}

//����->�������: �������� �����---------------------------------------------------------------------------
void __fastcall TForm4::N3Click(TObject *Sender)
{
	if (OpenDialog1->Execute()) {//���� ������� ���������� ����
		gridclear();

		TFileStream *fs = new TFileStream(OpenDialog1->FileName, fmOpenRead);//��������� ��������� ���� ��� ������
		filename= OpenDialog1->FileName;//��������� ��� �����
		int fileSize = fs->Size;//��������� ������ �����
		StringGrid1->RowCount = StringGrid1->RowCount+ fileSize/108;//���������� ���������� ����� � �������
		char *buffer;//��������������� ������ ������
		for (int i = 1; i < StringGrid1->RowCount-1; i++) {
			for (int j = 1; j < StringGrid1->ColCount; j++) {
				buffer = new char[dataSize[j-1]];//������� ���������� ������� �������
				fs->Read(buffer, dataSize[j-1]);//��������� ������ �� �����
				StringGrid1->Cells[j][i] = buffer;//��������� ������ �������
			}
			StringGrid1->Cells[0][i] = i;//�������� ������
		}
		delete[] buffer;//������� ������
		delete fs;//������� ���������� ���������� ������
	}

	N3->Enabled=false;ToolButton2->Enabled=false;//�������
	turnon();//����������� ������� ����
	flag = false;//���� ��������� �����
}
//������ ������������: �������� �����---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton2Click(TObject *Sender)
{
	N3Click(Sender);//����� ������� �������� �����
}

//����->���������---------------------------------------------------------------------------
void __fastcall TForm4::N5Click(TObject *Sender)
{
	if(flag){//���� ��������� ��������� � �����
		if(filename=="")//���� ���� ����� �� �����������
		{
			N6Click(Sender);//�������� ������� ���������� ���
		}
		else//���� ���� ��� ����������
		{
			TFileStream *fs = new TFileStream(filename, fmOpenWrite);//��������� ���� ��� ������
			fs->Size = 0;//������� ����
			save(fs);//������� ����������
		}
	}

	flag = false;//���� ���������
}
//������ ������������: ���������---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton3Click(TObject *Sender)
{
	N5Click(Sender);//����� ������� ����������
}

//����->��������� ���:---------------------------------------------------------------------------
void __fastcall TForm4::N6Click(TObject *Sender)
{
	if(SaveDialog1->Execute()){//���� ������� ���������� ����
		TFileStream *fs = new TFileStream(SaveDialog1->FileName, fmCreate);//������� ����� ����
		filename= SaveDialog1->FileName;//���������� ��� �����
		save(fs);//������� ����������
	}
	flag = false;//���� ���������
}

//����->�������--------------------------------------------------------------------------
void __fastcall TForm4::N8Click(TObject *Sender)
{
	N2Click(Sender);//����� ������� �������� ������ �����
}

//����->�����---------------------------------------------------------------------------
void __fastcall TForm4::N10Click(TObject *Sender)
{
	this->Close();//�������� �����
	bool CanClose=true;
	FormCloseQuery(Sender,CanClose);//����� ������� ����� ��������� �����
}

//������->�������� ������---------------------------------------------------------------------------
void __fastcall TForm4::N12Click(TObject *Sender)
{
	Form1->Button1->Caption="��������";//�������� �������� ������ �� �����
	Form1->Caption="����������";//�������� �������� �����
	Form1->Show();//�������� �����

	flag = true;//���� ���������
	N5->Enabled=true;ToolButton3->Enabled=true;//����������� "���������"
	turnon();//����������� ������� ����
}
//������ ������������: �������� ������---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton5Click(TObject *Sender)
{
	N12Click(Sender);//����� ������� ���������� ������
}

//������->������������� ������---------------------------------------------------------------------------
void __fastcall TForm4::N14Click(TObject *Sender)
{
	int nm = StringGrid1->Selection.Top;//���������� ����� �� ������
	Form1->Button1->Caption="�������������";//�������� �������� ������ �� �����
	Form1->Caption="��������������";//�������� �������� �����

	editfill(nm);//���������� ����� ������� �� �������

	Form1->Show();//�������� �����

	flag=true;//���� ���������
	N5->Enabled=true;ToolButton3->Enabled=true;//����������� "���������"
}
//������ ������������: ������������� ������---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton7Click(TObject *Sender)
{
	N14Click(Sender);//����� ������� �������������� ������
}

//������->������� ������---------------------------------------------------------------------------
void __fastcall TForm4::N13Click(TObject *Sender)
{
	int nm  = StringGrid1->Selection.Top;//���������� ����� �� ������
	switch (MessageDlg("�� ������ ������� '" + StringGrid1->Cells[1][nm] + "'?",mtConfirmation,mbYesNo,0)) {
	case mrYes:
		{
			for (int i = nm;i < StringGrid1-> RowCount-1;++i) {
				StringGrid1-> Rows[i] = StringGrid1-> Rows[i+1];//������� ��� ������ �� ���� �����
			}
			StringGrid1->RowCount--;//��������� ���������� ����� � �������
			rownumber();//��������������� ��������� �����
			break;
		}
	}
	N5->Enabled=true;ToolButton3->Enabled=true;//����������� "���������"
	if(StringGrid1-> RowCount==2){//���� ���������� ����� ����� 2
		N3->Enabled=true;ToolButton2->Enabled=true;//����������� "�������"
		turnoff();//������������� ������� ����
	}
	flag = true;//���� ���������
}
//������ ������������:������� ������---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton6Click(TObject *Sender)
{
	N13Click(Sender);//����� ������� �������� ������
}

//���������->�����---------------------------------------------------------------------------
void __fastcall TForm4::N24Click(TObject *Sender)
{
	Form2->Show();//������� �����
}
//������ ������������: �����---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton9Click(TObject *Sender)
{
	N24Click(Sender);//����� ������� ������
}

//���������� �� �����������---------------------------------------------------------------------------
void __fastcall TForm4::N27Click(TObject *Sender)
{
	int nm = StringGrid1->Selection.Left;//������������� ����� �� �������
	if(StringGrid1->Cells[nm][0]=="���� ��������" || StringGrid1->Cells[nm][0]=="���� ����� �� ������")//���� ���������� �� ����
		sortData(sort_up, nm,data_date);//���������� �� �����������, ��� ���
	else//���� ���������� ��� �����
		sortData(sort_up, nm,data_str);//���������� �� �����������, ��� �����

	flag = true;//���� ���������
	N5->Enabled=true;ToolButton3->Enabled=true;//����������� "���������"
}
//���������� �� ��������---------------------------------------------------------------------------
void __fastcall TForm4::N28Click(TObject *Sender)
{
	int nm = StringGrid1->Selection.Left;//������������� ����� �� �������
	if(StringGrid1->Cells[nm][0]=="���� ��������" || StringGrid1->Cells[nm][0]=="���� ����� �� ������")//���� ���������� �� ����
		sortData(sort_down, nm,data_date);//���������� �� ��������, ��� ���
	else//���� ���������� ��� �����
		sortData(sort_down, nm,data_str);//���������� �� ��������, ��� �����

	flag = true;//���� ���������
	N5->Enabled=true;ToolButton3->Enabled=true;//����������� "���������"
}

//���������� ���������� �����������, �������� �� ������ � .... ����---------------------------------------------------------------------------
void __fastcall TForm4::N32Click(TObject *Sender)
{
	Button1->Visible=true;//������ � ������
	Label1->Visible=true;//������ � ���������
	ComboBox1->Items->Clear();//������� ������
	ComboBox1->Visible=true;//����� ����
	ComboBox1->SetFocus();//��������� ����� �� ���������� ������

	for(int i=1;i<StringGrid1->RowCount-1;i++){
		AnsiString dop =  StringGrid1->Cells[8][i];//����������� �������� ������ ������
		AnsiString dop1 =  dop.SubString(7,10);//�������� ��� �� ����
		if (ComboBox1->Items->IndexOf(dop1) < 0) //���������, ��� �� ������ �������� ��� � ������ combobox
			ComboBox1->Items->Add(dop1);//���������
	}
}
//���������� ���������� �����������, �������� �� ������ � .... ����---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	if(ComboBox1->ItemIndex>-1){//���� ������� ���-�� �� ������
		int k = 0;//���������� �����������
		for(int i=1;i<StringGrid1->RowCount-1;i++){
			AnsiString dop =  StringGrid1->Cells[8][i];//����������� �������� ������ ������
			AnsiString dop1 =  dop.SubString(7,10);//�������� ��� �� ����
			if(dop1==ComboBox1->Items->Strings[ComboBox1->ItemIndex])//���� ��� ���� � ������
				k++;//������� ���������� �����������
	}
	ShowMessage("���������� �����������, �������� �� ������ � "+ComboBox1->Items->Strings[ComboBox1->ItemIndex]+" ����: "+k);
	}
	else{//���� ������ �� �������
	ShowMessage("�������� ��� �� ������, ����� ���������� ���������� �����������");
	}
	ComboBox1->Text="���";//������������� ���������
}
//���������� �������� ��������---------------------------------------------------------------------------
void __fastcall TForm4::N33Click(TObject *Sender)
{
	ComboBox1->Visible=false;//����� ����
	Button1->Visible=false;//������ ������
	Label1->Visible=false;//���������

	int c = StringGrid1->RowCount-2;//���������� �����������
	int s = 0;//��������� �������
	for(int i=1;i<StringGrid1->RowCount-1;i++){
		AnsiString dop =  StringGrid1->Cells[4][i];//����������� �������� ������ ������
		AnsiString dop1 =  dop.SubString(7,10);//�������� ��� �� ����
		s += (2023-StrToInt(dop1));//��������� ������� �� ����������� ���
		}
	ShowMessage("������� ������� �����������: "+IntToStr(s/c));
}
//���������� % ����������� � ������ ������������---------------------------------------------------------------------------
void __fastcall TForm4::N34Click(TObject *Sender)
{
	ComboBox1->Visible=false;//����� ����
	Button1->Visible=false;//������ ������
	Label1->Visible=false;//���������

	int cnt = 0;//���������� ����������� � ������ ������������(3)
	for(int i=1;i<StringGrid1->RowCount-1;i++){
	AnsiString dop = StringGrid1->Cells[6][i];//����������� �������� ������ ������
		if(dop=="������"){//���� ������ �����������
			++cnt;//����������� ���������� ����������� � ������ ������������
		}
	}
	ShowMessage("������� ����������� � ������ ������������: "+IntToStr(cnt*100/(StringGrid1->RowCount-2))+"%");
}

//�������->�������: �������� ��������� �����---------------------------------------------------------------------------
void __fastcall TForm4::N17Click(TObject *Sender)
{
	WinExec("C:\\Windows\\system32\\notepad.exe E:\\Embarcadero\\Studio\\Projects\\�������� ������\\files\\task.txt", SW_SHOW);
}
//�������->� ���������: �������� ��������� �����---------------------------------------------------------------------------
void __fastcall TForm4::N18Click(TObject *Sender)
{
	AboutBox->Show();
}
//�������->���������� �������: �������� ��������� �����---------------------------------------------------------------------------
void __fastcall TForm4::N19Click(TObject *Sender)
{
	WinExec("C:\\Windows\\system32\\notepad.exe E:\\Embarcadero\\Studio\\Projects\\�������� ������\\files\\Ref.txt", SW_SHOW);
}

//����������� ������������ ����---------------------------------------------------------------------------
void __fastcall TForm4::StringGrid1MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if(Button==mbRight){//���� ������ ���
		TGridCoord coord = StringGrid1->MouseCoord(X, Y); //�������� ���������� ������
		StringGrid1->Row = coord.Y;//���������� ������ � ������ ���������� ������
		StringGrid1->Col = coord.X;//���������� ������ � ������� ���������� ������

		int row = StringGrid1->Row;//���������� ����� ���������� ������
		if (row <StringGrid1->RowCount-1)//���� � ����� ������ ���������� �����
			StringGrid1->PopupMenu = PopupMenu1;//����������� ���� ����� 1
		else
			StringGrid1->PopupMenu = PopupMenu2;//����������� ���� ����� 2
	}
}

//---------------------------------------------------------------------------

