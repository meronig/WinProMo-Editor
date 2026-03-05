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
    public class ProMoOutgoingEdgesAutoTest : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_OutgoingEdges_Count()
        {
            IOutgoingEdges outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            Assert.AreEqual(1, outgoingEdges.Count(), "Expected 1 outgoing edges for block A");
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdge_IDs()
        {
            IOutgoingEdges outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            string[] ids = outgoingEdges.IDs;
            Assert.IsNotNull(ids, "IDs collection is null");
            Assert.AreEqual(1, ids.Length, "Expected 1 outgoing edges for block A");
            Assert.IsTrue(ids.Contains("391"), "Expected edge x not found");
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdge_Objects_By_Position()
        {
            IOutgoingEdges outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            IEdge edge = outgoingEdges[0];
            Assert.AreEqual(edgeX, edge, "Expected edge x does not match");
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdge_Objects_By_Name()
        {
            IOutgoingEdges outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            IEdge edge = outgoingEdges["391"];
            Assert.AreEqual(edgeX, edge, "Expected edge x does not match");
        }
    }
}
