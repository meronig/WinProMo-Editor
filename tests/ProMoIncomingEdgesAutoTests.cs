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
    public class ProMoIncomingEdgesAutoTest : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_IncomingEdges_Count()
        {
            IIncomingEdges incomingEdges = blockB1.IncomingEdges;
            Assert.IsNotNull(incomingEdges, "IncomingEdges collection is null");
            Assert.AreEqual(1, incomingEdges.Count(), "Expected 1 incoming edges for block B1");
        }

        [STATestMethod]
        public void Can_Get_IncomingEdge_IDs()
        {
            IIncomingEdges incomingEdges = blockB1.IncomingEdges;
            Assert.IsNotNull(incomingEdges, "IncomingEdges collection is null");
            string[] ids = incomingEdges.IDs;
            Assert.IsNotNull(ids, "IDs collection is null");
            Assert.AreEqual(1, ids.Length, "Expected 1 incoming edges for block B1");
            Assert.IsTrue(ids.Contains("391"), "Expected edge x not found");
        }

        [STATestMethod]
        public void Can_Get_IncomingEdge_Objects_By_Position()
        {
            IIncomingEdges incomingEdges = blockB1.IncomingEdges;
            Assert.IsNotNull(incomingEdges, "IncomingEdges collection is null");
            IEdge edge = incomingEdges[0];
            Assert.AreEqual(edgeX, edge, "Expected edge x does not match");
        }

        [STATestMethod]
        public void Can_Get_IncomingEdge_Objects_By_Name()
        {
            IIncomingEdges incomingEdges = blockB1.IncomingEdges;
            Assert.IsNotNull(incomingEdges, "IncomingEdges collection is null");
            IEdge edge = incomingEdges["391"];
            Assert.AreEqual(edgeX, edge, "Expected edge x does not match");
        }
    }
}
