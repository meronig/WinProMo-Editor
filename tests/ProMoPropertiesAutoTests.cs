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
    public class ProMoPropertiesAutoTest : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_Properties_Count()
        {
            IProperties properties = blockA.Properties;
            Assert.IsNotNull(properties, "properties collection is null");
            Assert.AreEqual(1, properties.Count(), "Expected 1 properties for block A");
        }

        [STATestMethod]
        public void Can_Get_Property_Names()
        {
            IProperties properties = blockA.Properties;
            Assert.IsNotNull(properties, "properties collection is null");
            string[] names = properties.Names;
            Assert.IsNotNull(names, "Names collection is null");
            Assert.AreEqual(1, names.Length, "Expected 1 properties for block A");
            Assert.IsTrue(names.Contains("Title"), "Expected property Title not found");
        }

        [STATestMethod]
        public void Can_Get_Property_Objects_By_Position()
        {
            IProperties properties = blockA.Properties;
            Assert.IsNotNull(properties, "properties collection is null");
            IProperty property = properties[0];
            Assert.IsNotNull(property, "first property is null");
        }

        [STATestMethod]
        public void Can_Get_Property_Objects_By_Name()
        {
            IProperties properties = blockA.Properties;
            Assert.IsNotNull(properties, "properties collection is null");
            IProperty property = properties["Title"];
            Assert.IsNotNull(property, "property Title is null");
        }

        [STATestMethod]
        public void Can_Get_Properties_Diagram()
        {
            IProperties properties = blockA.Properties;
            Assert.IsNotNull(properties, "properties collection is null");
            IDiagram diagram = properties.Diagram();
            Assert.AreEqual(diagram1, diagram);
        }

        [STATestMethod]
        public void Can_Get_Properties_Element()
        {
            IProperties properties = blockA.Properties;
            Assert.IsNotNull(properties, "properties collection is null");
            IBlock block = properties.Element();
            Assert.AreEqual(blockA, block);
        }
    }
}
