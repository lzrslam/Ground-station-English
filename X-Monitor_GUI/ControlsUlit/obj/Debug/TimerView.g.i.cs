﻿#pragma checksum "..\..\TimerView.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "9BCAE3023FE8481EE6F167272FEBED78"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.18444
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
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


namespace ControlsUnit {
    
    
    /// <summary>
    /// TimerView
    /// </summary>
    public partial class TimerView : System.Windows.Controls.UserControl, System.Windows.Markup.IComponentConnector {
        
        
        #line 8 "..\..\TimerView.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Border ControlsUnitBorder;
        
        #line default
        #line hidden
        
        
        #line 12 "..\..\TimerView.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label TotalVal;
        
        #line default
        #line hidden
        
        
        #line 15 "..\..\TimerView.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label ConnectName;
        
        #line default
        #line hidden
        
        
        #line 16 "..\..\TimerView.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label cTimerVal;
        
        #line default
        #line hidden
        
        
        #line 20 "..\..\TimerView.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label mTimerVal;
        
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
            System.Uri resourceLocater = new System.Uri("/ControlsUnit;component/timerview.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\TimerView.xaml"
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
            this.ControlsUnitBorder = ((System.Windows.Controls.Border)(target));
            return;
            case 2:
            this.TotalVal = ((System.Windows.Controls.Label)(target));
            
            #line 12 "..\..\TimerView.xaml"
            this.TotalVal.MouseDoubleClick += new System.Windows.Input.MouseButtonEventHandler(this.TotalVal_MouseDoubleClick);
            
            #line default
            #line hidden
            return;
            case 3:
            this.ConnectName = ((System.Windows.Controls.Label)(target));
            return;
            case 4:
            this.cTimerVal = ((System.Windows.Controls.Label)(target));
            
            #line 16 "..\..\TimerView.xaml"
            this.cTimerVal.MouseDoubleClick += new System.Windows.Input.MouseButtonEventHandler(this.cTimerVal_MouseDoubleClick);
            
            #line default
            #line hidden
            return;
            case 5:
            this.mTimerVal = ((System.Windows.Controls.Label)(target));
            
            #line 20 "..\..\TimerView.xaml"
            this.mTimerVal.MouseDoubleClick += new System.Windows.Input.MouseButtonEventHandler(this.TimerVal_MouseDoubleClick);
            
            #line default
            #line hidden
            return;
            }
            this._contentLoaded = true;
        }
    }
}

