   M S B A M L   `   `   `  ���� c  _GMap.NET.WindowsPresentation, Version=1.7.0.0, Culture=neutral, PublicKeyToken=b85b9027b614afefqPclr-namespace:GMap.NET.WindowsPresentation;assembly=GMap.NET.WindowsPresentationGMap.NET.WindowsPresentation  [ WSystem.Windows.Forms, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089Y@clr-namespace:System.Windows.Forms;assembly=System.Windows.FormsSystem.Windows.Forms G CControlsUnit, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullA0clr-namespace:ControlsUnit;assembly=ControlsUnitControlsUnit D @X-Monitor, Version=1.2.1.4, Culture=neutral, PublicKeyToken=nullG(clr-namespace:XMonitor_GUI.CustomMarkersXMonitor_GUI.CustomMarkers 9!clr-namespace:XMonitor_GUI.WindowXMonitor_GUI.Window [ WHelixToolkit.Wpf, Version=2014.2.11.1, Culture=neutral, PublicKeyToken=52aa3500039caf0dM8clr-namespace:HelixToolkit.Wpf;assembly=HelixToolkit.WpfHelixToolkit.Wpf B >WPF.MDI, Version=1.1.1.0, Culture=neutral, PublicKeyToken=null2&clr-namespace:WPF.MDI;assembly=WPF.MDIWPF.MDI M ISystem, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089A-clr-namespace:System.IO.Ports;assembly=SystemSystem.IO.Ports O Kmscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e0891&clr-namespace:System;assembly=mscorlibSystem    XMonitor_GUI.MainWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^	 ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R
 NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation  	 
  R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml   
  ;metro)http://schemas.codeplex.com/elysium/theme   
  `mapPclr-namespace:GMap.NET.WindowsPresentation;assembly=GMap.NET.WindowsPresentation   
  Y UDynamicDataDisplay, Version=0.3.0.0, Culture=neutral, PublicKeyToken=5b7d744a7263923f?plot4http://research.microsoft.com/DynamicDataDisplay/1.0  Lforms@clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms  >control0clr-namespace:ControlsUnit;assembly=ControlsUnit  5marker(clr-namespace:XMonitor_GUI.CustomMarkers  .window!clr-namespace:XMonitor_GUI.Window  Dhelix8clr-namespace:HelixToolkit.Wpf;assembly=HelixToolkit.Wpf  0mdi&clr-namespace:WPF.MDI;assembly=WPF.MDI  8port-clr-namespace:System.IO.Ports;assembly=System  0sys&clr-namespace:System;assembly=mscorlib  :d2http://schemas.microsoft.com/expression/blend/2008  Dmc;http://schemas.openxmlformats.org/markup-compatibility/2006  -     �Name$  Main_Window��$	��720��$
��1280�� � Icon$ Resources/minisv3.ico��   WindowBackgroundBrush#���    � WindowStyle$ SingleBorderWindow=�$	��720��$	��780�� � WindowStartupLocation$ CenterScreen=� � 	Resources  �� Source�� $ MainWindowStyles.xaml?�%    '  !System.Windows.Shell.WindowChrome   WindowChrome      CaptionHeight$ 50Q�   ResizeBorderThickness$ 5q�.��� 	 � ColumnDefinitions	 �� $��20 ��� $
��440* ��� $��20 �
 � RowDefinitions
 �� $��10 ��� $��50 ��� $
��348* ��� $��10 �.+�.   (GMap.NET.WindowsPresentation.GMapControl  -     Name$ MainMap��   MaxZoom$ 24��   MinZoom$ 0��   Zoom$ 17Q� J� RenderTransformOrigin$ 0.5,0.5&�$��4��$��-362,-555,-418,-585q�$��3��   	ScaleMode$ Dynamic=��� -    ��Name$ 	Copyright��$��	Copyright��$��21��$��1��$��2�����	#FF1F1A50$��8(�$��Bottom=�$��Bottom=�� $��2��$��1��	 �� $	��100 ��� -    ��Name$ 	BaseWidth��$��* ��� $��10 ��� -   $ 
BaseColumn��$	��250 �$	��150��
 �� $	��100 ��� $��* ��� $��10 ��� -    ��Name$ BaseRow��$	��250 ��� -   $ 
BaseHeight��$	��100 �.+��� -    ��Name$ LeftsideArea��$��5������  �� Color$ White�� �� Opacity$ 0Q��� -	   $ TopArea��$��4������ $ White��$ 0Q��� -
   $ RightsideArea��$��3��$��4��$��	27,67,0,0q�$��1������ $ White��$ 0Q��� $��4��$��4������ $ White��$ 0Q�(� $��4��$��0��$
��Left=� (� StretchDirection$ DownOnly=�$	��Top=�$
��1252��.����  �� Orientation$ 
Horizontal=�$
��Left=�$	��Top=�$	��100��$
��1385��.+�  ControlsUnit.TimerView  -     Name$ 	TimerName��  CanvasBackgroundBrush#���  $	��Top=�$��0��"  ControlsUnit.ControlModeView  -     Name$ ControlModeName��#���  $	��105��  ControlsUnit.LinkView  -     Name$ LinkName��   ValueMax$	 100��   ValueMin$ 0��#���   � DataContext ��   Data �� Source# [   �� XPath$
  Data��!   	LinkValue! �� $
  Link��  ControlsUnit.GPSView  -   "  Name$" GPSName��#   ValueMax$# 48��$   ValueMin$$ 0��#���   �� # [ $
  Data��%   GPSValue% �� $	  GPS��  ControlsUnit.BatteryView  -   &  Name$& BatteryName��'   ValueMax$' 12Q�(   ValueMin$( 0Q�#���   �� # [ $
  Data��)   BatteryValue) �� $  BatteryVoltage��!  ControlsUnit.FlightModeView  -   *  Name$* FlightModeName��#���   �� # [ $
  Data��+   Text+ �� $  Flight��	  ControlsUnit.RCrecView	  -   , 	 Name$, 	RCrecName��- 	  ValueMax$	- 100��. 	  ValueMin$. 0��#���  $ 0.5,0.5&�$��1�� �� # [ $
  Data��/ 	  
RCrecValue/ �� $  RC��z�V� .~��� 0 �� ScaleX$0 -1Q��� �� T� 
  ControlsUnit.Height_Show
  -   1 
 Name$1 HeightModelName��#���  $	��106��  ControlsUnit.SpeedView  -   2  Name$2 	SpeedName��#���  $	��106��  ControlsUnit.Totol_Flow  -   3  Name$3 TotolFlowName��#���  $	��106��  ControlsUnit.Current_Flow  -   4  Name$4 CurrentFlowRateName��#���  $	��106���� $��0,2,0,0q�$ Vertical=�$��1��$ 0.5,0.5&�z�V� .~��� $0 -1Q��� �� T� .+��� $��	Serial：�����	#FFF1EAEA#���  $��2,2,2,20q�$��27��$
��Bold"��� $��Baud：�����	#FFF1EAEA#���  $��	2,13,2,20q�$��27��$
��Bold"�(� $��0��$��1��$��4��$
��Left=�$	��Top=�.��  ControlsUnit.UAVAltitude  -   5  Name$5 Altitude��$
��Left=�$	��Top=�#���  $ 0.5,0.5&�$��1��$y�Hidden=�z�V� .~��� $0 -1Q��� �� T� %  ControlsUnit.DropDownMenuButton  $��2��$��2��$	��Top=�
�������
�������$��50��$	��150��$��Right=�#���  6   DropDownContextMenu6 �� .@�m� -   7 m�Name$7 OpenFlightPlan��$��20(�$��Open Flight Plan���� �� m� -   $��20(�$��
Setting(S)��m� -   $��20(�$��About(A)���� m� -   $��20(�$��End(E)��.���� $ 
Horizontal=�.+��� $��SetInfo��$��34(�$��	Meiryo UI)�F� $��25��$��20��8 �� Stretch$
8 Fill=�+����on �>�`�� $� � $�  $� Ѱon �>���� *
Foreground+9 �� RelativeSource9 �� *FindAncestor+: �� AncestorType":  �� $��3��$��Bottom=�$ 
Horizontal=�$��Right=�.+��� -   $ 
MarkerIcon��$
��Left=�$��50��$	��Top=�$��50��$��2��
�������; J� OpacityMask; �� < �� ImageSource$!< Resources/shubiaodianji.png���� -   $ 	TouchIcon��$
��Left=�$��50��$	��Top=�$��50��$��2��
��������� -   $ SettingIcon��$
��Left=�$��50��$	��Top=�$��50��$��2��
�������; �� $< Resources/shezhi.png���� -   = ��Name$= GridLine��$��1��$��1��$��3��
�������> �� CornerRadius$> 0��$	��0.5q�._��� -   $ canvas��? J� SnapsToDevicePixels? . $��1,0,-1,0q�� -    @ �Name$@ Arrow��$��1��$��1��$��40��$	��250��$	��Top=�$��Right=�	 �� $��* ��� $��50 �
 �� $��* �.+�� -!   $@ DisArrow��$��1��$��Center=�$��Right=�$��50��.+��� -"   A ��Name$
A Dis1��
�������$��2��	B �� X1$B 0��	C �� Y1$C 8��	D �� Y2$D 8��	E �� X2E �� *Width+F �� ElementName$F DisArrow���� -#   $
A Dis2��$��4��$B 2��$C 0��$E 2��$D 16������ *Stroke+$
F Dis1���� -$   $
A Dis3��$��4��$��Right=�$B 0��$C 0��$E 0��$D 16������ *Stroke+$
F Dis1���� -%   $ DisName��$��0��$	��dis��$��40��$	��180��$��24(�$	��Top=�$��Right=�$��Right=�$��Center=�
���������Z� �� $.��(/X-Monitor;component/Resources/charu.png��$��2��$��128,40,0,-50q�(� $��1��$��4��$��2��$��Center=�$ DownOnly=�$��Bottom=�.���� -&   G ��Name$G 
back_color��$ 
Horizontal=�$��Center=�$��0q�$��Bottom=�$	��896������ $ #1b393f��$	 0.9Q�.+��� $ Vertical=�$��0��$	��100��$	��Top=�$ 0.5,0.5&�z�V� .~��� $0 -1Q��� �� T� .+��� -'   H ��Name$H cmbPortName��
�������#���  
���2͚�$��71��$��0,5,0,40q����� *Port.PortNames+�� -(   $H cmbBaudRate��
�������#���  
���2͚�$��71���� $ Vertical=�$��0��$��95��$	��Top=�$��0,5,0,0q�$ 0.5,0.5&�.+�d� -)   I d�Name$I btnOpenPort��J d� 	IsChecked$J FalseY�$��24��#���  
�������$ -0.283,0.254&����� K �� 
TargetType"K d�L �� TriggersL P� M P� PropertyM �@d�	IsCheckedN P� Value$
N TrueY�. ��� O �� PropertyO � ��P �� Value$P 关闭串口��P� M �@d�	IsChecked$N FalseY�. ��� O � ��$P 打开串口���� -*   Q ��Name$Q zuoyuan��#���  |�.  $��	Meiryo UI)�$��18(�$
��Bold"�$��2q�$��50��$	��100��$��Center=�$��Center=�.���� $.��(/X-Monitor;component/Resources/right.png���� -+   $��banjingwrite��$��0,5,0,0q�$ Vertical=�$	��100��$ 0.502,0.718&�.+��� -,   $ line_one��
�������$��1,-6.5,-11,0q�$��2��$ 0.5,0.5&�z�V� .~��� $0 -1Q��� �� T� �� $ 
Horizontal=�.+��� --   $ shijain��$��18(�$
��Bold"�$��2q�$��0��
�������$��Center=�$��Center=�$��35��$y�Visible=�$ 0.5,0.5&�$��67���� -.   $ pesabanjingtitle��$��16(�$
��Bold"�$��2q�$��s��
�������$��Center=�$��Center=�$��35��$y�Visible=�$ 0.5,0.5&�$��46���� -/   $H 
Show_Index��$��Center=�$��Center=�R �� Text$R 5��$��22(�
�������#���  $��
10,15,10,0q�
���2͚�$��30���� 
�������$��
0,11,-11,0q�$��2��$ 0.5,0.5&�z�V� .~��� S �� ScaleY$S -1Q�$0 -1Q��� �� T� �� -0   $Q 	jizhunset��|�.  T � ToolTip$T New Plan��$��	Meiryo UI)�$��18(�$
��Bold"�$��2q�#���  
�������$	��New��$	��100��$��	0,0,-33,0q�$y�Visible=�$	��100���� -1   $Q dandianshanchu��|�.  $T Delete One Waypoint��$��	Meiryo UI)�$��18(�$
��Bold"�$��2q�#���  
�������$��Delete��$	��100��$��32,0,-112,0q�$y�Visible=�$	��100���� -2   $Q fanganshengcheng��|�.  $T Generate Track��$��	Meiryo UI)�$��18(�$
��Bold"�$��2q�#���  
�������$
��Make��$	��100��$��0��$y�Visible=��� -3   $Q fanganbaocun��|�.  $T Save Into C:\\AutoWing��$��	Meiryo UI)�$��18(�$
��Bold"�$��2q�#���  
�������$
��Save��$	��100��$	��100��$��110,0,-112,0q�$y�Visible=��� -4   $Q ludianshangchuan��|�.  $T Upload The Mission��$��	Meiryo UI)�$��18(�$
��Bold"�$��2q�#���  
�������$��Waypoint��$	��100��$	��100��$��110,0,-112,0q�$y�Visible=��� -5   $Q guijiqingchu��|�.  $T Track Clear��$��	Meiryo UI)�$��18(�$
��Bold"�$��2q�#���  
�������$��Clear��$	��100��$	��100��$��110,0,-112,0q�$y�Visible=��� -6   $Q ludianxiugai��$T Start Collect Waypoints��|�.  #���  
�������$��	Meiryo UI)�$��18(�$
��Bold"�$��OpenColl��$	��100��$	��100��$��110,0,-73,0q�$y�Visible=�"  ControlsUnit.RotateAzimuthal  -7   U  Name$U 	MapRotate��#���  $	��100��$y�Visible=�$��74,0,0,0q��� -8   $Q youyuan��#���  |�.  $��	Meiryo UI)�$��18(�$
��Bold"�$��2q�$��55��$	��100��.���� $-��'/X-Monitor;component/Resources/left.png���� -9   $ PosSet��$��WaypointSet��$��96��$��1��
�������$��	Meiryo UI)�$��18(�$
��Bold"�#���  
�������$��Center=�$��Center=�$��1q�V �� IsPressAndHoldEnabledV .  $y�Hidden=��� -:   $ User4��$��User4��$��97��$��0��
�������$��	Meiryo UI)�$��18(�$
��Bold"�#���  
�������$��Center=�$��Center=�$��1q�V .  $y�Hidden=��� -;   $ PosSpd��$��Speed��$	��100��$��0��
�������$��	Meiryo UI)�$��18(�$
��Bold"�#���  
�������$��Center=�$��Center=�$��2q�V .  �� -<   $ PosClear��$��Clear��$	��100��$��0��
�������$��	Meiryo UI)�$��18(�$
��Bold"�#���  
�������$��Center=�$��Center=�$��2q�V .  �� $��Label��  WPF.MDI.MdiContainer  -=   W  Name$W 	Container��$��3��$��1��$��4��X   Theme$
X Luna=�$��
10,32,0,50q���Z� Y � ContextMenuY �� ->   Z ��Name$Z cm��$y�Visible=�.@�m� -?   $��The Window Of WayPoints��m� -@   $��The Window Of Chart��m� -A   $��The Window Of Camera��m� -B   $��The Window Of 3D Model��m� -C   $��The Window Of Version��m� -D   $��The Window Of Light��m� -E   $��The Window Of Wifi��m� -F   $��The Window Of Index��m� -G   $#��The Window Of Plan Finetuning��m� -H   $��The Window Of AP Code��m� -I   $��The Window Of IMU Data���� m� -J   $��Cascade��m� -K   $��
Horizontal��m� -L   $��Vertical���� m� -M   $��Close All Window���� -N   [ ��Name$[ OptionGridSplitter��$��2��$��1��$��3��\ �� ResizeDirection$\ Columns=�$��Stretch=����� $ White��$ 0Q�  ControlsUnit.MapZoom  -O   ]  Name$] ZoomName��$��3��$��1��$��4��$��Right=�$��Bottom=�^   ZoomBackground$^ 	#FF1F1A50��_   ZoomMinimum$_ 1Q�`   ZoomMaximum$` 20Q�$	��447��a   Valuea �� *Zoom+$F MainMap��  ControlsUnit.AlarmMessage  -P   b  Name$b AlertMessageName��$��1��$��1��c   	AlarmFlag$c 2��$
��Left=�$	��Top=�d   Message$
d test��$y�Hidden=�   ControlsUnit.TrimmingSlide  -Q   e  Name$e PlayerSlide��$��80��$	��850��$��1��$��3��$��Bottom=�$��Bottom=�$��Center=�f K� ZIndex$	f 100��g   TimeForegroundg �	#FF1F1A50�� -R   h ��Name$
h test��i �� TextWrapping$
i Wrap=�$
��test��$��1��$��
5,4,633,85q�$��1��
�������$��8(�"j �� VerticalScrollBarVisibility$
j Auto=�$��3��$y�Hidden=��� -S   $ Work_Record��$�� ��$��1��$��38��$��243,0,55,122q�$��1��$��18(����	#FFFFFDFD�� $ 
Horizontal=�$��Center=�$	��100��$��1��$��3��$��0,0,0,5q�.+��� .+��� -T   $Q 
UnLock_Btn��$$T 解锁成功飞机进入怠速��|�.  $��
0,20,0,330q�$��90��$��	Meiryo UI)�$��18(�$
��Bold"�$��2q�
������ $��Center=�$��Center=�
�������$	��100���� -U   $Q 	Start_Fly��$T 自主起飞��|�.  $��-400,-340,-400,239q�$��90��$��	Meiryo UI)�$��18(�$
��Bold"�$��2q�
������ $��Center=�$��Center=�
�������$	��100��.���� $.��(/X-Monitor;component/Resources/qifei.png���� -V   $ User3��$��-400,-340,-400,239q�$��90��$	��100��
�������$��	Meiryo UI)�$��18(�$
��Bold"�#���  
�������$��Center=�$��Center=�$��1q�V .  $y�Hidden=��� -W   $Q StopOrReback_Btn��$��
0,-400,0,0q�$T 紧急暂停当前任务��|�.  $��	Meiryo UI)�$��18(�$
��Bold"�$��2q�
������ 
�������$	��100��$��90��$��Center=�$��Center=�.���� $0��*/X-Monitor;component/Resources/zanting.png���� -X   $Q 
Start_Land��$��-400,-230,-400,0q�$T 自主着陆��|�.  $��	Meiryo UI)�$��18(�$
��Bold"�$��2q�
������ 
�������$	��100��$��90��$��Center=�$��Center=�.���� $/��)/X-Monitor;component/Resources/zhuolu.png���� -Y   $ User2��$��-400,-230,-400,0q�$��User2��$��90��$	��100��
�������$��	Meiryo UI)�$��18(�$
��Bold"�#���  
�������$��Center=�$��Center=�$��1q�V .  $y�Hidden=��� -Z   $Q 
Start_Back��$��-400,-70,-400,0q�$T 自主返航��|�.  $��	Meiryo UI)�$��18(�$
��Bold"�$��2q�
������ 
�������$	��100��$��90��$��Center=�$��Center=�.���� $0��*/X-Monitor;component/Resources/fanhang.png���� -[   $ User1��$��-400,-70,-400,0q�$��User1��$��90��$	��100��
�������$��	Meiryo UI)�$��18(�$
��Bold"�#���  
�������$��Center=�$��Center=�$��1q�V .  $	��Top=�$y�Hidden=��� -\   $Q 
Hand_Point��|�.  $	��100��$��389,156,403,0q�$��3��#���  $��0q�$y�Hidden=�$��1��.���� $4��./X-Monitor;component/Resources/Click_Point.png���� $.��(/X-Monitor;component/Resources/charu.png��$ 0.415,0.639&�$��3��$��10,5,129,105q�$��1��� -]   $@ TransmitWindow��$��1��$��2��$	��150��$	��500��$��Center=�$��Center=�$y�Hidden=����� *
Background+$F Main_Window��	 �� $��5 ��� $��* ��� $��5 �
 �� $��5 ��� $��50 ��� $��50 ��� $��50 ��� $��5 �.+��� $��1��$��1��$��飞行任务发送��$
��Left=�$	��Top=�
�������$��24(�$��	Meiryo UI)�$
��Bold"�$��0,5,0,0q��� $��1��$��1��$ 
Horizontal=�$��Right=�$	��Top=�$��50��$��37��.+��� -^   $��r��  CaptionButtonStyleKey#���  $��32(�
�������� -_   k �Name$k TransmitBar��$��1��$��2��$	��5,0q�l � Value$l 50Q�
��������� $��1��$��3��$ 
Horizontal=�$��Center=�$��Center=�$��50��.+��� -`   $��Transmit��$	��120��$��18(�
�������
�������
���   �$��	Meiryo UI)�$��5q�$��Center=�$��Center=�$��Center=�$��40���� -a   $��取消��$	��120��$��18(�
�������
�������
���   �$��	Meiryo UI)�$��80,5,5,5q��� -b   $ 
WaitWindow��$
��Wait��$��Center=�$��1��$��2��
�������m J� Opacity$	m 0.5Q�$��72(�$��Center=�$y�Hidden=��� $��0��$��4������ *
Background+$F Main_Window���� $��4��$��4������ *
Background+$F Main_Window���� $��1��$��0������ *
Background+$F Main_Window���� $��1��$��4������ *
Background+$F Main_Window���� -c   $ 	TopCanvas��$��1��$��1������ *
Background+$F Main_Window���� $��1��$��1��$ 
Horizontal=�$
��Left=�$	��Top=�$��50��.+��� $
��Left=�$��50��$	��Top=�$	��100��$$��Resources/minisurveyorlogo.png���� $��10,6,0,6q�$��	A.Y.Drone��$��28(�
�������$��Center=�$
��Bold"�$��0���� -d   n ��Name$n VersionName��$��0,20,0,0q�$��0.0.0��$��20(�
�������$��Center=��� $��1��$��1��$ 
Horizontal=�$��Right=�$	��Top=�$��50��.+��� -e   $��0��#���  $��32(�
��������� -f   $��1��#���  $��32(�
��������� -g   $��2��#���  $��32(�
��������� -h   $��r��#���  $��32(�
�������r� -i   o r�Name$	o me1��p r� Source$ p Sound/meka_ge_keihou03.mp3?�q r� LoadedBehavior$q Manual=�$y�	Collapsed=�r� -j   $	o me2��$p Sound/ding.wav?�$q Manual=�$y�	Collapsed=�r� -k   $o 	SendSound��$p Sound/start.wav?�$q Manual=�$y�	Collapsed=�r� -l   $o AutoStartFly_Wav��$p Sound/自主起飞.wav?�$q Manual=�$y�	Collapsed=�r� -m   $o AutoStartLand_Wav��$p Sound/自主着陆.wav?�$q Manual=�$y�	Collapsed=�r� -n   $o AutoStartBack_Wav��$p Sound/自主返航.wav?�$q Manual=�$y�	Collapsed=�r� -o   $"o AutoStartMessionTransmit_Wav��$p Sound/任务上传.wav?�$q Manual=�$y�	Collapsed=�r� -p   $'o !AutoStartBreakMessionTransmit_Wav��$p Sound/断点续喷.wav?�$q Manual=�$y�	Collapsed=�