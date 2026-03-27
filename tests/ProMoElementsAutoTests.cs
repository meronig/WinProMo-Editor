using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using WinProMo;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoElementsAutoTests : AutomationTestDiagrams
    {
        [STATestMethod]
        public void Can_Get_Elements_Count()
        {
            IElements elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            Assert.AreEqual(8, elements.Count(), "Expected 8 elements in the diagram");
        }

        [STATestMethod]
        public void Can_Get_Element_IDs()
        {
            IElements elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            string[] ids = elements.IDs;
            Assert.IsNotNull(ids, "IDs collection is null");
            Assert.AreEqual(8, ids.Length, "Expected 8 elements in the diagram");
            Assert.IsTrue(ids.Contains("4"), "Expected element 4 not found");
            Assert.IsTrue(ids.Contains("30"), "Expected element 30 not found");
            Assert.IsTrue(ids.Contains("72"), "Expected element 72 not found");
            Assert.IsTrue(ids.Contains("15"), "Expected element 15 not found");
            Assert.IsTrue(ids.Contains("522"), "Expected element 522 not found");
            Assert.IsTrue(ids.Contains("49"), "Expected element 49 not found");
            Assert.IsTrue(ids.Contains("391"), "Expected element 391 not found");
            Assert.IsTrue(ids.Contains("119"), "Expected element 119 not found");

        }

        [STATestMethod]
        public void Can_Get_Element_Objects_By_Position()
        {
            IElements elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            IBlock block = elements[0];
            Assert.IsNotNull(block, "Element at position 0 is null");
            Assert.AreEqual("4", block.ID, "Expected element A does not match");
            block = elements[1];
            Assert.IsNotNull(block, "Element at position 0 is null");
            Assert.AreEqual("30", block.ID, "Expected element A does not match");

        }

        [STATestMethod]
        public void Can_Get_Element_Objects_By_Name()
        {
            IElements elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            IBlock block = elements["4"];
            Assert.IsNotNull(block, "Element A is null");
            Assert.AreEqual("4", block.ID, "Expected element A does not match");
            block = elements["30"];
            Assert.IsNotNull(block, "Element A1 is null");
            Assert.AreEqual("30", block.ID, "Expected element A1 does not match");
        }

        [STATestMethod]
        public void Can_Add_Element()
        {
            IElements elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            IBlock block = elements.Add("promo_block_view");
            Assert.IsNotNull(block, "Element is null");
            IBlock block2 = elements[block.ID];
            Assert.AreEqual(block,block2);
        }

        [STATestMethod]
        public void Can_Remove_Element()
        {
            IElements elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            IBlock block = elements["4"];
            Assert.IsNotNull(block, "Element A is null");
            bool result = ToBool(elements.Remove("4"));
            Assert.IsTrue(result);
            block = elements["2975"];
            Assert.IsNull(block, "Block is not null");
        }
        
        [STATestMethod]
        public void Can_Get_Label_Element()
        {
            IElements elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            IBlock block = elements["4"];
            Assert.IsNotNull(block, "Element A is null");
            IDiagram diagram = block.Diagram();
            Assert.AreEqual(diagram1, diagram);
        }
    }
}
