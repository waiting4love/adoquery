//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "blob.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfm_Blob *fm_Blob;
TMenuItem *Bt4;
void Tfm_Blob::FreePage(void)
{
        DBMemo1->DataField="";
        DBRichEdit1->DataField="";
        DBRichEdit2->DataField="";
        DBMemo2->DataField="";
        DBImage1->DataField="";
        DBMemo1->DataSource=NULL;
        DBImage1->DataSource=NULL;
        DBMemo2->DataSource=NULL;
        DBRichEdit2->DataSource=NULL;
        DBRichEdit1->DataSource=NULL;
}
//---------------------------------------------------------------------------
__fastcall Tfm_Blob::Tfm_Blob(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
AnsiString ccharset(TFontCharset Charset)
{
        AnsiString csetstr;
        switch(Charset)
        {
                case DEFAULT_CHARSET: csetstr="Default charset";  break;
                case GB2312_CHARSET: csetstr="Simplified Chinese";  break;
                case ANSI_CHARSET: csetstr="ANSI characters";  break;
                case SYMBOL_CHARSET: csetstr="Standard symbol" ;  break;
                case CHINESEBIG5_CHARSET: csetstr="Traditional Chinese";  break;
                case SHIFTJIS_CHARSET: csetstr="Japanese shift-JIS";  break;
                case HANGEUL_CHARSET: csetstr="Korean characters (Wansung)";  break;
                case JOHAB_CHARSET: csetstr="Korean characters (Johab)";  break;
                case EASTEUROPE_CHARSET: csetstr="Eastern European";  break;
                case OEM_CHARSET: csetstr="OEM characters";  break;
                case GREEK_CHARSET: csetstr="Greek characters";  break;
                default : csetstr="Other";
        }
        return csetstr;
}
//---------------------------------------------------------------------------
TFontCharset chr2str(int csetstr)
{
        TFontCharset Charset;
        switch(csetstr)
        {
                case 0: Charset=DEFAULT_CHARSET; break;
                case 1: Charset=GB2312_CHARSET; break;
                case 2: Charset=ANSI_CHARSET; break;
                case 3 : Charset=SYMBOL_CHARSET; break;
                case 4: Charset=CHINESEBIG5_CHARSET; break;
                case 5: Charset=SHIFTJIS_CHARSET; break;
                case 6: Charset=HANGEUL_CHARSET; break;
                case 7: Charset=JOHAB_CHARSET; break;
                case 8: Charset=EASTEUROPE_CHARSET; break;
                case 9: Charset=OEM_CHARSET; break;
                case 10: Charset=GREEK_CHARSET; break;
                default : Charset=GB2312_CHARSET; break;
        }
        return Charset;
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::FormClose(TObject *Sender, TCloseAction &Action)
{
        FreePage();
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::PageControl1Change(TObject *Sender)
{
   //if(MessageDlg("强制使用其他查看方式可能会破坏数据,除非你有把握,否则不要轻易切换,有把握吗?", mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0)==mrNo) return;
   try{
        FreePage();
        switch(PageControl1->ActivePageIndex)
        {
                case 0:
                        DBImage1->DataSource=DS;
                        DBImage1->DataField=Fieldname;
                        break;
                case 1:
                        DBMemo1->DataSource=DS;
                        DBMemo1->DataField=Fieldname;
                        break;
                case 2:
                       DBRichEdit1->DataSource=DS;
                       DBRichEdit1->DataField=Fieldname;
                       break;
                case 3:
                        DBRichEdit2->DataSource=DS;
                        DBRichEdit2->DataField=Fieldname;
                        break;
                case 4:
                        DBMemo2->DataSource=DS;
                        DBMemo2->DataField=Fieldname;
                        break;
        }
       }
       catch(...)
       {
                //OpChild->Table1->Cancel();
                DS->DataSet->Cancel();
       }
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::Button1Click(TObject *Sender)
{
        AnsiString ofn;
/*        if(OpChild->ROnly)
        {
                ShowMessage("在只读方式下不能编辑数据库!");
                return;
        }
*/
        if(Field->DataType==ftGraphic)
        {
                if(!OpenPictureDialog1->Execute())  return;
                ofn=OpenPictureDialog1->FileName;
        }
        else
        {
                if(!OpenDialog1->Execute()) return;
                ofn=OpenDialog1->FileName;
        }
        FreePage();
        //OpChild->Table1->Edit();
        DS->DataSet->Edit();
        switch(Field->DataType)
        {
                case ftMemo:
                            ((TMemoField*)Field)->LoadFromFile(ofn);
                            DBMemo1->DataSource=DS;
                            DBMemo1->DataField=Fieldname;
                            PageControl1->ActivePageIndex=1;
                            break;
                case ftFmtMemo:
                            ((TMemoField*)Field)->LoadFromFile(ofn);
                            DBRichEdit1->DataSource=DS;
                            DBRichEdit1->DataField=Fieldname;
                            PageControl1->ActivePageIndex=2;
                            break;
                case ftParadoxOle:
                case ftDBaseOle:
                            ((TBlobField*)Field)->LoadFromFile(ofn);
                            DBRichEdit2->DataSource=DS;
                            DBRichEdit2->DataField=Fieldname;
                            PageControl1->ActivePageIndex=3;
                            break;
                case ftTypedBinary:
                case ftBlob:
                            ((TBlobField*)Field)->LoadFromFile(ofn);
                            DBMemo2->DataSource=DS;
                            DBMemo2->DataField=Fieldname;
                            PageControl1->ActivePageIndex=4;
                            break;
                case ftGraphic:
                            ((TGraphicField*)Field)->LoadFromFile(ofn);
                            DBImage1->DataSource=DS;
                            DBImage1->DataField=Fieldname;
                            PageControl1->ActivePageIndex=0;
                            break;
        }
        //OpChild->Table1->Post();
        DS->DataSet->Post();
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::Button2Click(TObject *Sender)//导出
{
        AnsiString sfn;
        if(Field->DataType==ftGraphic)
        {
                if(!SavePictureDialog1->Execute())  return;
                sfn=SavePictureDialog1->FileName;
        }
        else
        {
                if(!SaveDialog1->Execute()) return;
                sfn=SaveDialog1->FileName;
        }
        FreePage();
        switch(Field->DataType)
        {
                case ftMemo:
                            ((TMemoField*)Field)->SaveToFile(sfn);
                            DBMemo1->DataSource=DS;
                            DBMemo1->DataField=Fieldname;
                            PageControl1->ActivePageIndex=1;
                            break;
                case ftFmtMemo:
                            ((TMemoField*)Field)->SaveToFile(sfn);
                            DBRichEdit1->DataSource=DS;
                            DBRichEdit1->DataField=Fieldname;
                            PageControl1->ActivePageIndex=2;
                            break;
                case ftParadoxOle:
                case ftDBaseOle:
                            ((TBlobField*)Field)->SaveToFile(sfn);
                            DBRichEdit2->DataSource=DS;
                            DBRichEdit2->DataField=Fieldname;
                            PageControl1->ActivePageIndex=3;
                            break;
                case ftTypedBinary:
                case ftBlob:
                            ((TBlobField*)Field)->SaveToFile(sfn);
                            DBMemo2->DataSource=DS;
                            DBMemo2->DataField=Fieldname;
                            PageControl1->ActivePageIndex=4;
                            break;
                case ftGraphic:
                            ((TGraphicField*)Field)->SaveToFile(sfn);
                            DBImage1->DataSource=DS;
                            DBImage1->DataField=Fieldname;
                            PageControl1->ActivePageIndex=0;
                            break;
        }
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::FormCreate(TObject *Sender)
{
        ComboBox1->Clear();
        ComboBox1->Items=Screen->Fonts;
        ComboBox1->ItemIndex=0;
        ComboBox2->ItemIndex=1;
        ComboBox3->ItemIndex=0;
        Bt4=N1;
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::ComboBox1Change(TObject *Sender)
{
        //if(OpChild->Table1->State!=dsEdit&&OpChild->Table1->State!=dsInsert)OpChild->Table1->Edit();
        if(DS->DataSet->State!=dsEdit&&DS->DataSet->State!=dsInsert)DS->DataSet->Edit();
        DBRichEdit1->SelAttributes->Name=ComboBox1->Items->Strings[ComboBox1->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::ComboBox2Change(TObject *Sender)
{
        int fsize;
        try{
                fsize=ComboBox2->Text.ToInt();
        }
        catch(...)
        {
                fsize=9;
        }
        //if(OpChild->Table1->State!=dsEdit&&OpChild->Table1->State!=dsInsert)OpChild->Table1->Edit();
        if(DS->DataSet->State!=dsEdit&&DS->DataSet->State!=dsInsert)DS->DataSet->Edit();
        DBRichEdit1->SelAttributes->Size=fsize;
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::DBRichEdit1SelectionChange(TObject *Sender)
{
        bool enabled=true;
        //enabled=!OpChild->ROnly;
        ComboBox1->Enabled=enabled;
        ComboBox2->Enabled=enabled;
        ComboBox3->Enabled=enabled;
        ToolButton4->Enabled=enabled;
        ComboBox1->ItemIndex=ComboBox1->Items->IndexOf(DBRichEdit1->SelAttributes->Name);
        ComboBox2->Text=IntToStr(DBRichEdit1->SelAttributes->Size);
        ComboBox3->ItemIndex=ComboBox3->Items->IndexOf(ccharset(DBRichEdit1->SelAttributes->Charset));
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::ComboBox3Change(TObject *Sender)
{
        if(DS->DataSet->State!=dsEdit&&DS->DataSet->State!=dsInsert)DS->DataSet->Edit();
        DBRichEdit1->SelAttributes->Charset=chr2str(ComboBox3->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::PopupMenu1Popup(TObject *Sender)
{
        N1->Checked=DBRichEdit1->SelAttributes->Style.Contains(fsBold);
        N2->Checked=DBRichEdit1->SelAttributes->Style.Contains(fsItalic);
        N3->Checked=DBRichEdit1->SelAttributes->Style.Contains(fsUnderline);
        N6->Checked=DBRichEdit1->Paragraph->Alignment==taLeftJustify;
        N7->Checked=DBRichEdit1->Paragraph->Alignment==taCenter;
        N8->Checked=DBRichEdit1->Paragraph->Alignment==taRightJustify;
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::N1Click(TObject *Sender)
{
        TMenuItem *fontitem;
        TFontStyles style;
        fontitem=dynamic_cast<TMenuItem *>(Sender);
        if(!fontitem)return;
        fontitem->Checked=!fontitem->Checked;
        style.Clear();
        if(N1->Checked) style << fsBold;
        if(N2->Checked) style << fsItalic;
        if(N3->Checked) style << fsUnderline;
        if(DS->DataSet->State!=dsEdit&&DS->DataSet->State!=dsInsert)DS->DataSet->Edit();
        DBRichEdit1->SelAttributes->Style = style;
        Bt4=fontitem;
        ToolButton4->ImageIndex=Bt4->ImageIndex;
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::N6Click(TObject *Sender)
{
        TMenuItem *pgitem;
        pgitem=dynamic_cast<TMenuItem*>(Sender);
        if(!pgitem)return;
        pgitem->Checked=!pgitem->Checked;
        if(DS->DataSet->State!=dsEdit&&DS->DataSet->State!=dsInsert)DS->DataSet->Edit();
        if(N6->Checked)DBRichEdit1->Paragraph->Alignment=taLeftJustify;
        if(N7->Checked)DBRichEdit1->Paragraph->Alignment=taCenter;
        if(N8->Checked)DBRichEdit1->Paragraph->Alignment=taRightJustify;
        Bt4=pgitem;
        ToolButton4->ImageIndex=Bt4->ImageIndex;
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::ToolButton4Click(TObject *Sender)
{
        PopupMenu1Popup(NULL);
        Bt4->OnClick(Bt4);
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::N4Click(TObject *Sender)
{
        if(ColorDialog1->Execute())
        {
                if(DS->DataSet->State!=dsEdit&&DS->DataSet->State!=dsInsert)DS->DataSet->Edit();
                DBRichEdit1->SelAttributes->Color=ColorDialog1->Color;
        }
        Bt4=N4;
        ToolButton4->ImageIndex=Bt4->ImageIndex;
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::DBImage1DblClick(TObject *Sender)
{
        DBImage1->Stretch=!DBImage1->Stretch;
}
//---------------------------------------------------------------------------
void __fastcall Tfm_Blob::FormShow(TObject *Sender)
{
	DataSetNext1->DataSource=DS;
        DataSetPrior1->DataSource=DS;
}
//---------------------------------------------------------------------------

