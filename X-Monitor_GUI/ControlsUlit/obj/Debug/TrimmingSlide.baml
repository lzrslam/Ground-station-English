   M S B A M L   `   `   `  ����X  TXceed.Wpf.Toolkit, Version=2.2.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4P:clr-namespace:Xceed.Wpf.Toolkit;assembly=Xceed.Wpf.ToolkitXceed.Wpf.Toolkit  5       ControlsUnit    ControlsUnit.TrimmingSlide   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      Kxctk:clr-namespace:Xceed.Wpf.Toolkit;assembly=Xceed.Wpf.Toolkit     5      -   5        $��TrimmingSlideControl��5      $��80��5      $	��800��6     � 	Resources  5       �� Source�� 5   
   $ TrimmingSlideStyles.xaml?�6   %    .��5      � .+�5   
   �� -   5        $��_Time��5      $��0:0.0��6   
�������$	��100��6@   $��Center=�6L   $
��Left=�6o   $
��Left=�6�   $��Center=�6�   $��0,5,0,50q�6�   �� 5   
   -   5        $��
_TotalTime��5      $
��time��6"   
�������$	��100��6D   $��Center=�6P   $��Right=�6s   $��Center=�6�   $��Right=�6�   $��0,5,0,50q�6�   �� 5   
   -   5         ��Name$ _PlaySlider��5   "   $��0��6   $��25��67    �� Orientation$ 
Horizontal=�6�    � Maximum$	 100Q�6�    � SmallChange$ 1Q�6�   ��6D   ��  �� ElementName$ TrimmingSlideControl�� �� Path$ Width�6�   #   Xceed.Wpf.Toolkit.RangeSlider  5   
   -   5          Name$ _RangeSlider��5      	   Step$	 1Q�5      $��20��5!         HigherRangeStyle3
   HigherRangeStyle#
 [  5"        RangeStyle3   
RangeStyle# [ 5#        LowerRangeStyle3   LowerRangeStyle# [ 5$      $��Bottom=�5%   �   $��Center=�6�   $��0,0,0,12q�6�   ��5       �� $ TrimmingSlideControl��$ Width�5%   �   5,      5.      