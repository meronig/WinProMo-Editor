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
            IEdge edge = outgoingEdges[1];
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

        [STATestMethod]
        public void Can_Add_OutgoingEdge()
        {
            IBlock src = edgeX.Source;
            Assert.AreEqual(blockA, src, "Edge x source does not match block A");
            IOutgoingEdges outgoingEdges = blockA1.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            bool result = ToBool(outgoingEdges.Add(edgeX));
            Assert.IsTrue(result, "Failed to add edge x to block A1's outgoing edges");
            src = edgeX.Source;
            Assert.AreEqual(blockA1, src, "Edge x destination was not updated to block A1");
        }

        [STATestMethod]
        public void Can_Remove_OutgoingEdge()
        {
            IBlock src = edgeX.Source;
            Assert.AreEqual(blockA, src, "Edge x source does not match block A");
            IOutgoingEdges outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            bool result = ToBool(outgoingEdges.Remove(edgeX.ID));
            Assert.IsTrue(result, "Failed to remove edge x from block A's incoming edges");
            src = edgeX.Source;
            Assert.IsNull(src, "Edge x source was not set to null after removal");
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdges_Diagram()
        {
            IOutgoingEdges outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            IDiagram diagram = outgoingEdges.Diagram();
            Assert.AreEqual(diagram1, diagram);
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdges_Element()
        {
            IOutgoingEdges outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges, "OutgoingEdges collection is null");
            IBlock block = outgoingEdges.Element();
            Assert.AreEqual(blockA, block);
        }
    }
}
