   M S B A M L   `   `   `  ����   	Y-Planner'    !Y_Planner.Option.AltitudeProperty   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089` \RibbonControlsLibrary, Version=3.5.41019.1, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     @d2http://schemas.microsoft.com/expression/blend/2008     X TXceed.Wpf.Toolkit, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f44xctk)http://schemas.xceed.com/wpf/xaml/toolkit    � 	Resources     templateActHome �� 
TargetType � ColumnDefinitions ]� DecreaseRepeatButton ]� IncreaseRepeatButton ]� Thumb �� ImageSource j� Stretch j� TileMode  ActHomeStyle	 �� 
TargetType
 �� Property �� Value  templateActAlt m� 	Placement m� Fill �� CornerRadius �� Triggers P� Property P� Value �� 
TargetName  ActAltStyle��%�  &	        &	     7   &	 �    &	 Y    7  �� " ��.R��� #��z��#��z��#��z��._��  �� $��10 ��� $��40 �.+�]� $��
PART_Track��$��1�� �� $��Slider.DecreaseLarge����.  |�.  ���� .R��� 
������  �� $��Slider.IncreaseLarge����.  |�.  ���� .R��� 
������  n� $��15������ .R��� ���� $- '/Y-Planner;component/Resources/home.png��$ Uniform=�$
 None=��� "	 ��.��� 
 �@��Orientation$ Vertical=��� 
 � ��8   �� " ��.R��� #��z��#��z��#��z��._��  �� $��10 ��� $��40 �.+�m� $��LeftTick��$��0��$��10��$
 Left=�$y�	Collapsed=�# z��m� $��	RightTick��$��0��$��10��$ Right=�$y�	Collapsed=�# z���� $��0��$��2��$��	26 0 18 0q�$ 2 2 2 2��
���   �$��1q�
��� ���]� $��
PART_Track��$��1�� �� $��Slider.DecreaseLarge����.  |�.  ���� .R��� 
������  �� $��Slider.IncreaseLarge����.  |�.  ���� .R��� 
������  n� $��15������ .R��� ���� $- '/Y-Planner;component/Resources/uav2.png��$ Uniform=�$
 None=� P�  �@��TickPlacement$ TopLeft=�. ��� $ LeftTick��
 � y�$ Visible=�P�  �@��TickPlacement$ BottomRight=�. ��� $ 	RightTick��
 � y�$ Visible=�P�  �@��TickPlacement$
 Both=�. ��� $ LeftTick��
 � y�$ Visible=��� $ 	RightTick��
 � y�$ Visible=��� "	 ��.��� 
 �@��Orientation$ Vertical=��� 
 � ��8   .��� .+��� $
��Auto=�$
��Auto=�.��� $
��Left=�$	��Top=� �� $	��120 ��� $��* � � RowDefinitions �� $��* �.+��� $��0��.+��� 
 �� Top$ 0�� �� Left$ 5��$��机体���� -   $
��Home��$ 20��#��[  �� Orientation$ Vertical=�$	��200�� � SmallChange$ 1Q� �� TickPlacement$ TopLeft=� �� TickFrequency$ 10Q�{�.   � Maximum ��  �� ElementName$
 _Max�� �� Path$ Value� � Minimum �� $
 _Min��$ Value��� -   $	��UAV��$ 20��#��[ $ Vertical=�$	��200��$ 1Q�$ TopLeft=�$ 10Q�{�.   �� $
 _Max��$ Value� �� $
 _Min��$ Value��� $	 222��$ 1��$��20��$��20������ $- '/Y-Planner;component/Resources/uav3.png��$ Uniform=��� $	 244��$ 3��$��15��$��15������ $. (/Y-Planner;component/Resources/home2.png��$ Uniform=��� $	 220��$ 15������ $	 UAV��$ Value��� $	 240��$ 15������ $
 Home��$ Value��� -   $��Check��$ 4��$ 60��$	��ALL���� -   $��	AllSlider��$ 20��$ 65��$ Vertical=�$	��200��$ 1Q�$ TopLeft=�$ 10Q� �� $
 _Max��$ Value� �� $
 _Min��$ Value�{��� $ Check��$ 	IsChecked��� $	 220��$ 65������ $ 	AllSlider��$ Value��� $	 280��$ 1��$��高度制限���� $	 310��$ 5�� �� Orientation$ 
Horizontal=�.+��� $��最大��$��10,0,0,0q�$  Xceed.Wpf.Toolkit.DoubleUpDown  -   $
��_Max��$��50���  �Xceed.Wpf.Toolkit.Primitives.UpDownBase`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   Value$	 150X�$��1q�    Maximum$
  5000X�!   Minimum$! -5000X��  �Xceed.Wpf.Toolkit.NumericUpDown`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]"   	Increment$" 10X��� $	 340��$ 5��$ 
Horizontal=�.+��� $��最小��$��10,0,3,0q�  -   $
��_Min��$��50��$ 0X�$��1q�$
  5000X�$! -5000X�$" 10X��� $��按下��$��75��$	 264���� -   $��canvas1��$��1��$��20���� $��0�����	#FFDDDDDD$	��0.5q��� $��1�����	#FFDDDDDD$	��0.5q�