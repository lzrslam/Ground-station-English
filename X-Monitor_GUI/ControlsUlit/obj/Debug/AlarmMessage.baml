   M S B A M L   `   `   `  ����  ControlsUnit    ControlsUnit.AlarmMessage   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      .��5      � -   5        $
��grid��5   !   $	��100��6   $	��450��6   $
��Left=�6-   $	��Top=�6H     � ColumnDefinitions  5	      �� 5
      $��80 �6   �� 5      $��* �6   �� 5      $��90 �6    � RowDefinitions 5      �� 5      $��* �6   �� 5      $��* �6   �� 5      $��30 �6   .+�5      � -   5        $��
AlarmColor��5      $��3��6   $��3��62    � Points �    5  �  5  �� Stretch$
 Fill=�6g   $	��Top=�6v   ��5      �� 5       �� Color$
 Gold��6    �� Opacity$	 0.5Q�6#   5      �� 5      $��0��6   $��2��6   .+�5      �� $��Resources/Alarm.png��6   $��70��6(   $��80��64   �� 5      -   5         ��Name$ 
AlarmState��5      $��	Emergency��6   
�������$��	Meiryo UI)�6F   $��12(�6]   $
��Bold"�6k   
 �� Top$ 45��6}   5      �� 5      -   5        $��AlarmMessage0��5   /   $��1��6   $��2��6   $��Message��6D   
�������$��	Meiryo UI)�6f   $��12(�6}   $
��Bold"�6�   $
��Wrap=�6�   {�.  6�   �� 5      -   5        $��AlarmMessage1��5   /   $��2��6   $��2��6"   $T��N健全度がより劣化しないか注意しながら運用して下さい。��6D   
�������$��	Meiryo UI)�6y   $��13(�6�   $
��Bold"�6�   $��20��6�   $
��Wrap=�6�    �� TextAlignment$ Center=�6�   5      5      