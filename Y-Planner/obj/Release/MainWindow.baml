   M S B A M L   `   `   `  ���� c  _GMap.NET.WindowsPresentation, Version=1.7.0.0, Culture=neutral, PublicKeyToken=b85b9027b614afefqPclr-namespace:GMap.NET.WindowsPresentation;assembly=GMap.NET.WindowsPresentationGMap.NET.WindowsPresentation  G CControlsUnit, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullA0clr-namespace:ControlsUnit;assembly=ControlsUnitControlsUnit O Kmscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e0891&clr-namespace:System;assembly=mscorlibSystem D @Y-Planner, Version=1.2.1.3, Culture=neutral, PublicKeyToken=null3clr-namespace:Y_Planner.OptionY_Planner.Option    Y_Planner.MainWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089` \RibbonControlsLibrary, Version=3.5.41019.1, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      R	 NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml 	    ;metro)http://schemas.codeplex.com/elysium/theme 	    `mapPclr-namespace:GMap.NET.WindowsPresentation;assembly=GMap.NET.WindowsPresentation 	    Dcontrol0clr-namespace:ControlsUnit;assembly=ControlsUnit 	    X
 TXceed.Wpf.Toolkit, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f44xctk)http://schemas.xceed.com/wpf/xaml/toolkit 
 [ WXceed.Wpf.AvalonDock, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f47xcad,http://schemas.xceed.com/wpf/xaml/avalondock  .s&clr-namespace:System;assembly=mscorlib  MCustom@http://schemas.microsoft.com/winfx/2006/xaml/presentation/ribbon  +optionclr-namespace:Y_Planner.Option  -     �Name$  Main_Window��$	��720��$
��1280�� � Icon$ Resources/minisv.ico�� � WindowStyle$ SingleBorderWindow=�$	��720��$	��780������ *
Background+ �� ElementName$ 
MainRibbon�� � 	Resources  �� Source�� $ MainWindowStyles.xaml?�%    '  !System.Windows.Shell.WindowChrome   WindowChrome      CaptionHeight$ 50Q�   ResizeBorderThickness$ 5q�.��� 	 � ColumnDefinitions	 �� $��10 ��� $
��440* ��� $��10 �
 � RowDefinitions
 �� $��10 ��� $��50 ��� $
��348* ��� $��10 �.+�� $��2��$��1��	 
 �� -    �Name$ 	RibbonRow��$	��140 ��� $��* �.+�+  %System.Windows.Controls.Ribbon.Ribbon  -     Name$ 
MainRibbon��$��0��$��2��   ApplicationMenu :  4System.Windows.Controls.Ribbon.RibbonApplicationMenu  5  /System.Windows.Controls.Ribbon.RibbonMenuButton   KeyTip$ F��   LargeImageSource$ Resources/Circle1.png��.@�>  8System.Windows.Controls.Ribbon.RibbonApplicationMenuItem  -   $��NewFile��$��新建��3  -System.Windows.Controls.Ribbon.RibbonMenuItem   ImageSource$ Resources/file126.png��  -   $��FileOpen��$��打开��$ Resources/open127.png��  -   $��	FileClose��$��关闭��  -   $
��Save��$��目标另存为��$ Resources/save-file.png��  -   $��	OverWrite��$��保存��4  .System.Windows.Controls.Ribbon.RibbonSeparator    -	   $��Manual��$��帮助文档��$ Resources/text54.png��  -
   $��About��$��关于��    -   $	��End��$��退出��   KeyTip$ E��   HelpPaneContent 1  +System.Windows.Controls.Ribbon.RibbonButton  -      SmallImageSource$ Resources/up.png��   QuickAccessToolBar =	  7System.Windows.Controls.Ribbon.RibbonQuickAccessToolBar	  .@�  -     Name$ QuickAccessConnect��$��0,0,5,0q� �� $ 	UAVConect�� �� Path$ LargeImageSource�  -   $ QuickAccessTouch��$��0,0,5,0q� �� $ 	TouchIcon��$ LargeImageSource�  -   $ QuickAccessUndo��$ Resources/back36.png��{��� $ 
UndoButton��$ 	IsEnabled�  -   $ QuickAccessRedo��$ Resources/right133.png��{��� $ 
RedoButton��$ 	IsEnabled�.@�.
  (System.Windows.Controls.Ribbon.RibbonTab
  $��工程�� 
  KeyTip$ V��.@�0  *System.Windows.Controls.Ribbon.RibbonGroup  -     Name$ Mission��$��任务��.@�  -   $��	BasePoint��   Label$ 	基准点��$  Resources/placeholder8.png��.@�  -   $��BasePointAdd��$��	增加(+)��$ Resources/add204.png��  -   $��BasePointDel��$��	删除(-)��$ Resources/minus3.png��  $��航点��.@�  -   $ SingleClear��   Label$ 清除��  -   $ AllClear��$ 清除所有��  -   $ 	AllSelect��$ 全选��$y�Hidden=�  $��撤销/前进��.@�  -   $ 
UndoButton��$ 撤销��$��2q�   LargeImageSource$ Resources/back36.png��{�.    -   $ 
RedoButton��$ 前进��$��2q�$ Resources/right133.png��{�.    -   $ PropertiesView��$��属性显示��.@�  $ 属性��$ Resources/view1.png��.@�  $��航点属性��$! Resources/property-blue.png��  $��任务属性��$! Resources/property-blue.png��  $ 列表显示��$ Resources/list88.png��.@�  -   $��航点视图��  -   $��任务视图��  -   $��高度视图��  $��路点设置��.@���  �� Orientation$ Vertical=�.+��� -   $��40��$��40��$��5q�����  �� ImageSource$ Resources/standard.png��	� -   $��Radio_StandardDraw�� 	� 	GroupName$ Group1��$��2q�$��标准�� d� 	IsChecked$
 TrueY��� $ Vertical=�.+��� -    $��40��$��40��$��5q����� $ Resources/line.png��	� -!   $��Radio_LineDraw��$ Group1��$��2q�$��直线���� $ Vertical=�.+��� -"   $��40��$��40��$��5q����� $ Resources/Rectangle.png��	� -#   $��Radio_RectangleDraw��$ Group1��$��2q�$��矩形���� $ Vertical=�.+��� -$   $��40��$��40��$��5q����� $ Resources/Circle.png��	� -%   $��Radio_CircleDraw��$ Group1��$��2q�$	��圆���� $ Vertical=�.+��� -&   $��40��$��40��$��5q����� $ Resources/ReturnDraw1.png��	� -'   $��Radio_ReturnDraw1��$ Group1��$��2q�$��横向往复���� $ Vertical=�.+��� -(   $��40��$��40��$��5q����� $ Resources/ReturnDraw2.png��	� -)   $��Radio_ReturnDraw2��$ Group1��$��2q�$��纵向往复���� $ 
Horizontal=�.+��� $��纵向等分数:��$��0,0,5,0q�$ 
 Xceed.Wpf.Toolkit.DoubleUpDown  -*   $��NumberOfPartitionsValue1��$��60��� 
 �Xceed.Wpf.Toolkit.Primitives.UpDownBase`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]    Value$  3X�$��1q�!   Maximum$	! 255X�"   Minimum$" 0X�� 
 �Xceed.Wpf.Toolkit.NumericUpDown`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]#   	Increment$# 1X��� $ 
Horizontal=�.+��� $��横向等分数:��$��0,0,5,0q�  -+   $��NumberOfPartitionsValue2��$��60��$  3X�$��1q�$	! 255X�$" 0X�$# 1X�  $��发送��.@�  -,   $��Transmit��$ Transmit��$ Resources/x_monitor.png��  $��変换��.@�  --   $��kmlWrite��$	 KML��$ Resources/kml.png��
  $��设置��$ V��.@�  -.   $ 	MapGroup2��$��切换操作��.@�  -/   $ 	TouchIcon��$ 触控/鼠标��  -0   $ 
MapSetting��$��	经纬度��.@��� $ 
Horizontal=�.+��� $��纬度:��$��0,0,5,0q�2  ,System.Windows.Controls.Ribbon.RibbonTextBox  -1   $��LatText��$��90���� $ 
Horizontal=�.+��� $��经度:��$��0,0,2,0q�  -2   $��LngText��$��90��$��	0,0,0,0.2q��� -3   $��	LatLngSet��$��设置��$��55��$��2q�  $��地图选择��.@��� -4   $��a��$��地图类别:���� -5   $��MapProviders��$	��100��  $��地图选择��.@��� -6   $��CustomMapText��$	��120��{�.  �� -7   $��CustomMapButton��$��1��$��1��$��5q�$��参照��  $��经度和纬度搜索��.@��� $��
目标点:��  -8   $��AddressText��$��	千叶大���� -9   $��AddressSearch��$��搜索��$��55��$��2q��� -:   $��
AddressSet��$��设置��$��55��$��2q�  $��海拔高度��.@�  -;   $��ElevationText��{�.  �� -<   $��ElevationSet��$��海拔获取��$��5q�
  $��机体信息��.@�  $��连接��.@�  -=   $��	UAVConect��$ 连接失败��$ Resources/disconnect.png��  $	��UAV��.@��� $ 
Horizontal=�.+��� $��纬度:��$��0,0,3,0q�  ->   $��
UAVLatText���� $ 
Horizontal=�.+��� $��经度:��$��0,0,0,0q�  -?   $��
UAVLngText���� $ 
Horizontal=�.+��� $��高度:��$��0,0,7,0q�  -@   $��
UAVAltText���� $ 
Horizontal=�.+��� $��偏航:��$��0,0,0,0q�  -A   $��
UAVYawText��)  #Xceed.Wpf.AvalonDock.DockingManager  $��2��$   AllowMixedOrientation$ . $��1q�%   DocumentHeaderTemplate% �� .R��� $ 
Horizontal=�.+��� $��0,0,4,0q����� *
IconSource+�� ���� *Title+&   Layout.& ,  &Xceed.Wpf.AvalonDock.Layout.LayoutRoot  -B   _layoutRoot��'   	RootPanel.' -  'Xceed.Wpf.AvalonDock.Layout.LayoutPanel  (   Orientation$( 
Horizontal=��  �Xceed.Wpf.AvalonDock.Layout.LayoutGroup`1[[Xceed.Wpf.AvalonDock.Layout.ILayoutPanelElement, Xceed.Wpf.AvalonDock, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4]])   Children.) 6  0Xceed.Wpf.AvalonDock.Layout.LayoutAnchorablePane  �  �Xceed.Wpf.AvalonDock.Layout.LayoutPositionableGroup`1[[Xceed.Wpf.AvalonDock.Layout.LayoutAnchorable, Xceed.Wpf.AvalonDock, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4]]*   	DockWidth$	* 250 ��  �Xceed.Wpf.AvalonDock.Layout.LayoutGroup`1[[Xceed.Wpf.AvalonDock.Layout.LayoutAnchorable, Xceed.Wpf.AvalonDock, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4]]+   Children.+ 2  ,Xceed.Wpf.AvalonDock.Layout.LayoutAnchorable  /  )Xceed.Wpf.AvalonDock.Layout.LayoutContent,   	ContentId$, WaypointPropertyId��-   Title$- 航点属性��.   CanHide. .  /   CanClose/ .  0   AutoHideWidth$	0 300Q�1   
IconSource$!1 Resources/property-blue.png��2   FloatingWidth$	2 200Q�3   Content.3 1 
 +Xceed.Wpf.Toolkit.PropertyGrid.PropertyGrid  -C   4  Name$4 WaypointProperty��5   NameColumnWidth$	5 120Q�  $, MissionPropaertyId��$- 任务属性��. .  / .  $	0 300Q�$!1 Resources/property-blue.png��6   FloatingHeight$	6 200Q�$	2 200Q�.3   -D   $4 MissionProperty��$	5 120Q�9  3Xceed.Wpf.AvalonDock.Layout.LayoutDocumentPaneGroup  �  �Xceed.Wpf.AvalonDock.Layout.LayoutGroup`1[[Xceed.Wpf.AvalonDock.Layout.ILayoutDocumentPane, Xceed.Wpf.AvalonDock, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4]]7   Children.7 4  .Xceed.Wpf.AvalonDock.Layout.LayoutDocumentPane  �  �Xceed.Wpf.AvalonDock.Layout.LayoutGroup`1[[Xceed.Wpf.AvalonDock.Layout.LayoutContent, Xceed.Wpf.AvalonDock, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4]]8   Children.8 0  *Xceed.Wpf.AvalonDock.Layout.LayoutDocument  -E   $, documentMap��$	- Map��$1 Resources/document.png��/ .  9   CanFloat9 .  .3 � 	 �� $��80 ��� $��* ��� $	��200 �
 �� $��* ��� $��60 �.+�.   (GMap.NET.WindowsPresentation.GMapControl  -F   :  Name$: MainMap��$��3��$��2��;   MaxZoom$; 20��<   MinZoom$< 1��=   Zoom$= 17Q�>   	ScaleMode$> Dynamic=�? J� RenderTransformOrigin$? 0.5,0.5&�$��-278,-291,-222,-309q��� -G   @ ��Name$@ 	Copyright��$��1��$��0��$��2��$��	Copyright��$��21�����	#FF5B5B5B$��8(�$��Bottom=�$��Bottom=��� -H   A ��Name$A GridLine��$��3��$��2��
�������B �� CornerRadius$B 0��$	��0.5q�._��� -I   C ��Name$C canvas��D J� SnapsToDevicePixelsD . $��0,-2,0,2q�� -J   $��Arrow��$��3��$��40��$	��250��$	��Top=�$��Right=�	 �� $��* ��� $��50 �
 �� $��* �.+�� -K   $��DisArrow��$��1��$��Center=�$��Right=�$��50��.+��� -L   $
��Dis1��
�������$��2��	E �� X1$E 0��	F �� Y1$F 8��	G �� Y2$G 8��	H �� X2H �� $ DisArrow��$ Width��� -M   $
��Dis2��$��4��$E 2��$F 0��$H 2��$G 16������ $
 Dis1��$ Stroke��� -N   $
��Dis3��$��4��$��Right=�$E 0��$F 0��$H 0��$G 16������ $
 Dis1��$ Stroke��� -O   $��DisName��$��0��$	��dis��$��40��$	��180��$��24(�$	��Top=�$��Right=�$��Right=�$��Center=����	#FF1F1A50��Z� (� $��2��$��0��$��2��I (� StretchDirection$I DownOnly=�$��Right=�$��Bottom=�.���� $ 
Horizontal=�$��Center=�$��Bottom=�.+��� $��50��$��50��$��2�����	#FF1F1A50$��Bottom=�
�������$B 3��$��2q�._��� -P   $��
MarkerIcon��
�������
�������J J� OpacityMaskJ �� $ Resources/maker.png��"   ControlsUnit.RotateAzimuthal   -Q   K   Name$K 	MapRotate��$��Bottom=�$��50��$��50������ $ ZoomName��$ ZoomBackground�!  ControlsUnit.MapZoom!  -R   L ! Name$L ZoomName��M !  ZoomBackground$M 	#FF1F1A50��N !  ZoomMinimum$N 1Q�O !  ZoomMaximum$O 20Q�P !  ValueP �� *Zoom+$ MainMap��;"  5Xceed.Wpf.AvalonDock.Layout.LayoutAnchorablePaneGroup"  �#  �Xceed.Wpf.AvalonDock.Layout.LayoutPositionableGroup`1[[Xceed.Wpf.AvalonDock.Layout.ILayoutAnchorablePane, Xceed.Wpf.AvalonDock, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4]]Q #  	DockWidth$	Q 200 ��$  �Xceed.Wpf.AvalonDock.Layout.LayoutGroup`1[[Xceed.Wpf.AvalonDock.Layout.ILayoutAnchorablePane, Xceed.Wpf.AvalonDock, Version=2.3.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f4]]R $  Children.R   .+   -S   WaypointDoc��$, Waypoint��$- 航点��$%1 Resources/address-book-open.png��S   CanAutoHideS . 9 . . . / .  T   AutoHideMinHeight$T 0Q�U   AutoHideMinWidth$U 0Q�$	0 200Q�$	2 200Q�V   IsMaximizedV . .3 � 	 �� $��* �
 �� $��80 ��� $��* ��� $��30 �.+��� -T   W ��Name$ W WaypointAllChange_DataGrid��$��0��X �� ViewX �� .P��� $��ID��Y �� DisplayMemberBindingY �� *ID+�� $��x��Z �� CellTemplateZ �� .R�  [  Name$[ AllWaypointX��-U     �� *x+�� $��y��Z �� .R�  $[ AllWaypointY��-V     �� *y+�� $��高度��Z �� .R�  $[ AllWaypointHeight��-W     �� *Height+�� $��航向��Z �� .R�  $[ AllWaypointHeading��-X   $
" -180X�$	! 180X�  �� *	Heading+�� $��等待时间��Z �� .R�  $[ AllWaypointWait��-Y     �� *Wait+�� $��速度��Z �� .R�  $[ AllWaypointSpeed��-Z   $	" 0.1X�$! 10X�  �� *Speed+�� -[   $W WaypointListView��$��1������ X �� .P��� $��ID��Y �� *ID+�� $��x��Y �� *x+�� $��y��Y �� *y+�� $��高度��Y �� *Height+�� $��航向��Y �� *	Heading+�� $��等待时间��Y �� *Wait+�� $��速度��Y �� *Speed+� $��2��	 �� $��50 ��� $��50 ��� $��50 ��� $��50 ��� $��* �
 �� $��* �.+��� -\   $��0��$��增加��$��2q��� -]   $��1��$��删除��$��2q��� -^   $��2��$	��▲��$��2q��� -_   $��3��$	��▼��$��2q�  -`   AltitudeDock��$, Altitude��$- 高度列表��$%1 Resources/address-book-open.png��S . 9 . . . / .  $T 0Q�$U 0Q�$	0 200Q�$	2 200Q�V . .3 '%  !Y_Planner.Option.AltitudeProperty%  -a   \ % Name$\ AltitudePropertyValue��'&  !Y_Planner.Option.AltitudeProperty] &  ValueChanged$(] "AltitudePropertyValue_ValueChanged��^ &  AllValueChanged$+^ %AltitudePropertyValue_AllValueChanged��  -b   
MissionDoc��$, Mission��$- 任务列表��$%1 Resources/address-book-open.png��/ .  . . 9 . S . $	T 200Q�$	U 200Q�_   AutoHideHeight$	_ 200Q�$	0 200Q�$	2 200Q�$	6 200Q�V . `   	IsVisible` .  .3 � 	 �� $��* ��� $��* ��� $��* �
 �� $	��100 ��� $	��120 ��� $	��100 ��� $��60 ��� $��40 ��� $��40 ��� $��40 ��� $��* �.+��� $��0��$��3��.+��� $ 
Horizontal=�$��5q�.+��� $��任务:���� -c   $��missionSelect��$	��120��{�.  �� $ 
Horizontal=�$��5q�.+��� $��名称:���� -d   $��missionName��$	��120��$��5,0,0,0q�{��� $ missionSelect��$ 	IsEnabled��� -e   $��missonEnabled��$��5q�$��Enabled��$
 TrueY�{�.  �� $��基本属性��$��1��$��3��.��� 	 �� $��70 ��� $��* �
 �� $��25 ��� $��25 ��� $��25 ��� $��25 �.+��� $��纬度:��$��0���� $��经度:��$��1���� $��高度:��$��2���� $��旋转:��$��3��  -f   $��LatValue��$��0��$��1��$��1q�$! 90X�$	" -90X�$# 0.000001X�{��� $ missionSelect��$ 	IsEnabled�  -g   $��LonValue��$��1��$��1��$��1q�$	! 180X�$
" -180X�$# 0.000001X�{��� $ missionSelect��$ 	IsEnabled�  -h   $��AltValue��$��2��$��1��$��1q�$	! 300X�$" 0X�$	# 0.1X�{�.    -i   $��RotValue��$��3��$��1��$��1q�$	! 180X�$
" -180X�$# 1X�{��� $ missionSelect��$ 	IsEnabled��� $��比例��$��2��$��3��.��� 	 �� $��50 ��� $��* �
 �� $��25 ��� $��25 ��� $��25 �.+��� $��x:��$��0��$��Right=��� $��y:��$��1��$��Right=��� $��z:��$��2��$��Right=�  -j   $��XValue��$��0��$��1��$��1q�$	! 300X�$" 0X�$	# 0.1X�{��� $ missionSelect��$ 	IsEnabled�  -k   $��YValue��$��1��$��1��$��1q�$	! 300X�$" 0X�$	# 0.1X�{��� $ missionSelect��$ 	IsEnabled�  -l   $��ZValue��$��2��$��1��$��1q�$	! 300X�$" 0X�$	# 0.1X�{�.  �� $��3��$��3��.+��� $��高度模式���� -m   $��AltitudeMode��{�.  .@��� $��相对高度���� $��绝对高度���� $��对地高度���� $��4��$��3��$ 
Horizontal=�$��5q�{�.  .+��� $��任务:���� -n   $��missionConnect��$	��120��{��� $ missionSelect��$ 	IsEnabled��� $��5��$��3��$ 
Horizontal=�$��5q�.+��� $��总计:���� -o   $��	TotalText��$��0��$	��100��{�.  a �� TextAlignment$a Right=��� $	��[m]���� $��6��$��3��$ 
Horizontal=�$��5q�$y�Hidden=�.+��� $��预测:���� -p   $��EstimationText��$	��100��{�.  �� -q   $��
WaitWindow��$��等待��$��Center=�$��1��$��2��
�������b J� Opacity$	b 0.5Q�$��72(�$��Center=�$y�Hidden=��� $��0��$��4������ *
Background+$ 
MainRibbon���� $��4��$��4������ *
Background+$ 
MainRibbon���� $��1��$��0������ *
Background+$ 
MainRibbon���� $��1��$��4������ *
Background+$ 
MainRibbon���� -r   $C 	TopCanvas��$��1��$��1������ *
Background+$ 
MainRibbon���� $��1��$��1��$ 
Horizontal=�$
��Left=�$	��Top=�$��50��.+��� $
��Left=�$��50��$	��Top=�$	��120��$��1��$��1������ c �� Color$c Black��d �� Opacity$	d 0.6Q�J �� $$ Resources/minisurveyorlogo.png���� $��10,0,0,0q�$��	Y-Planner��$��32(�$��Bottom=�$
��Bold"����� $c Black��$	d 0.6Q��� -s   $��VersionName��$��10,0,0,0q�$��0.0.0��$��32(�$��Bottom=�$
��Bold"����� $c Black��$	d 0.6Q��� $��1��$��1��$ 
Horizontal=�$��Right=�$	��Top=�$��50��.+��� -t   $��0��   CaptionButtonStyleKey#���   $��32(�
�������
���   ��� -u   $��1��#���   $��32(�
�������
���   ��� -v   $��2��#���   $��32(�
�������
���   ��� -w   $��r��#���   $��32(�
�������
���   �