   M S B A M L   `   `   `  ����  ControlsUnit    ControlsUnit.MapZoom   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      .��5      �   � ColumnDefinitions  5   
   �� 5	      $��50 �6   �� 5
      $��50 �6   �� 5      $��50 �6    � RowDefinitions 5   
   �� 5      $	��450 �6   �� 5      $��50 �6   .+�5   
   �� -   5        $��slider��5      $��0��6!   $��1��6.   $��Right=�6>   $��Stretch=�6Z   $
��Zoom��6v   
�������
�������$y�Hidden=�6�   .��5      � .+�5      �� -   5         ��Name$ 
ZoomSlider��5       � Maximum$ 24Q�6-    � Minimum$ 10Q�6:    �� Orientation$ Vertical=�6G   $��Center=�6^   $��Stretch=�6{    �� TickPlacement$
 Both=�6�   $��	0,10,0,10q�6�    � SmallChange$ 1Q�6�   ���	#FFFFF9F96�   5      5      �� 5   
   -   5        $��ZoomBtn��5      $��1��6    $��1��60   
������� �� CornerRadius$ 0��6Q   $��1q�6b   	 J� Opacity$		 0.7Q�6v   ._�5      �� -   5        $��30(�5      $��Center=�6#   $��Center=�6G   ��5      �� 5      
 �� ImageSource$
 Resources/zoom.png��6!    j� Stretch$ Uniform=�6B   5      5       �� 5"   
   -   5        $��PlusBtn��5"      $��+��6    
�������
�������$��2��6S   $��1��6c   $��36(�6p   $��Center=�6~   $��Center=�6�   ��6�   Z� �� 5#   
   -   5        $��MinusBtn��5#      $��-��6!   
�������
�������$��0��6T   $��1��6d   $��36(�6q   $��Center=�6   $��Center=�6�   ��6�   Z� 5%      5&      