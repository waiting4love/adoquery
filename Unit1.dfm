object Form1: TForm1
  Left = 209
  Top = 154
  Caption = 'ADOQuery Express'
  ClientHeight = 573
  ClientWidth = 840
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  DesignSize = (
    840
    573)
  PixelsPerInch = 120
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 476
    Width = 840
    Height = 78
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    TabOrder = 0
    object Memo1: TMemo
      Left = 1
      Top = 1
      Width = 764
      Height = 76
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alClient
      ScrollBars = ssVertical
      TabOrder = 0
      OnKeyDown = Memo1KeyDown
    end
    object Button2: TButton
      Left = 765
      Top = 1
      Width = 74
      Height = 76
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alRight
      Caption = #25191#34892
      Enabled = False
      TabOrder = 1
      OnClick = SpeedButton1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 840
    Height = 476
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 1
    object Panel3: TPanel
      Left = 669
      Top = 1
      Width = 170
      Height = 474
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alRight
      Caption = 'Panel3'
      TabOrder = 0
      object Splitter1: TSplitter
        Left = 1
        Top = 286
        Width = 168
        Height = 4
        Cursor = crVSplit
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alBottom
        ExplicitTop = 231
      end
      object ListBox1: TListBox
        Left = 1
        Top = 32
        Width = 168
        Height = 254
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        ItemHeight = 15
        TabOrder = 0
        OnClick = ListBox1Click
        OnDblClick = ListBox1DblClick
      end
      object ListBox2: TListBox
        Left = 1
        Top = 290
        Width = 168
        Height = 183
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alBottom
        ItemHeight = 15
        TabOrder = 1
        OnDblClick = ListBox2DblClick
      end
      object Button1: TButton
        Left = 1
        Top = 1
        Width = 168
        Height = 31
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alTop
        Caption = #36830#25509#25968#25454#24211'...'
        TabOrder = 2
        OnClick = SpeedButton2Click
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 668
      Height = 474
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alClient
      Caption = 'Panel4'
      TabOrder = 1
      object DBGrid1: TDBGrid
        Left = 1
        Top = 1
        Width = 666
        Height = 440
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        DataSource = DataSource1
        TabOrder = 0
        TitleFont.Charset = ANSI_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -15
        TitleFont.Name = #23435#20307
        TitleFont.Style = []
        OnDblClick = DBGrid1DblClick
      end
      object DBNavigator1: TDBNavigator
        Left = 1
        Top = 441
        Width = 666
        Height = 32
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataSource = DataSource1
        Align = alBottom
        Flat = True
        TabOrder = 1
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 554
    Width = 840
    Height = 19
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Panels = <
      item
        Width = 100
      end
      item
        Text = 'Ready!'
        Width = 50
      end>
    SimpleText = 'Ready!'
  end
  object edtConStr: TEdit
    Left = 40
    Top = 648
    Width = 849
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Anchors = [akLeft, akRight, akBottom]
    Color = clBtnFace
    Ctl3D = False
    ParentCtl3D = False
    ReadOnly = True
    TabOrder = 3
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    MaxRecords = 1000
    Parameters = <>
    SQL.Strings = (
      'select * from ReturnLoss')
    Left = 72
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 112
    Top = 8
  end
  object PopupMenu1: TPopupMenu
    Left = 176
    Top = 8
    object Select1: TMenuItem
      Caption = #25968#25454#26816#32034
      Hint = 'SELECT first, last, city FROM empinfo WHERE first LIKE '#39'Er%'#39'; '
      OnClick = N4Click
    end
    object CreateTable1: TMenuItem
      Caption = #21019#24314#34920
      Hint = 
        'CREATE TABLE employee(first varchar(15),last varchar(20),age num' +
        'ber(3),address varchar(30),city varchar(20),state varchar(20));'
      OnClick = N4Click
    end
    object N1: TMenuItem
      Caption = #25554#20837#25968#25454
      Hint = 
        'INSERT INTO employee(first, last, age, address, city) VALUES ('#39'Z' +
        'hang'#39','#39'Weiguo'#39',28,'#39'SIP601'#39','#39'SuZhou'#39'); '
      OnClick = N4Click
    end
    object N2: TMenuItem
      Caption = #21024#38500#34920
      Hint = 'DROP TABLE employee;'
      OnClick = N4Click
    end
    object N3: TMenuItem
      Caption = #26356#26032#35760#24405
      Hint = 
        'UPDATE employee SET age = age+1 WHERE first_name='#39'Mary'#39' and last' +
        '_name='#39'Williams'#39';'
      OnClick = N4Click
    end
    object N4: TMenuItem
      Caption = #21024#38500#35760#24405
      Hint = 'DELETE FROM employee;'
      OnClick = N4Click
    end
    object N5: TMenuItem
      AutoHotkeys = maManual
      Caption = #21512#35745#20989#25968
      object MIN1: TMenuItem
        Caption = 'MIN'
        OnClick = COUNT1Click
      end
      object MAX1: TMenuItem
        Caption = 'MAX'
        OnClick = COUNT1Click
      end
      object SUM1: TMenuItem
        Caption = 'SUM'
        OnClick = COUNT1Click
      end
      object AVG1: TMenuItem
        Caption = 'AVG'
        OnClick = COUNT1Click
      end
      object COUNT1: TMenuItem
        Caption = 'COUNT'
        OnClick = COUNT1Click
      end
    end
  end
  object ADOConnection1: TADOConnection
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 32
    Top = 8
  end
end
