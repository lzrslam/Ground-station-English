   M S B A M L   `   `   `  ����   	X-Monitor     XMonitor_GUI.MessageWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     -     � Title$  MessageWindow��$	��420��$	��500�� � Icon$/ )/X-Monitor;component/Resources/minisv.ico��   WindowBackgroundBrush#���    � WindowStyle$
 None=� � WindowStartupLocation$ CenterScreen=� � 	Resources  �� Source�� $ ../MainWindowStyles.xaml?�%    '  !System.Windows.Shell.WindowChrome   WindowChrome      CaptionHeight$ 50Q�   ResizeBorderThickness$ 5q�.��� 	 � ColumnDefinitions	 �� $��5 ��� $��* ��� $��* ��� $��5 �
 � RowDefinitions
 �� $��5 ��� $��50 ��� $��* ��� $��50 ��� $��5 �.+��� $��1��$��1��$��信息��$
��Left=�$	��Top=�
�������$��32(�$��	Meiryo UI)�$
��Bold"��� $��2��$��1�� �� Orientation$ 
Horizontal=�$��Right=�$	��Top=�$��50��$��37��.+��� -   $��r��  CaptionButtonStyleKey#���  $��32(�
��������� $��2��$��1��$��2��$��5q�.+��� $��更新��$
��Left=�$	��Top=�
�������$��24(�$��	Meiryo UI)��� -   $��
UpdataText��$	��100�� �� AcceptsReturn .  �� TextWrapping$
 Wrap=�" �� VerticalScrollBarVisibility$
 Auto=��� $��通知��$
��Left=�$	��Top=�
�������$��24(�$��	Meiryo UI)��� -   $��MessageText��$	��100�� . $
 Wrap=�$
 Auto=��� -   $��1��$��3��$��下次更新不显示��
�������$��16(�$
��Left=�$��Center=��� $��2��$��3��$ 
Horizontal=�$��Center=�$��Right=�.+��� -   $��OK��$��18(�$	��100��
�������
�������
���   �$��	Meiryo UI)�$��5q�