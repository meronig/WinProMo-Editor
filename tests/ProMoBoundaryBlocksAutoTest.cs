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
    public class ProMoBoundaryBlocksAutoTest : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_BoundaryBlocks_Count()
        {
            IBoundaryBlocks boundaryBlocks = blockB.BoundaryBlocks;
            Assert.IsNotNull(boundaryBlocks, "Boundary blocks collection is null");
            Assert.AreEqual(1, boundaryBlocks.Count(), "Expected 1 boundary blocks for block B");
        }

        [STATestMethod]
        public void Can_Get_BoundaryBlock_IDs()
        {
            IBoundaryBlocks boundaryBlocks = blockB.BoundaryBlocks;
            Assert.IsNotNull(boundaryBlocks, "Boundary blocks collection is null");
            string[] ids = boundaryBlocks.IDs;
            Assert.IsNotNull(ids, "IDs collection is null");
            Assert.AreEqual(1, ids.Length, "Expected 1 boundary blocks for block B");
            Assert.IsTrue(ids.Contains("461"), "Expected boundary block C not found");
        }

        [STATestMethod]
        public void Can_Get_BoundaryBlock_Objects_By_Position()
        {
            IBoundaryBlocks boundaryBlocks = blockB.BoundaryBlocks;
            Assert.IsNotNull(boundaryBlocks, "Boundary blocks collection is null");
            IBlock block = boundaryBlocks[0];
            Assert.AreEqual(blockC, block, "Expected boundary block C does not match");
            
        }

        [STATestMethod]
        public void Can_Get_BoundaryBlock_Objects_By_Name()
        {
            IBoundaryBlocks boundaryBlocks = blockB.BoundaryBlocks;
            Assert.IsNotNull(boundaryBlocks, "Boundary blocks collection is null");
            IBlock block = boundaryBlocks["461"];
            Assert.AreEqual(blockC, block, "Expected boundary block C does not match");
        }

        [STATestMethod]
        public void Can_Add_BoundaryBlock()
        {
            IBlock parent = blockC.Parent;
            Assert.AreEqual(blockB, parent, "Block C parent does not match block B");
            IBoundaryBlocks boundaryBlocks = blockB1.BoundaryBlocks;
            Assert.IsNotNull(boundaryBlocks, "Boundary blocks collection is null");
            bool result = ToBool(boundaryBlocks.Add(blockC, tagBoundaryAttachment.baBottom));
            Assert.IsTrue(result, "Failed to set block C as the parent of block B1");
            parent = blockC.Parent;
            Assert.AreEqual(blockB1, parent, "Block C parent was not updated to block B1");
            Assert.AreEqual(tagBoundaryAttachment.baBottom, blockC.BoundaryAttachment, "Block C boundary attachment was not set to 11");
        }

        [STATestMethod]
        public void Can_Remove_BoundaryBlock()
        {
            IBlock parent = blockC.Parent;
            Assert.AreEqual(blockB, parent, "Block C parent does not match block B");
            IBoundaryBlocks boundaryBlocks = blockB.BoundaryBlocks;
            Assert.IsNotNull(boundaryBlocks, "Boundary blocks collection is null");
            bool result = ToBool(boundaryBlocks.Remove(blockC.ID));
            Assert.IsTrue(result, "Failed to remove block C from the children of block B");
            parent = blockC.Parent;
            Assert.IsNull(parent, "Block C parent was not set to null after removal");
        }

        [STATestMethod]
        public void Can_Get_BoundaryBlocks_Diagram()
        {
            IBoundaryBlocks boundaryBlocks = blockB.BoundaryBlocks;
            Assert.IsNotNull(boundaryBlocks, "Boundary blocks collection is null");
            IDiagram diagram = boundaryBlocks.Diagram();
            Assert.AreEqual(diagram1, diagram);
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdges_Element()
        {
            IBoundaryBlocks boundaryBlocks = blockB.BoundaryBlocks;
            Assert.IsNotNull(boundaryBlocks, "Boundary blocks collection is null");
            IBlock block = boundaryBlocks.Element();
            Assert.AreEqual(blockB, block);
        }
    }
}
