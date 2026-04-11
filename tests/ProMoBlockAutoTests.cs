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
    public class ProMoBlockAutoTests : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Set_Block_Geometry()
        {
            Assert.AreEqual(183, blockA.Left);
            Assert.AreEqual(105, blockA.Top);
            Assert.AreEqual(490, blockA.Right);
            Assert.AreEqual(163, blockA.Bottom);
            Assert.AreEqual(307, blockA.Width);
            Assert.AreEqual(58, blockA.Height);

            double newLeft = 200;
            double newTop = 150;
            double newWidth = 500;
            double newHeight = 200;
            
            blockA.Left = newLeft;
            blockA.Top = newTop;
            blockA.Width = newWidth;
            blockA.Height = newHeight;
            
            Assert.AreEqual(newLeft, blockA.Left);
            Assert.AreEqual(newTop, blockA.Top);
            Assert.AreEqual(newWidth, blockA.Width);
            Assert.AreEqual(newHeight, blockA.Height);
            Assert.AreEqual(newLeft + newWidth, blockA.Right);
            Assert.AreEqual(newTop + newHeight, blockA.Bottom);

            double newRight = 750;
            double newBottom = 400;

            blockA.Right = newRight;
            blockA.Bottom = newBottom;

            Assert.AreEqual(newRight, blockA.Right);
            Assert.AreEqual(newBottom, blockA.Bottom);
            Assert.AreEqual(newWidth, blockA.Width);
            Assert.AreEqual(newHeight, blockA.Height);
            Assert.AreEqual(newRight - newWidth, blockA.Left);
            Assert.AreEqual(newBottom - newHeight, blockA.Top);
        }

        [STATestMethod]
        public void Can_Set_Block_Fill_Style()
        {
            uint fillColor = 1000; // White color in RGB
            bool fillPattern = true;
            short fillStyle = 3;

            blockA.FillColor = fillColor;
            blockA.FillPattern = FromBool(fillPattern);
            blockA.FillStyle = fillStyle;

            Assert.AreEqual(fillColor, blockA.FillColor);
            Assert.AreEqual(fillPattern, ToBool(blockA.FillPattern));
            Assert.AreEqual(fillStyle, blockA.FillStyle);
        }

        [STATestMethod]
        public void Can_Get_Block_Parent()
        {
            Assert.IsFalse(ToBool(blockA.IsSubBlock()), "Block A is unexpectedly a sub-block");
            Assert.IsFalse(ToBool(blockA.IsBoundaryBlock()), "Block A is unexpectedly a boundary block");
            IBlock parent = blockA.Parent;
            Assert.IsNull(parent, "Block parent is not null");

            Assert.IsTrue(ToBool(blockA1.IsSubBlock()), "Block A1 is unexpectedly not a sub-block");
            Assert.IsFalse(ToBool(blockA1.IsBoundaryBlock()), "Block A1 is unexpectedly a boundary block");
            parent = blockA1.Parent;
            Assert.IsNotNull(parent, "Block parent is null");   
            Assert.AreEqual(blockA, parent, "Block parent does not match expected block");
        }

        [STATestMethod]
        public void Can_Get_Block_Boundary_Attachment()
        {
            Assert.IsFalse(ToBool(blockA.IsBoundaryBlock()), "Block A is unexpectedly a boundary block");
            Assert.AreEqual(0, blockA.BoundaryAttachment, "Block A boundary attachment is not zero");           
        }

        [STATestMethod]
        public void Can_Get_SubBlocks_Object()
        {
            ISubBlocks subBlocks = blockA.SubBlocks;
            Assert.IsNotNull(subBlocks);
        }

        [STATestMethod]
        public void Can_Get_BoundaryBlocks_Object()
        {
            IBoundaryBlocks boundaryBlocks = blockA.BoundaryBlocks;
            Assert.IsNotNull(boundaryBlocks);
        }

        [STATestMethod]
        public void Can_Get_IncomingEdges_Object()
        {
            IIncomingEdges incomingEdges = blockA.IncomingEdges;
            Assert.IsNotNull(incomingEdges);
        }

        [STATestMethod]
        public void Can_Get_OutgoingEdges_Object()
        {
            IOutgoingEdges outgoingEdges = blockA.OutgoingEdges;
            Assert.IsNotNull(outgoingEdges);
        }
    }
}
