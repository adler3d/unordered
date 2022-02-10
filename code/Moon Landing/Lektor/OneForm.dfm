object eXForm: TeXForm
  Left = 191
  Top = 106
  BiDiMode = bdLeftToRight
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'eXForm'
  ClientHeight = 566
  ClientWidth = 792
  Color = 9655085
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clYellow
  Font.Height = -13
  Font.Name = 'Comic Sans MS'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  ParentBiDiMode = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnMouseWheel = FormMouseWheel
  DesignSize = (
    792
    566)
  PixelsPerInch = 96
  TextHeight = 18
  object XBox: TPanel
    Left = 8
    Top = 8
    Width = 777
    Height = 465
    Cursor = crCross
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvNone
    Color = clBlack
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clYellow
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnMouseDown = XBoxMouseDown
    OnMouseUp = XBoxMouseUp
  end
  object UserBox: TPanel
    Left = 8
    Top = 480
    Width = 777
    Height = 81
    Anchors = [akLeft, akRight, akBottom]
    Color = clBlack
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clYellow
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    DesignSize = (
      777
      81)
    object lbTex: TLabel
      Left = 8
      Top = 32
      Width = 57
      Height = 18
      Anchors = [akLeft, akBottom]
      Caption = 'Texture :'
    end
    object sbClear: TSpeedButton
      Left = 688
      Top = 32
      Width = 81
      Height = 17
      Anchors = [akRight, akBottom]
      BiDiMode = bdLeftToRight
      Caption = 'Clear'
      Flat = True
      Layout = blGlyphBottom
      ParentShowHint = False
      ParentBiDiMode = False
      ShowHint = False
      Spacing = 100
      OnClick = sbClearClick
    end
    object sbOpen: TSpeedButton
      Left = 512
      Top = 32
      Width = 81
      Height = 17
      Anchors = [akRight, akBottom]
      BiDiMode = bdLeftToRight
      Caption = 'Open'
      Flat = True
      Layout = blGlyphBottom
      ParentShowHint = False
      ParentBiDiMode = False
      ShowHint = False
      Spacing = 100
      OnClick = sbOpenClick
    end
    object sbSave: TSpeedButton
      Left = 600
      Top = 32
      Width = 81
      Height = 17
      Anchors = [akRight, akBottom]
      BiDiMode = bdLeftToRight
      Caption = 'Save'
      Flat = True
      Layout = blGlyphBottom
      ParentShowHint = False
      ParentBiDiMode = False
      ShowHint = False
      Spacing = 100
      OnClick = sbSaveClick
    end
    object lbMap: TLabel
      Left = 8
      Top = 8
      Width = 70
      Height = 18
      Anchors = [akLeft, akBottom]
      Caption = 'Map Name :'
    end
    object BoxTex: TComboBox
      Left = 88
      Top = 32
      Width = 129
      Height = 20
      BevelInner = bvNone
      BevelOuter = bvNone
      Style = csSimple
      Anchors = [akLeft, akBottom]
      BiDiMode = bdLeftToRight
      Color = clMaroon
      Ctl3D = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clYellow
      Font.Height = -11
      Font.Name = 'Comic Sans MS'
      Font.Style = []
      ItemHeight = 15
      ParentBiDiMode = False
      ParentCtl3D = False
      ParentFont = False
      Sorted = True
      TabOrder = 0
      TabStop = False
      Text = 'BLA-BLA'
      OnDblClick = BoxTexEnter
    end
    object BoxInfo: TPanel
      Left = 8
      Top = 56
      Width = 761
      Height = 20
      Anchors = [akLeft, akRight, akBottom]
      Color = clBlack
      TabOrder = 1
      DesignSize = (
        761
        20)
      object lbZoom: TLabel
        Left = 3
        Top = 2
        Width = 52
        Height = 15
        Anchors = [akLeft, akBottom]
        Caption = 'Zoom [1:1]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object lbPosition: TLabel
        Left = 163
        Top = 2
        Width = 97
        Height = 15
        Anchors = [akBottom]
        Caption = 'Position [X:0 | Y:0]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object lbMPos: TLabel
        Left = 376
        Top = 2
        Width = 130
        Height = 15
        Anchors = [akBottom]
        Caption = 'Mouse Position[X:0 | Y:0]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object lbNumMesh: TLabel
        Left = 656
        Top = 2
        Width = 87
        Height = 15
        Anchors = [akRight, akBottom]
        Caption = 'Number Mesh[-1]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
    end
    object edMapName: TEdit
      Left = 88
      Top = 8
      Width = 129
      Height = 20
      Anchors = [akLeft, akBottom]
      AutoSize = False
      BevelInner = bvNone
      BevelOuter = bvNone
      Color = clMaroon
      Ctl3D = True
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clYellow
      Font.Height = -11
      Font.Name = 'Comic Sans MS'
      Font.Style = []
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 2
      Text = 'Noname'
    end
  end
  object Timer_eX: TTimer
    Interval = 10
    OnTimer = Timer_eXTimer
    Left = 720
    Top = 16
  end
  object TimerRender: TTimer
    Interval = 15
    OnTimer = TimerRenderTimer
    Left = 752
    Top = 16
  end
  object sd: TSaveDialog
    OnClose = fdClose
    OnShow = fdShow
    DefaultExt = '.ASD'
    Filter = 'ASD File|*.ASD'
    Left = 688
    Top = 16
  end
  object od: TOpenDialog
    OnClose = fdClose
    OnShow = fdShow
    DefaultExt = '.ASD'
    Filter = 'ASD File|*.ASD'
    Left = 688
    Top = 48
  end
  object PopupMenu: TPopupMenu
    AutoPopup = False
    OnPopup = PopupMenuPopup
    Left = 16
    Top = 16
    object NTex: TMenuItem
      Caption = 'Set Texture'
      Enabled = False
      OnClick = NTexClick
    end
    object NInvNormal: TMenuItem
      Caption = 'Inversion Normal'
      Enabled = False
      OnClick = NInvNormalClick
    end
    object NNUL_Con: TMenuItem
      Caption = 'Control'
      object NBringF: TMenuItem
        Caption = 'Bring to Front'
        OnClick = NBringFClick
      end
      object NBringB: TMenuItem
        Caption = 'Bring to Back'
        OnClick = NBringBClick
      end
    end
    object NNul3: TMenuItem
      Caption = '-'
    end
    object NAddBot: TMenuItem
      Caption = 'New Bot'
    end
    object NNul: TMenuItem
      Caption = '-'
    end
    object NStart: TMenuItem
      Caption = 'Set Start'
      OnClick = NStartClick
    end
    object NFinish: TMenuItem
      Caption = 'Set Finish'
      OnClick = NFinishClick
    end
    object NNul2: TMenuItem
      Caption = '-'
    end
    object NDel: TMenuItem
      Caption = 'Delete'
      Enabled = False
      OnClick = NDelClick
    end
  end
end
