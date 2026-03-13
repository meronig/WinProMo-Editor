using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Hosting;
using System.Text;
using System.Threading.Tasks;
using WinProMo;
using WinProMo_App;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestBase
    {
        protected IApplication CreateApplication()
        {
            Type t = Type.GetTypeFromProgID("WinProMo.Application");
            Assert.IsNotNull(t, "ProgID not registered.");

            return (IApplication)Activator.CreateInstance(t);
        }

        protected void ReleaseComObject(object obj)
        {
            if (obj != null)
                System.Runtime.InteropServices.Marshal.ReleaseComObject(obj);
        }

        public static bool ToBool(sbyte value)
        {
            return value != 0;
        }

        public static sbyte FromBool(bool value)
        {
            return value ? (sbyte)1 : (sbyte)0;
        }
    }
}
