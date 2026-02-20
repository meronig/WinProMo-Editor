using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoBlockAutoTests : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_Block_Geometry()
        {
            Assert.AreEqual(183, blockA.Left);
            Assert.AreEqual(105, blockA.Top);
            Assert.AreEqual(490, blockA.Right);
            Assert.AreEqual(163, blockA.Bottom);
            Assert.AreEqual(307, blockA.Width);
            Assert.AreEqual(58, blockA.Height);
        }

        [STATestMethod]
        public void Can_Get_Block_Fill_Style()
        {
            Assert.AreEqual(16777215, blockA.FillColor);
            Assert.IsFalse(blockA.FillPattern);
            Assert.AreEqual(4, blockA.FillStyle);
        }

        [STATestMethod]
        public void Can_Get_Block_Parent()
        {
            Assert.IsFalse(blockA.IsSubBlock, "Block A is unexpectedly a sub-block");
            dynamic parent = blockA.Parent;
            Assert.IsNull(parent, "Block parent is not null");

            Assert.IsTrue(blockA1.IsSubBlock, "Block A1 is unexpectedly not a sub-block");
            parent = blockA1.Parent;
            Assert.IsNotNull(parent, "Block parent is null");   
            Assert.AreEqual(blockA, parent, "Block parent does not match expected block");
        }
    }
}
