   M S B A M L   `   `   `  ����   ControlsUnit    ControlsUnit.MapZoom   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     @d2http://schemas.microsoft.com/expression/blend/2008     .���   � ColumnDefinitions  �� $��50 ��� $��50 ��� $��50 � � RowDefinitions �� $	��450 ��� $��50 �.+��� -   $��slider��$��0��$��1��$��Right=�$��Stretch=�$
��Zoom��
�������
�������$y�Hidden=�.��� .+��� -    ��Name$ 
ZoomSlider�� � Maximum$ 24Q� � Minimum$ 10Q� �� Orientation$ Vertical=�$��Center=�$��Stretch=� �� TickPlacement$
 Both=�$��	0,10,0,10q� � SmallChange$ 1Q����	#FFFFF9F9�� -   $��ZoomBtn��$��1��$��1��
������� �� CornerRadius$ 0��$��1q�	 J� Opacity$		 0.9Q�._��� -   $��30(�$��Center=�$��Center=����� 
 �� ImageSource$$
 Resources/suofangzhongjian.png�� j� Stretch$ Uniform=��� -   $��smallBtn��$��2��$��1��
�������$ 0��$��1q�$		 0.9Q�._��� -   $��PlusBtn��$��30(�$��Center=�$��Center=����� $
 Resources/suoxiao.png��$ Uniform=��� -   $��bigBtn��$��0��$��1��
�������$ 0��$��1q�$		 0.9Q�._��� -   $��MinusBtn��$��30(�$��Center=�$��Center=����� $
 Resources/fangda.png��$ Uniform=�