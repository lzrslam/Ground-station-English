   M S B A M L   `   `   `  ����   ControlsUnit    ControlsUnit.AlarmMessage   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     @d2http://schemas.microsoft.com/expression/blend/2008     .��� -   $
��grid��$��88��$	��389��$
��Left=�$	��Top=�  � ColumnDefinitions  �� $��80 ��� $��* ��� $��90 � � RowDefinitions �� $��* ��� $��* ��� $��30 �.+�� -   $��
AlarmColor��$��3��$��3�� � Points �    5  �  5  �� Stretch$
 Fill=�$	��Top=�����  �� Color$
 Gold�� �� Opacity$	 0.5Q��� $��0��$��2��.+��� $��Resources/Alarm.png��$��70��$��80���� -    ��Name$ 
AlarmState��$��	Emergency��
�������$��	Meiryo UI)�$��12(�$
��Bold"�
 �� Top$ 45���� -   $��AlarmMessage0��$��1��$��2��$��Message��
�������$��	Meiryo UI)�$��12(�$
��Bold"�$
��Wrap=�{�.  �� -   $��AlarmMessage1��$��2��$��2��$-��'通信强度减弱，请注意使用。��
�������$��	Meiryo UI)�$��13(�$
��Bold"�$��20��$
��Wrap=� �� TextAlignment$ Center=�