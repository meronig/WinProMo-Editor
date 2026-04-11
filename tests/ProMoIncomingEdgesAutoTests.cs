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
            IEdge edge = incomingEdges[1];
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

        [STATestMethod]
        public void Can_Add_IncomingEdge()
        {
            IBlock dest = edgeX.Destination;
            Assert.AreEqual(blockB1, dest, "Edge x destination does not match block B1");
            IIncomingEdges incomingEdges = blockB.IncomingEdges;
            Assert.IsNotNull(incomingEdges, "IncomingEdges collection is null");
            bool result = ToBool(incomingEdges.Add(edgeX));
            Assert.IsTrue(result, "Failed to add edge x to block B's incoming edges");
            dest = edgeX.Destination;
            Assert.AreEqual(blockB, dest, "Edge x destination was not updated to block B");
        }

        [STATestMethod]
        public void Can_Remove_IncomingEdge()
        {
            IBlock dest = edgeX.Destination;
            Assert.AreEqual(blockB1, dest, "Edge x destination does not match block B1");
            IIncomingEdges incomingEdges = blockB1.IncomingEdges;
            Assert.IsNotNull(incomingEdges, "IncomingEdges collection is null");
            bool result = ToBool(incomingEdges.Remove(edgeX.ID));
            Assert.IsTrue(result, "Failed to remove edge x from block B1's incoming edges");
            dest = edgeX.Destination;
            Assert.IsNull(dest, "Edge x destination was not set to null after removal");
        }

        [STATestMethod]
        public void Can_Get_IncomingEdges_Diagram()
        {
            IIncomingEdges incomingEdges = blockB1.IncomingEdges;
            Assert.IsNotNull(incomingEdges, "IncomingEdges collection is null");
            IDiagram diagram = incomingEdges.Diagram();
            Assert.AreEqual(diagram1, diagram);
        }

        [STATestMethod]
        public void Can_Get_IncomingEdges_Element()
        {
            IIncomingEdges incomingEdges = blockB1.IncomingEdges;
            Assert.IsNotNull(incomingEdges, "IncomingEdges collection is null");
            IBlock block = incomingEdges.Element();
            Assert.AreEqual(blockB1, block);
        }
    }
}
