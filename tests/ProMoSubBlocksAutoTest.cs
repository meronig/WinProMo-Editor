using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoSubBlocksAutoTest : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_SubBlocks_Count()
        {
            dynamic subBlocks = blockA.SubBlocks;
            Assert.IsNotNull(subBlocks, "SubBlocks collection is null");
            Assert.AreEqual(2, subBlocks.Count, "Expected 2 sub-blocks for block A");
        }

        [STATestMethod]
        public void Can_Get_SubBlock_IDs()
        {
            dynamic subBlocks = blockA.SubBlocks;
            Assert.IsNotNull(subBlocks, "SubBlocks collection is null");
            var ids = subBlocks.IDs;
            Assert.IsNotNull(ids, "IDs collection is null");
            Assert.AreEqual(2, ids.Length, "Expected 2 sub-blocks for block A");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("30"), "Expected sub-block A1 not found");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("72"), "Expected sub-block A2 not found");
        }

        [STATestMethod]
        public void Can_Get_SubBlock_Objects_By_Position()
        {
            dynamic subBlocks = blockA.SubBlocks;
            Assert.IsNotNull(subBlocks, "SubBlocks collection is null");
            dynamic block = subBlocks[0];
            Assert.AreEqual(blockA1, block, "Expected sub-block A1 does not match");
            block = subBlocks[1];
            Assert.AreEqual(blockA2, block, "Expected sub-block A2 does not match");

        }

        [STATestMethod]
        public void Can_Get_SubBlock_Objects_By_Name()
        {
            dynamic subBlocks = blockA.SubBlocks;
            Assert.IsNotNull(subBlocks, "SubBlocks collection is null");
            dynamic block = subBlocks["30"];
            Assert.AreEqual(blockA1, block, "Expected sub-block A1 does not match");
            block = subBlocks["72"];
            Assert.AreEqual(blockA2, block, "Expected sub-block A2 does not match");
        }
    }
}
