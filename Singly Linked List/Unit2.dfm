object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 431
  ClientWidth = 642
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label5: TLabel
    Left = 56
    Top = 8
    Width = 31
    Height = 13
    Caption = 'Label5'
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 642
    Height = 431
    ActivePage = TabSheet5
    Align = alClient
    TabOrder = 0
    OnChange = PageControl1Change
    ExplicitTop = 8
    object TabSheet1: TTabSheet
      Caption = 'Singly linked list'
      object Label1: TLabel
        Left = 31
        Top = 32
        Width = 45
        Height = 13
        Caption = 'Element :'
      end
      object Label2: TLabel
        Left = 31
        Top = 72
        Width = 42
        Height = 13
        Caption = 'Target : '
      end
      object Label3: TLabel
        Left = 32
        Top = 117
        Width = 16
        Height = 13
        BiDiMode = bdLeftToRight
        Caption = 'n : '
        ParentBiDiMode = False
      end
      object Label4: TLabel
        Left = 102
        Top = 117
        Width = 41
        Height = 13
        Caption = 'Range : '
      end
      object Edit1: TEdit
        Left = 96
        Top = 29
        Width = 65
        Height = 21
        TabOrder = 0
        Text = '10'
      end
      object Edit2: TEdit
        Left = 96
        Top = 69
        Width = 65
        Height = 21
        TabOrder = 1
        Text = '10'
      end
      object Button1: TButton
        Left = 200
        Top = 27
        Width = 75
        Height = 25
        Caption = 'Insert as first'
        TabOrder = 2
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 296
        Top = 27
        Width = 75
        Height = 25
        Caption = 'Insert as last'
        TabOrder = 3
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 200
        Top = 67
        Width = 75
        Height = 25
        Caption = 'Find target'
        TabOrder = 4
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 296
        Top = 67
        Width = 98
        Height = 25
        Caption = 'Find_Insertafter'
        TabOrder = 5
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 408
        Top = 67
        Width = 98
        Height = 25
        Caption = 'Find_Insertbefore'
        TabOrder = 6
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 528
        Top = 67
        Width = 75
        Height = 25
        Caption = 'Find_Delete'
        TabOrder = 7
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 200
        Top = 112
        Width = 137
        Height = 25
        Caption = 'Insert n random numbers'
        TabOrder = 8
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 360
        Top = 112
        Width = 105
        Height = 25
        Caption = 'Clear list'
        TabOrder = 9
        OnClick = Button8Click
      end
      object Edit3: TEdit
        Left = 54
        Top = 114
        Width = 33
        Height = 21
        TabOrder = 10
        Text = '10'
      end
      object Edit4: TEdit
        Left = 149
        Top = 114
        Width = 33
        Height = 21
        TabOrder = 11
        Text = '100'
      end
      object PageControl2: TPageControl
        Left = 0
        Top = 160
        Width = 634
        Height = 243
        ActivePage = TabSheet4
        Align = alBottom
        TabOrder = 12
        object TabSheet4: TTabSheet
          Caption = 'Linked list output'
          object Memo1: TMemo
            Left = 0
            Top = 0
            Width = 626
            Height = 215
            Align = alClient
            Lines.Strings = (
              'Memo1')
            TabOrder = 0
          end
        end
      end
      object Button13: TButton
        Left = 488
        Top = 112
        Width = 115
        Height = 25
        Caption = 'Reverse the list'
        TabOrder = 13
        OnClick = Button13Click
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'Linked Queue'
      ImageIndex = 3
      object Label7: TLabel
        Left = 47
        Top = 48
        Width = 45
        Height = 13
        Caption = 'Element :'
      end
      object PageControl3: TPageControl
        Left = 0
        Top = 96
        Width = 634
        Height = 307
        ActivePage = TabSheet9
        Align = alBottom
        TabOrder = 0
        object TabSheet9: TTabSheet
          Caption = 'Linked queue output'
          ImageIndex = 2
          object Memo6: TMemo
            Left = 0
            Top = 0
            Width = 626
            Height = 279
            Align = alClient
            Lines.Strings = (
              'Memo3')
            TabOrder = 0
          end
        end
      end
      object Edit6: TEdit
        Left = 112
        Top = 45
        Width = 65
        Height = 21
        TabOrder = 1
        Text = '10'
      end
      object Button11: TButton
        Left = 344
        Top = 43
        Width = 75
        Height = 25
        Caption = 'Delete Queue'
        TabOrder = 2
        OnClick = Button11Click
      end
      object Button12: TButton
        Left = 232
        Top = 43
        Width = 75
        Height = 25
        Caption = 'Add Queue'
        TabOrder = 3
        OnClick = Button12Click
      end
      object Button20: TButton
        Left = 456
        Top = 43
        Width = 97
        Height = 25
        Caption = 'Reverse Queue'
        TabOrder = 4
        OnClick = Button20Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Linked Stack'
      ImageIndex = 2
      object Label6: TLabel
        Left = 39
        Top = 40
        Width = 45
        Height = 13
        Caption = 'Element :'
      end
      object Label8: TLabel
        Left = 104
        Top = 85
        Width = 3
        Height = 13
      end
      object PageControl4: TPageControl
        Left = 0
        Top = 136
        Width = 634
        Height = 267
        ActivePage = TabSheet11
        Align = alBottom
        TabOrder = 0
        object TabSheet11: TTabSheet
          Caption = 'Linked Stack output'
          ImageIndex = 1
          object Memo8: TMemo
            Left = 0
            Top = 0
            Width = 626
            Height = 239
            Align = alClient
            Lines.Strings = (
              'Memo2')
            TabOrder = 0
          end
        end
      end
      object Edit5: TEdit
        Left = 104
        Top = 37
        Width = 65
        Height = 21
        TabOrder = 1
        Text = '10'
      end
      object Button9: TButton
        Left = 232
        Top = 35
        Width = 75
        Height = 25
        Caption = 'Push'
        TabOrder = 2
        OnClick = Button9Click
      end
      object Button10: TButton
        Left = 344
        Top = 35
        Width = 75
        Height = 25
        Caption = 'Pop'
        TabOrder = 3
        OnClick = Button10Click
      end
      object Edit7: TEdit
        Left = 39
        Top = 82
        Width = 121
        Height = 21
        TabOrder = 4
        Text = 'Edit7'
      end
      object Button19: TButton
        Left = 232
        Top = 80
        Width = 187
        Height = 25
        Caption = 'Reverse Stack'
        TabOrder = 5
        OnClick = Button19Click
      end
    end
    object TabSheet13: TTabSheet
      Caption = 'Concatenate'
      ImageIndex = 3
      object PageControl5: TPageControl
        Left = 0
        Top = 200
        Width = 634
        Height = 203
        ActivePage = TabSheet2
        Align = alBottom
        TabOrder = 0
        object TabSheet2: TTabSheet
          Caption = 'Concatenate output'
          object Memo2: TMemo
            Left = 0
            Top = 0
            Width = 626
            Height = 175
            Align = alClient
            Lines.Strings = (
              'Memo2')
            TabOrder = 0
          end
        end
      end
      object GroupBox1: TGroupBox
        Left = 28
        Top = 24
        Width = 205
        Height = 154
        Caption = 'List 1'
        TabOrder = 1
        object Label9: TLabel
          Left = 38
          Top = 34
          Width = 13
          Height = 13
          Caption = 'n :'
        end
        object Label12: TLabel
          Left = 38
          Top = 72
          Width = 41
          Height = 13
          Caption = 'Range : '
        end
        object Edit8: TEdit
          Left = 100
          Top = 23
          Width = 65
          Height = 21
          TabOrder = 0
          Text = '10'
        end
        object Button14: TButton
          Left = 24
          Top = 112
          Width = 141
          Height = 23
          Caption = 'Insert n random numbers'
          TabOrder = 1
          OnClick = Button14Click
        end
        object Edit9: TEdit
          Left = 100
          Top = 69
          Width = 65
          Height = 21
          TabOrder = 2
          Text = '10'
        end
      end
      object GroupBox2: TGroupBox
        Left = 260
        Top = 24
        Width = 205
        Height = 154
        Caption = 'List 2'
        TabOrder = 2
        object Label10: TLabel
          Left = 38
          Top = 34
          Width = 13
          Height = 13
          Caption = 'n :'
        end
        object Label11: TLabel
          Left = 38
          Top = 72
          Width = 41
          Height = 13
          Caption = 'Range : '
        end
        object Edit10: TEdit
          Left = 100
          Top = 23
          Width = 65
          Height = 21
          TabOrder = 0
          Text = '10'
        end
        object Edit11: TEdit
          Left = 100
          Top = 69
          Width = 65
          Height = 21
          TabOrder = 1
          Text = '10'
        end
        object Button15: TButton
          Left = 24
          Top = 112
          Width = 145
          Height = 25
          Caption = 'Insert n random numbers'
          TabOrder = 2
          OnClick = Button15Click
        end
      end
      object Button16: TButton
        Left = 512
        Top = 91
        Width = 75
        Height = 25
        Caption = 'Concatenate'
        TabOrder = 3
        OnClick = Button16Click
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Separate'
      ImageIndex = 4
      object Label16: TLabel
        Left = 406
        Top = 184
        Width = 224
        Height = 13
        Caption = '\\  Please insert new number after separate  //'
      end
      object PageControl6: TPageControl
        Left = 0
        Top = 200
        Width = 634
        Height = 203
        ActivePage = TabSheet6
        Align = alBottom
        TabOrder = 0
        ExplicitLeft = 16
        ExplicitTop = 159
        object TabSheet6: TTabSheet
          Caption = 'Separate Output'
          object Memo3: TMemo
            Left = 0
            Top = 0
            Width = 626
            Height = 175
            Align = alClient
            Lines.Strings = (
              'Memo3')
            TabOrder = 0
            ExplicitLeft = 224
            ExplicitTop = 40
            ExplicitWidth = 185
            ExplicitHeight = 89
          end
        end
      end
      object GroupBox3: TGroupBox
        Left = 28
        Top = 24
        Width = 205
        Height = 154
        Caption = 'List 1'
        TabOrder = 1
        object Label13: TLabel
          Left = 38
          Top = 29
          Width = 13
          Height = 13
          Caption = 'n :'
        end
        object Label14: TLabel
          Left = 38
          Top = 72
          Width = 41
          Height = 13
          Caption = 'Range : '
        end
        object Edit12: TEdit
          Left = 100
          Top = 26
          Width = 65
          Height = 21
          TabOrder = 0
          Text = '10'
        end
        object Edit13: TEdit
          Left = 100
          Top = 69
          Width = 65
          Height = 21
          TabOrder = 1
          Text = '10'
        end
        object Button17: TButton
          Left = 24
          Top = 112
          Width = 145
          Height = 25
          Caption = 'Insert n random numbers'
          TabOrder = 2
          OnClick = Button17Click
        end
      end
      object GroupBox4: TGroupBox
        Left = 256
        Top = 24
        Width = 209
        Height = 154
        Caption = 'GroupBox4'
        TabOrder = 2
        object Label15: TLabel
          Left = 39
          Top = 34
          Width = 42
          Height = 13
          Caption = 'Target : '
        end
        object Edit14: TEdit
          Left = 104
          Top = 26
          Width = 65
          Height = 21
          TabOrder = 0
          Text = '10'
        end
        object RadioButton1: TRadioButton
          Left = 39
          Top = 112
          Width = 130
          Height = 17
          Caption = 'Target as last'
          TabOrder = 1
          OnClick = RadioButton1Click
        end
        object RadioButton2: TRadioButton
          Left = 39
          Top = 71
          Width = 130
          Height = 17
          Caption = 'Target as first'
          TabOrder = 2
          OnClick = RadioButton2Click
        end
      end
      object Button18: TButton
        Left = 512
        Top = 91
        Width = 75
        Height = 25
        Caption = 'Separate'
        TabOrder = 3
        OnClick = Button18Click
      end
    end
  end
end
