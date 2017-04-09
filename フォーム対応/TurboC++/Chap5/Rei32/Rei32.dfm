object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 203
  ClientWidth = 331
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 8
    Top = 48
    Width = 177
    Height = 33
  end
  object Edit1: TEdit
    Left = 8
    Top = 8
    Width = 49
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Button1: TButton
    Left = 63
    Top = 8
    Width = 57
    Height = 25
    Caption = 'push'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 126
    Top = 8
    Width = 57
    Height = 25
    Caption = 'pop'
    TabOrder = 2
    OnClick = Button2Click
  end
end
