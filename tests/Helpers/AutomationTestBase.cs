using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestBase
    {
        protected dynamic CreateApplication()
        {
            Type t = Type.GetTypeFromProgID("WinProMo.Application");
            Assert.IsNotNull(t, "ProgID not registered.");

            return Activator.CreateInstance(t);
        }

        protected void ReleaseComObject(object obj)
        {
            if (obj != null)
                System.Runtime.InteropServices.Marshal.ReleaseComObject(obj);
        }
    }
}
