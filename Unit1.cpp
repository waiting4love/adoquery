//*****************************************************//
//                                                     //
//      ∞Ê»®À˘”– (C) 2008 www.cpp-prog.com              //
//                                                     //
//*****************************************************//

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "blob.h"
#include <memory>
#include <vector>
#include <olectrls.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using std::auto_ptr;
using std::vector;

struct TBkEdit : TComponent{

    enum TState{esNone,esPass,esFail};

    __fastcall TBkEdit(TCustomEdit *edt, Graphics::TBitmap* bkbmp)
        :TComponent(edt),m_edt(edt)
    {
        m_wmOldProc = edt->WindowProc;
        edt->WindowProc = NewProc;
        m_Brush = new TBrush;
        m_bmpDraw = new Graphics::TBitmap;
        m_bmpDraw->Assign(bkbmp);

        m_Brush->Bitmap = m_bmpDraw;
        m_edt->Invalidate();
    }
    __fastcall ~TBkEdit(){
        m_edt->WindowProc = m_wmOldProc;
        delete m_Brush;
        delete m_bmpDraw;
    }

private:
    TCustomEdit *m_edt;
    TWndMethod m_wmOldProc;

    TState m_State;
    TBrush *m_Brush;
    Graphics::TBitmap *m_bmpDraw;

    void __fastcall NewProc(Messages::TMessage &Message)
    {
        m_wmOldProc(Message);
        if(Message.Msg == CN_CTLCOLOREDIT)
        {
            HDC hdc = (HDC)Message.WParam;
            ::SetBkMode(hdc, TRANSPARENT);

            Message.Result = (LRESULT)m_Brush->Handle;
        }
    }
};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}

//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
    ADOQuery1->Active=false;
    ADOQuery1->SQL->Clear();

    for (int i=0;i<Memo1->Lines->Count;i++)
        ADOQuery1->SQL->Add(Memo1->Lines->Strings[i]);

    try
    {
        ADOQuery1->Active=true;
        StatusBar1->Panels->Items[1]->Text="Ready!";
        StatusBar1->Panels->Items[0]->Text=ADOQuery1->RecordCount;
    }
    catch (Exception &e)//(char *s)
    {
        //ShowMessage(e.Message);
        //does not return a result set
        StatusBar1->Panels->Items[1]->Text=e.Message;
    }

    ADOConnection1->GetTableNames(ListBox1->Items,false);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1KeyDown(TObject *Sender, WORD &Key,
                                     TShiftState Shift)
{
    if (Shift.Contains(ssCtrl)&&Key==VK_RETURN)
    {
        SpeedButton1Click(NULL);
    }
    else if (Key==VK_F1)
    {
        ShellExecute(Handle,_T("open"),_T("SQL.chm"),NULL,NULL,SW_SHOW);
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{

    //OleVariant varEmpty = EmptyParam;
	String S;

	SHORT nVirtKey = ::GetKeyState(VK_SHIFT);
	if(nVirtKey & 0x8000)
	{
    	if(!InputQuery(_T("Connection String"), _T("Please input connection string:"), S)) return;
	}
	else
	{
		S=PromptDataSource((unsigned)Handle,ADOConnection1->ConnectionString);
	}
	/*
     Provider=Microsoft.Jet.OLEDB.4.0;
     Data Source=c:\\book1.xls;
     Extended Properties=Excel 8.0;
    */

    edtConStr->Text = S;
    if (!SameText(S,ADOConnection1->ConnectionString))
    {
        ADOConnection1->Connected=false;
		ADOConnection1->ConnectionString=S;

        try
        {
            ADOConnection1->Connected=true;
			ADOConnection1->GetTableNames(ListBox1->Items,false);
            StatusBar1->Panels->Items[1]->Text="Ready!";
        }
        catch (Exception &e)
        {
            StatusBar1->Panels->Items[1]->Text=e.Message;
        }
    }

    Memo1->PopupMenu=ADOConnection1->Connected?PopupMenu1:NULL;

    Button2->Enabled=ADOConnection1->Connected;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
    static AnsiString LastTable=NULL;

    if (ListBox1->ItemIndex>=0)
    {
        AnsiString S=ListBox1->Items->Strings[ListBox1->ItemIndex];

        if (SameText(S,LastTable))return;

        LastTable=S;

        try
        {
            ADOConnection1->GetFieldNames(S,ListBox2->Items);
            StatusBar1->Panels->Items[1]->Text="Ready!";
        }
        catch (Exception &e)
        {
            StatusBar1->Panels->Items[1]->Text=e.Message;
            //ShowMessage(e.Message);
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox1DblClick(TObject *Sender)
{
    if (ListBox1->ItemIndex>=0)
    {
        Memo1->Lines->Clear();
        AnsiString S=ListBox1->Items->Strings[ListBox1->ItemIndex];
        char *p=S.c_str();

        while (*p)
        {
            if (
                (*p>='A'&&*p<='Z')||
                (*p>='a'&&*p<='z')||
                (*p>='0'&&*p<='9')||
                *p=='_')
                p++;
            else
            {
                S="["+S+"]";
                break;
            }
        }

        Memo1->Lines->Add("SELECT * FROM "+S);
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox2DblClick(TObject *Sender)
{
    if (ListBox2->ItemIndex>=0)
    {
        AnsiString S=ListBox2->Items->Strings[ListBox2->ItemIndex];
        char *p=S.c_str();

        while (*p)
        {
            if (
                (*p>='A'&&*p<='Z')||
                (*p>='a'&&*p<='z')||
                (*p>='0'&&*p<='9')||
                *p=='_')
                p++;
            else
            {
                S="["+S+"]";
                break;
            }
        }

        if (Memo1->SelStart<=0||Memo1->Text.SubString(Memo1->SelStart,1).Trim().IsEmpty())
            Memo1->SelText=S;
        else
            Memo1->SelText=","+S;
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
    Button1->Align=alTop;
    Button2->Align=alRight;
    edtConStr->Align = alBottom;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::COUNT1Click(TObject *Sender)
{
    TMenuItem *mi=dynamic_cast<TMenuItem*>(Sender);
    AnsiString S;

    if (ListBox2->ItemIndex>=0)
        S="("+ListBox2->Items->Strings[ListBox2->ItemIndex]+")";
    else
        S="()";

    Memo1->SelText=mi->Caption+S;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
    TMenuItem *mi=dynamic_cast<TMenuItem*>(Sender);
    Memo1->SelText=mi->Hint;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1DblClick(TObject *Sender)
{
    auto_ptr<Tfm_Blob> fb(new Tfm_Blob(this));
    fb->DS=DataSource1;
    fb->Fieldname=DBGrid1->SelectedField->FieldName;
    fb->Field=DBGrid1->SelectedField;
    fb->FreePage();

    switch (DBGrid1->SelectedField->DataType)
    {

    case ftMemo:
        fb->DBMemo1->DataSource=DataSource1;
        fb->DBMemo1->DataField=DBGrid1->SelectedField->FieldName;
        fb->PageControl1->ActivePageIndex=1;
        break;

    case ftFmtMemo:
        fb->DBRichEdit1->DataSource=DataSource1;
        fb->DBRichEdit1->DataField=DBGrid1->SelectedField->FieldName;
        fb->PageControl1->ActivePageIndex=2;
        break;

    case ftParadoxOle:

    case ftDBaseOle:
        fb->DBRichEdit2->DataSource=DataSource1;
        fb->DBRichEdit2->DataField=DBGrid1->SelectedField->FieldName;
        fb->PageControl1->ActivePageIndex=3;
        break;

    case ftTypedBinary:

    case ftBlob:
        fb->DBMemo2->DataSource=DataSource1;
        fb->DBMemo2->DataField=DBGrid1->SelectedField->FieldName;
        fb->PageControl1->ActivePageIndex=4;
        break;

    case ftGraphic:
        fb->DBImage1->DataSource=DataSource1;
        fb->DBImage1->DataField=DBGrid1->SelectedField->FieldName;
        fb->PageControl1->ActivePageIndex=0;
        break;

    default:
//                        if(fb->Visible) fb->Close();
        return;
    }

    fb->ShowModal();

}

//---------------------------------------------------------------------------
