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
        public void Can_Set_Edge_Source()
        {
            IBlock source = edgeX.Source;
            Assert.IsNotNull(source, "Edge source is null");
            Assert.AreEqual(blockA, source, "Edge source does not match expected block");
            edgeX.Source = blockA1;
            IBlock newSource = edgeX.Source;
            Assert.AreNotEqual(newSource, source, "Edge source was not updated correctly");
            Assert.AreEqual(blockA1, newSource, "Edge source was not updated correctly");
        }

        [STATestMethod]
        public void Can_Set_Edge_Destination()
        {
            IBlock dest = edgeX.Destination;
            Assert.IsNotNull(dest, "Edge destination is null");
            Assert.AreEqual(blockB1, dest, "Edge destination does not match expected block");
            edgeX.Destination = blockB;
            IBlock newDest = edgeX.Destination;
            Assert.AreNotEqual(newDest, dest, "Edge destination was not updated correctly");
            Assert.AreEqual(blockB, newDest, "Edge destination was not updated correctly");
        }

        [STATestMethod]
        public void Can_Get_Segments_Object()
        {
            IEdgeSegments segments = edgeX.Segments;
            Assert.IsNotNull(segments);
        }
    }
}
