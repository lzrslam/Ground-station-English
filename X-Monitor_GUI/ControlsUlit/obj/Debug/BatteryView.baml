   M S B A M L   `   `   `  ����  ControlsUnit    ControlsUnit.BatteryView   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5        � 	Resources  5       �� 
TargetType   ProgressBarSize �� Property �� Value  RectangleProgressBar �� 
TargetType �� CornerRadius ��Name �� RadiusX �� RadiusY��%;  &	        &	 �     �� 5
      " �6
   .�5      ��  � ��$	 100��6   �� 5       � ��$	 100��6   �� 5       � ��$ 	10,0,0,10q�6   5      �� 5      " �6
   .�5      ��  � �� 5      �� 5      " �6   .R�5      � .+�5   	   �� $��
PART_Track��6   $ 1��6"   $��1q�64   #��z��5   !   #��z��5   !   � 5   	   $��PART_Indicator��6   $
��Left=�6$   .+�5   
   �� $ prgBackground��6   $��0q�6+   $ 1��66   $ 1��6B   #��z��5   (   5   
   5   	   5      5      5       5!      .��5$      �� -   5        $��ControlsUnitBorder��5$   
   
�������$ 0��68   $��1q�6I   ._�5%      � .+�5&      �� $��Battery��6   $
��Left=�6   $��41��68   $	��Top=�6D   $	��105��6\   $��	Meiryo UI)�6h   $��24(�6   	 J� RenderTransformOrigin$	 0.505,0.772&�6�   $��
-3,-5,-2,0q�6�   
�������$
��Bold"�6�   �� 5'      $
��Left=�6   $	��Top=�6&   $��0,35,0,0q�6>   $��Resources/battery.png��6P   � 5)      -   5        $��ProBar��5)      $
��Left=�6   $��44��6:   $	��Top=�6F   $��70��6^   $��9,44,0,0q�6i   #��[ 6{   
��� � �
���������6�   Z� �� 5*      -   5        $��BatVal��5*      $
��Left=�6   $��36��64   $	��Top=�6@   $��68��6X   $��	Meiryo UI)�6c   $��18(�6z   $	 0.505,0.772&�6�   $��	11,48,0,0q�6�   ���	#FFF6BD06$��Center=�6�   $��Center=�6�   $
��Bold"�6  5+      5,      5-      