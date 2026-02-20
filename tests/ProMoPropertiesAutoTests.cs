using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoPropertiesAutoTest : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_Properties_Count()
        {
            dynamic properties = blockA.properties;
            Assert.IsNotNull(properties, "properties collection is null");
            Assert.AreEqual(1, properties.Count, "Expected 1 properties for block A");
        }

        [STATestMethod]
        public void Can_Get_Property_Names()
        {
            dynamic properties = blockA.properties;
            Assert.IsNotNull(properties, "properties collection is null");
            var names = properties.Names;
            Assert.IsNotNull(names, "Names collection is null");
            Assert.AreEqual(1, names.Length, "Expected 1 properties for block A");
            Assert.IsTrue(((object[])names).Cast<string>().Contains("Title"), "Expected property Title not found");
        }

        [STATestMethod]
        public void Can_Get_Property_Objects_By_Position()
        {
            dynamic properties = blockA.properties;
            Assert.IsNotNull(properties, "properties collection is null");
            dynamic property = properties[0];
            Assert.IsNotNull(property, "first property is null");
        }

        [STATestMethod]
        public void Can_Get_Property_Objects_By_Name()
        {
            dynamic properties = blockA.properties;
            Assert.IsNotNull(properties, "properties collection is null");
            dynamic property = properties["Title"];
            Assert.IsNotNull(property, "property Title is null");
        }
    }
}
