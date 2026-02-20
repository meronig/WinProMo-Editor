using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoOutgoingEdgesAutoTest : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_OutgoingEdges_Count()
        {
            dynamic outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            Assert.AreEqual(1, outgoingEdges.Count, "Expected 1 outgoing edges for block A");
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdge_IDs()
        {
            dynamic outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            var ids = outgoingEdges.IDs;
            Assert.IsNotNull(ids, "IDs collection is null");
            Assert.AreEqual(1, ids.Length, "Expected 1 outgoing edges for block A");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("391"), "Expected edge x not found");
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdge_Objects_By_Position()
        {
            dynamic outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            dynamic edge = outgoingEdges[0];
            Assert.AreEqual(edgeX, edge, "Expected edge x does not match");
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdge_Objects_By_Name()
        {
            dynamic outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            dynamic edge = outgoingEdges["391"];
            Assert.AreEqual(edgeX, edge, "Expected edge x does not match");
        }
    }
}
