﻿#pragma checksum "..\..\MainWindow.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "852872921A910A042769CB32757F395A"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.18444
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using ControlsUnit;
using GMap.NET.WindowsPresentation;
using HelixToolkit.Wpf;
using Microsoft.Research.DynamicDataDisplay;
using Microsoft.Research.DynamicDataDisplay.Charts;
using Microsoft.Research.DynamicDataDisplay.Charts.Axes;
using Microsoft.Research.DynamicDataDisplay.Charts.Navigation;
using Microsoft.Research.DynamicDataDisplay.Charts.Shapes;
using Microsoft.Research.DynamicDataDisplay.Common.Palettes;
using Microsoft.Research.DynamicDataDisplay.DataSources;
using Microsoft.Research.DynamicDataDisplay.Navigation;
using Microsoft.Research.DynamicDataDisplay.PointMarkers;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Forms.Integration;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;
using WPF.MDI;
using XMonitor_GUI.CustomMarkers;
using XMonitor_GUI.Window;


namespace XMonitor_GUI {
    
    
    /// <summary>
    /// MainWindow
    /// </summary>
    public partial class MainWindow : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 13 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal XMonitor_GUI.MainWindow Main_Window;
        
        #line default
        #line hidden
        
        
        #line 40 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal GMap.NET.WindowsPresentation.GMapControl MainMap;
        
        #line default
        #line hidden
        
        
        #line 43 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label Copyright;
        
        #line default
        #line hidden
        
        
        #line 49 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ColumnDefinition BaseWidth;
        
        #line default
        #line hidden
        
        
        #line 51 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ColumnDefinition BaseColumn;
        
        #line default
        #line hidden
        
        
        #line 57 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.RowDefinition BaseRow;
        
        #line default
        #line hidden
        
        
        #line 58 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.RowDefinition BaseHeight;
        
        #line default
        #line hidden
        
        
        #line 62 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas LeftsideArea;
        
        #line default
        #line hidden
        
        
        #line 67 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas TopArea;
        
        #line default
        #line hidden
        
        
        #line 72 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas RightsideArea;
        
        #line default
        #line hidden
        
        
        #line 88 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.TimerView TimerName;
        
        #line default
        #line hidden
        
        
        #line 89 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.BatteryView BatteryName;
        
        #line default
        #line hidden
        
        
        #line 90 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.GPSView GPSName;
        
        #line default
        #line hidden
        
        
        #line 91 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.LinkView LinkName;
        
        #line default
        #line hidden
        
        
        #line 92 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.RCrecView RCrecName;
        
        #line default
        #line hidden
        
        
        #line 93 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.ControlModeView ControlModeName;
        
        #line default
        #line hidden
        
        
        #line 94 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.FlightModeView FlightModeName;
        
        #line default
        #line hidden
        
        
        #line 95 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.SpeedView SpeedName;
        
        #line default
        #line hidden
        
        
        #line 101 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.UAVAltitude Altitude;
        
        #line default
        #line hidden
        
        
        #line 112 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem OpenFlightPlan;
        
        #line default
        #line hidden
        
        
        #line 113 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem CloseFlightPlan;
        
        #line default
        #line hidden
        
        
        #line 114 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem SendFlightPlan;
        
        #line default
        #line hidden
        
        
        #line 115 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem ListFlightPlan;
        
        #line default
        #line hidden
        
        
        #line 117 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem OpenFlightLog;
        
        #line default
        #line hidden
        
        
        #line 118 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem CloseFlightLog;
        
        #line default
        #line hidden
        
        
        #line 119 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem SaveFlightLog;
        
        #line default
        #line hidden
        
        
        #line 120 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem OpenExplorer;
        
        #line default
        #line hidden
        
        
        #line 134 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas MarkerIcon;
        
        #line default
        #line hidden
        
        
        #line 139 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas TouchIcon;
        
        #line default
        #line hidden
        
        
        #line 140 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas SettingIcon;
        
        #line default
        #line hidden
        
        
        #line 149 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Border GridLine;
        
        #line default
        #line hidden
        
        
        #line 150 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas canvas;
        
        #line default
        #line hidden
        
        
        #line 157 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Grid Arrow;
        
        #line default
        #line hidden
        
        
        #line 165 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Grid DisArrow;
        
        #line default
        #line hidden
        
        
        #line 166 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Shapes.Line Dis1;
        
        #line default
        #line hidden
        
        
        #line 167 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Shapes.Line Dis2;
        
        #line default
        #line hidden
        
        
        #line 168 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Shapes.Line Dis3;
        
        #line default
        #line hidden
        
        
        #line 170 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label DisName;
        
        #line default
        #line hidden
        
        
        #line 181 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label User1;
        
        #line default
        #line hidden
        
        
        #line 182 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label User2;
        
        #line default
        #line hidden
        
        
        #line 183 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label User3;
        
        #line default
        #line hidden
        
        
        #line 184 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label User4;
        
        #line default
        #line hidden
        
        
        #line 185 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label PosSet;
        
        #line default
        #line hidden
        
        
        #line 186 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label PosSpd;
        
        #line default
        #line hidden
        
        
        #line 187 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label PosClear;
        
        #line default
        #line hidden
        
        
        #line 188 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.RotateAzimuthal MapRotate;
        
        #line default
        #line hidden
        
        
        #line 195 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal WPF.MDI.MdiContainer Container;
        
        #line default
        #line hidden
        
        
        #line 197 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ContextMenu cm;
        
        #line default
        #line hidden
        
        
        #line 212 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.GridSplitter OptionGridSplitter;
        
        #line default
        #line hidden
        
        
        #line 220 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.MapZoom ZoomName;
        
        #line default
        #line hidden
        
        
        #line 227 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.AlarmMessage AlertMessageName;
        
        #line default
        #line hidden
        
        
        #line 230 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ControlsUnit.TrimmingSlide PlayerSlide;
        
        #line default
        #line hidden
        
        
        #line 234 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox test;
        
        #line default
        #line hidden
        
        
        #line 240 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Grid TransmitWindow;
        
        #line default
        #line hidden
        
        
        #line 259 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ProgressBar TransmitBar;
        
        #line default
        #line hidden
        
        
        #line 266 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label WaitWindow;
        
        #line default
        #line hidden
        
        
        #line 276 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas TopCanvas;
        
        #line default
        #line hidden
        
        
        #line 280 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBlock VersionName;
        
        #line default
        #line hidden
        
        
        #line 290 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MediaElement me1;
        
        #line default
        #line hidden
        
        
        #line 291 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MediaElement me2;
        
        #line default
        #line hidden
        
        
        #line 292 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MediaElement SendSound;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/X-Monitor;component/mainwindow.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\MainWindow.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.Main_Window = ((XMonitor_GUI.MainWindow)(target));
            
            #line 14 "..\..\MainWindow.xaml"
            this.Main_Window.Closing += new System.ComponentModel.CancelEventHandler(this.MainWindowCosing);
            
            #line default
            #line hidden
            
            #line 15 "..\..\MainWindow.xaml"
            this.Main_Window.SizeChanged += new System.Windows.SizeChangedEventHandler(this.Window_SizeChanged);
            
            #line default
            #line hidden
            
            #line 15 "..\..\MainWindow.xaml"
            this.Main_Window.PreviewKeyDown += new System.Windows.Input.KeyEventHandler(this.Window_PreviewKeyDown);
            
            #line default
            #line hidden
            return;
            case 2:
            this.MainMap = ((GMap.NET.WindowsPresentation.GMapControl)(target));
            return;
            case 3:
            this.Copyright = ((System.Windows.Controls.Label)(target));
            return;
            case 4:
            this.BaseWidth = ((System.Windows.Controls.ColumnDefinition)(target));
            return;
            case 5:
            this.BaseColumn = ((System.Windows.Controls.ColumnDefinition)(target));
            return;
            case 6:
            this.BaseRow = ((System.Windows.Controls.RowDefinition)(target));
            return;
            case 7:
            this.BaseHeight = ((System.Windows.Controls.RowDefinition)(target));
            return;
            case 8:
            this.LeftsideArea = ((System.Windows.Controls.Canvas)(target));
            return;
            case 9:
            this.TopArea = ((System.Windows.Controls.Canvas)(target));
            return;
            case 10:
            this.RightsideArea = ((System.Windows.Controls.Canvas)(target));
            return;
            case 11:
            this.TimerName = ((ControlsUnit.TimerView)(target));
            return;
            case 12:
            this.BatteryName = ((ControlsUnit.BatteryView)(target));
            return;
            case 13:
            this.GPSName = ((ControlsUnit.GPSView)(target));
            return;
            case 14:
            this.LinkName = ((ControlsUnit.LinkView)(target));
            return;
            case 15:
            this.RCrecName = ((ControlsUnit.RCrecView)(target));
            return;
            case 16:
            this.ControlModeName = ((ControlsUnit.ControlModeView)(target));
            return;
            case 17:
            this.FlightModeName = ((ControlsUnit.FlightModeView)(target));
            return;
            case 18:
            this.SpeedName = ((ControlsUnit.SpeedView)(target));
            return;
            case 19:
            this.Altitude = ((ControlsUnit.UAVAltitude)(target));
            return;
            case 20:
            this.OpenFlightPlan = ((System.Windows.Controls.MenuItem)(target));
            
            #line 112 "..\..\MainWindow.xaml"
            this.OpenFlightPlan.Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_FplaOpen);
            
            #line default
            #line hidden
            return;
            case 21:
            this.CloseFlightPlan = ((System.Windows.Controls.MenuItem)(target));
            
            #line 113 "..\..\MainWindow.xaml"
            this.CloseFlightPlan.Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_FplaClose);
            
            #line default
            #line hidden
            return;
            case 22:
            this.SendFlightPlan = ((System.Windows.Controls.MenuItem)(target));
            
            #line 114 "..\..\MainWindow.xaml"
            this.SendFlightPlan.Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_FplaTrans);
            
            #line default
            #line hidden
            return;
            case 23:
            this.ListFlightPlan = ((System.Windows.Controls.MenuItem)(target));
            
            #line 115 "..\..\MainWindow.xaml"
            this.ListFlightPlan.Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_FplaData);
            
            #line default
            #line hidden
            return;
            case 24:
            this.OpenFlightLog = ((System.Windows.Controls.MenuItem)(target));
            
            #line 117 "..\..\MainWindow.xaml"
            this.OpenFlightLog.Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_FlogOpen);
            
            #line default
            #line hidden
            return;
            case 25:
            this.CloseFlightLog = ((System.Windows.Controls.MenuItem)(target));
            
            #line 118 "..\..\MainWindow.xaml"
            this.CloseFlightLog.Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_FlogClose);
            
            #line default
            #line hidden
            return;
            case 26:
            this.SaveFlightLog = ((System.Windows.Controls.MenuItem)(target));
            
            #line 119 "..\..\MainWindow.xaml"
            this.SaveFlightLog.Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_FlogSave);
            
            #line default
            #line hidden
            return;
            case 27:
            this.OpenExplorer = ((System.Windows.Controls.MenuItem)(target));
            
            #line 120 "..\..\MainWindow.xaml"
            this.OpenExplorer.Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_OpenExplorer);
            
            #line default
            #line hidden
            return;
            case 28:
            
            #line 123 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_UAVData);
            
            #line default
            #line hidden
            return;
            case 29:
            
            #line 124 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_Setting);
            
            #line default
            #line hidden
            return;
            case 30:
            
            #line 125 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_Manual);
            
            #line default
            #line hidden
            return;
            case 31:
            
            #line 126 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_About);
            
            #line default
            #line hidden
            return;
            case 32:
            
            #line 128 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_End);
            
            #line default
            #line hidden
            return;
            case 33:
            this.MarkerIcon = ((System.Windows.Controls.Canvas)(target));
            
            #line 134 "..\..\MainWindow.xaml"
            this.MarkerIcon.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.MarkerIcon_MouseLeftButtonDown);
            
            #line default
            #line hidden
            return;
            case 34:
            this.TouchIcon = ((System.Windows.Controls.Canvas)(target));
            
            #line 139 "..\..\MainWindow.xaml"
            this.TouchIcon.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.TouchIconMouse);
            
            #line default
            #line hidden
            return;
            case 35:
            this.SettingIcon = ((System.Windows.Controls.Canvas)(target));
            
            #line 140 "..\..\MainWindow.xaml"
            this.SettingIcon.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.SettingIconMouseLeftButton);
            
            #line default
            #line hidden
            return;
            case 36:
            this.GridLine = ((System.Windows.Controls.Border)(target));
            return;
            case 37:
            this.canvas = ((System.Windows.Controls.Canvas)(target));
            
            #line 152 "..\..\MainWindow.xaml"
            this.canvas.Loaded += new System.Windows.RoutedEventHandler(this.canvas_Loaded);
            
            #line default
            #line hidden
            
            #line 153 "..\..\MainWindow.xaml"
            this.canvas.SizeChanged += new System.Windows.SizeChangedEventHandler(this.canvas_SizeChanged);
            
            #line default
            #line hidden
            return;
            case 38:
            this.Arrow = ((System.Windows.Controls.Grid)(target));
            return;
            case 39:
            this.DisArrow = ((System.Windows.Controls.Grid)(target));
            return;
            case 40:
            this.Dis1 = ((System.Windows.Shapes.Line)(target));
            return;
            case 41:
            this.Dis2 = ((System.Windows.Shapes.Line)(target));
            return;
            case 42:
            this.Dis3 = ((System.Windows.Shapes.Line)(target));
            return;
            case 43:
            this.DisName = ((System.Windows.Controls.Label)(target));
            return;
            case 44:
            this.User1 = ((System.Windows.Controls.Label)(target));
            return;
            case 45:
            this.User2 = ((System.Windows.Controls.Label)(target));
            return;
            case 46:
            this.User3 = ((System.Windows.Controls.Label)(target));
            return;
            case 47:
            this.User4 = ((System.Windows.Controls.Label)(target));
            return;
            case 48:
            this.PosSet = ((System.Windows.Controls.Label)(target));
            return;
            case 49:
            this.PosSpd = ((System.Windows.Controls.Label)(target));
            
            #line 186 "..\..\MainWindow.xaml"
            this.PosSpd.MouseDoubleClick += new System.Windows.Input.MouseButtonEventHandler(this.PosSpd_MouseDoubleClick);
            
            #line default
            #line hidden
            return;
            case 50:
            this.PosClear = ((System.Windows.Controls.Label)(target));
            return;
            case 51:
            this.MapRotate = ((ControlsUnit.RotateAzimuthal)(target));
            
            #line 188 "..\..\MainWindow.xaml"
            this.MapRotate.ValueChanged += new System.Windows.RoutedPropertyChangedEventHandler<double>(this.RotateAzimuthalValueChanged);
            
            #line default
            #line hidden
            
            #line 188 "..\..\MainWindow.xaml"
            this.MapRotate.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.MapRotate_MouseLeftButtonDown);
            
            #line default
            #line hidden
            return;
            case 52:
            this.Container = ((WPF.MDI.MdiContainer)(target));
            
            #line 195 "..\..\MainWindow.xaml"
            this.Container.SizeChanged += new System.Windows.SizeChangedEventHandler(this.OptionAreaSizeChanged);
            
            #line default
            #line hidden
            return;
            case 53:
            this.cm = ((System.Windows.Controls.ContextMenu)(target));
            return;
            case 54:
            
            #line 198 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.WaypointWindow_Click);
            
            #line default
            #line hidden
            return;
            case 55:
            
            #line 199 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.ChartWindow_Click);
            
            #line default
            #line hidden
            return;
            case 56:
            
            #line 200 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.ApplicationWindow_Click);
            
            #line default
            #line hidden
            return;
            case 57:
            
            #line 201 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.ModelWindow_Click);
            
            #line default
            #line hidden
            return;
            case 58:
            
            #line 203 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.Cascade_Click);
            
            #line default
            #line hidden
            return;
            case 59:
            
            #line 204 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.Horizontally_Click);
            
            #line default
            #line hidden
            return;
            case 60:
            
            #line 205 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.Vertically_Click);
            
            #line default
            #line hidden
            return;
            case 61:
            
            #line 207 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.CloseAll_Click);
            
            #line default
            #line hidden
            return;
            case 62:
            this.OptionGridSplitter = ((System.Windows.Controls.GridSplitter)(target));
            return;
            case 63:
            this.ZoomName = ((ControlsUnit.MapZoom)(target));
            
            #line 221 "..\..\MainWindow.xaml"
            this.ZoomName.ValueChanged += new System.Windows.RoutedPropertyChangedEventHandler<double>(this.MapZoomChanged);
            
            #line default
            #line hidden
            return;
            case 64:
            this.AlertMessageName = ((ControlsUnit.AlarmMessage)(target));
            return;
            case 65:
            this.PlayerSlide = ((ControlsUnit.TrimmingSlide)(target));
            
            #line 231 "..\..\MainWindow.xaml"
            this.PlayerSlide.ValueChanged += new System.Windows.RoutedPropertyChangedEventHandler<double>(this.PlayerSlide_ValueChanged);
            
            #line default
            #line hidden
            return;
            case 66:
            this.test = ((System.Windows.Controls.TextBox)(target));
            return;
            case 67:
            this.TransmitWindow = ((System.Windows.Controls.Grid)(target));
            return;
            case 68:
            
            #line 257 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.TransmitClosingButton_Click);
            
            #line default
            #line hidden
            return;
            case 69:
            this.TransmitBar = ((System.Windows.Controls.ProgressBar)(target));
            return;
            case 70:
            
            #line 261 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.TransmitButton_Click);
            
            #line default
            #line hidden
            return;
            case 71:
            
            #line 262 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.TransmitCancelButton_Click);
            
            #line default
            #line hidden
            return;
            case 72:
            this.WaitWindow = ((System.Windows.Controls.Label)(target));
            return;
            case 73:
            this.TopCanvas = ((System.Windows.Controls.Canvas)(target));
            return;
            case 74:
            this.VersionName = ((System.Windows.Controls.TextBlock)(target));
            return;
            case 75:
            
            #line 283 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.MinWindowButton_Click);
            
            #line default
            #line hidden
            return;
            case 76:
            
            #line 284 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.MaxWindowButton_Click);
            
            #line default
            #line hidden
            return;
            case 77:
            
            #line 285 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.DefaultWindowButton_Click);
            
            #line default
            #line hidden
            return;
            case 78:
            
            #line 286 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.CloseButton_Click);
            
            #line default
            #line hidden
            return;
            case 79:
            this.me1 = ((System.Windows.Controls.MediaElement)(target));
            return;
            case 80:
            this.me2 = ((System.Windows.Controls.MediaElement)(target));
            return;
            case 81:
            this.SendSound = ((System.Windows.Controls.MediaElement)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}
