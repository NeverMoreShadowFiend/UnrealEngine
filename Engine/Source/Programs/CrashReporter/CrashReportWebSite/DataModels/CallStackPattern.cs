//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Tools.CrashReporter.CrashReportWebSite.DataModels
{
    using System;
    using System.Collections.Generic;
    
    public partial class CallStackPattern
    {
        public CallStackPattern()
        {
            this.Buggs = new HashSet<Bugg>();
            this.Crashes = new HashSet<Crash>();
        }
    
        public int id { get; set; }
        public string Pattern { get; set; }
    
        public virtual ICollection<Bugg> Buggs { get; set; }
        public virtual ICollection<Crash> Crashes { get; set; }
    }
}
