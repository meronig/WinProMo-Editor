using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoDiagramAutoTests : AutomationTestDiagrams
    {
        [STATestMethod]
        public void Can_Get_Diagram_Size()
        {
            Assert.AreEqual(762, diagram1.Width, "Diagram width does not match");
            Assert.AreEqual(1091, diagram1.Height, "Diagram height does not match");

        }

        [STATestMethod]
        public void Can_Get_Diagram_Type()
        {
            Assert.AreEqual("demoPlugin", diagram1.Type(), "Diagram type does not match");
        }

        [STATestMethod]
        public void Can_Get_Creatable_Element_Types()
        {
            string[] types = diagram1.CreatableElementTypes;
            Assert.IsNotNull(types);
            Assert.IsTrue(types.Length > 0, "Expected at least one creatable element type");
            Assert.IsTrue(types.Contains("promo_block_view"), "Expected creatable element type 'promo_block_view' not found");
            Assert.IsTrue(types.Contains("promo_edge_view"), "Expected creatable element type 'promo_edge_view' not found");

        }

    }
}
