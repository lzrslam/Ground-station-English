   M S B A M L   `   `   `  ����   	X-Monitor     XMonitor_GUI.SettingWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     -     � Title$  SettingWindow��$	��540��$	��550�� � Icon$0 */X-Monitor;component/Resources/minisv3.ico��   WindowBackgroundBrush#���    � WindowStyle$
 None=� � WindowStartupLocation$ CenterScreen=�$	��540��$	��550�� � 	Resources  �� Source�� $ ../MainWindowStyles.xaml?�%    '  !System.Windows.Shell.WindowChrome   WindowChrome      CaptionHeight$ 50Q�   ResizeBorderThickness$ 5q�.��� 	 � ColumnDefinitions	 �� $��5 ��� $��* ��� $��* ��� $��5 �
 � RowDefinitions
 �� $��5 ��� $��50 ��� $��* ��� $��50 ��� $��5 �.+��� $��1��$��1��$��Settings��$
��Left=�$	��Top=�
�������$��32(�$��	Meiryo UI)�$
��Bold"��� $��2��$��1�� �� Orientation$ 
Horizontal=�$��Right=�$	��Top=�$��50��$��37��.+��� -   $��r��  CaptionButtonStyleKey#���  $��32(�
��������� $��2��$��1��$��2��
�������.@��� $��Maintenance Settings��
�������
�������.��� 	 �� $��* �
 �� $��60 ��� $��60 ��� $��* �.+��� $��1��$��0��$��Maintenance Time：��.���� $ 
Horizontal=�$��Center=�$
��Left=� J� OpacityMask
 ����� �� Left$ 10��
 �� Top$ 11��$��
76,0,-2,-3q�$	��436��$��41��.+��� $��0,9,0,3q�$��Time Setting：���� -   $��
M_Text_Set��$��36��$��64��$��0,10,0,5q��� $��0,9,0,1q�$
��Hour���� -   $��Maintain_Success_Btn��$��Maintenance Complete��$��15(�$	��184��
���   �$��5,5,5,5q��� $��0��$��1��$��Work Information：��.���� $ 
Horizontal=�$��1��$��2��$	��Top=�$
��Left=�$ 10��$ 34���� $��Option Settings��
�������
�������.��� 	 �� $��* �
 �� $��* �.+��� $��0��$��0��$��	Show/Hide��.���� -   $��OptionViwer��  MyContainer#��[  �� SelectionMode$ Multiple=�����  
 Option �� Source# [  �� XPath$
 view�� �� View �� .P���   	FirstCell �� CellTemplate# [  �� Width$ 30���� $��No��$ 30�� �� DisplayMemberBinding �� $	 @No���� $
��Name��$	 100�� �� $ @Name���� $��Function��$	 280�� �� $ 	@function���� $��Map Settings��
�������
�������.��� 	 �� $��* �
 �� $��* �.+��� $��0��$��0��$��Map Setting��$��2��.��� 	 �� $��* �
 �� $��40 ��� $��40 ��� $��* �.+��� $��0��$	��445��$��30��$ 
Horizontal=�$
��Left=�.+��� $��30,0,5,0q�$	��Lat��$��32���� -   $��LatText��$��32.0103691272��$	��165��$��Center=�$��Center=��� $��10,0,5,0q�$	��Lng��$��32���� -   $��LngText��$��118.7828039246��$	��165��$��Center=�$��Center=��� $��1��$	��445��$��30��$ 
Horizontal=�$
��Left=�.+��� $��15,0,5,0q�$
��Name���� -   $��AddressText��$�� ��$	��165��$��Center=�$��Center=��� -	   $��
AddressRec��$��	  Login  ��$��15,1,1,1q��� -
   $��
AddressDel��$��	  Clear  ��$��5,1,1,1q��� -   $��
  选择  ��$y�Hidden=�$��5,1,1,1q��� -    ��Name$ AddressListView��$��2��$��2q�$ Single=� �� .P��� $
��Name��$	 150�� ��  �� Path$
 Name��� $	��Lat��$	 120�� �� $	 Lat��� $	��Lng��$	 120�� �� $	 Lng��� $��Plant/Aerial��
�������
�������.��� 	 �� $��* �
 �� $��* �.+��� $��0��$��0��$)��#Switch The View Of Plant And Aerial��$��2��.��� 	 �� $��* �
 �� $��40 ��� $��40 ��� $��* �.+��� $��0��$	��445��$��30��$ 
Horizontal=�$��Center=�.+��� .+�	� -    	�Name$ zhibao_style��$��Plant Model�� 	� 	GroupName$ group1��	� -   $ hangpai_style��$��Aerial Model��$ group1���� $��1��$��3��$ 
Horizontal=�$��Center=�$
��Left=�.+��� -   $��	初始化��$y�Hidden=�$��18(�$	��100��
�������
�������
���   �$��	Meiryo UI)�$��5q��� $��2��$��3��$ 
Horizontal=�$��Center=�$��Right=�.+��� -   $��OK��$��18(�$	��100��
�������
�������
���   �$��	Meiryo UI)�$��5q��� -   $��Cancel��$��18(�$	��100��
�������
�������
���   �$��	Meiryo UI)�$��10,5,5,5q�