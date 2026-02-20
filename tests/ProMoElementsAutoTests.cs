using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoElementsAutoTests : AutomationTestDiagrams
    {
        [STATestMethod]
        public void Can_Get_Elements_Count()
        {
            dynamic elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            Assert.AreEqual(8, elements.Count, "Expected 8 elements in the diagram");
        }

        [STATestMethod]
        public void Can_Get_Element_IDs()
        {
            dynamic elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            var ids = elements.IDs;
            Assert.IsNotNull(ids, "IDs collection is null");
            Assert.AreEqual(8, ids.Length, "Expected 8 elements in the diagram");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("4"), "Expected element 4 not found");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("30"), "Expected element 30 not found");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("72"), "Expected element 72 not found");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("15"), "Expected element 15 not found");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("522"), "Expected element 522 not found");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("49"), "Expected element 49 not found");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("391"), "Expected element 391 not found");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("119"), "Expected element 119 not found");

        }

        [STATestMethod]
        public void Can_Get_Element_Objects_By_Position()
        {
            dynamic elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            dynamic block = elements[0];
            Assert.IsNotNull(block, "Element at position 0 is null");
            Assert.AreEqual("4", block.ID, "Expected element A does not match");
            block = elements[1];
            Assert.IsNotNull(block, "Element at position 0 is null");
            Assert.AreEqual("30", block.ID, "Expected element A does not match");

        }

        [STATestMethod]
        public void Can_Get_Element_Objects_By_Name()
        {
            dynamic elements = diagram1.Elements;
            Assert.IsNotNull(elements, "Elements collection is null");
            dynamic block = elements["4"];
            Assert.IsNotNull(block, "Element A is null");
            Assert.AreEqual("4", block.ID, "Expected element A does not match");
            block = elements["30"];
            Assert.IsNotNull(block, "Element A1 is null");
            Assert.AreEqual("30", block.ID, "Expected element A1 does not match");
        }
    }
}
