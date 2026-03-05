using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoEdgeAutoTests : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_Edge_Source()
        {
            IBlock source = edgeX.Source;
            Assert.IsNotNull(source, "Edge source is null");
            Assert.AreEqual(blockA, source, "Edge source does not match expected block");
        }

        [STATestMethod]
        public void Can_Get_Edge_Destination()
        {
            IBlock dest = edgeX.Destination;
            Assert.IsNotNull(dest, "Edge destination is null");
            Assert.AreEqual(blockB1, dest, "Edge destination does not match expected block");
        }
    }
}
