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
    public class ProMoDiagramAutoTests : AutomationTestDiagrams
    {
        [STATestMethod]
        public void Can_Set_Diagram_Size()
        {
            int width = 700;
            int height = 1000;
            diagram1.Width = width; 
            diagram1.Height = height;
            Assert.AreEqual(width, diagram1.Width, "Diagram width does not match");
            Assert.AreEqual(height, diagram1.Height, "Diagram height does not match");

        }

        [STATestMethod]
        public void Can_Get_Diagram_Type()
        {
            Assert.AreEqual("demoPlugin", diagram1.Type(), "Diagram type does not match");
        }

        [STATestMethod]
        public void Can_Get_Diagram_Path()
        {
            Assert.AreNotEqual("", diagram1.Path(), "Diagram path is empty");
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

        [STATestMethod]
        public void Can_Get_Elements_Object()
        {
            IElements elements = diagram1.Elements;
            Assert.IsNotNull(elements);
        }

        [STATestMethod]
        public void Can_Get_Labels_Object()
        {
            ILabels labels = diagram1.Labels;
            Assert.IsNotNull(labels);
        }

        [STATestMethod]
        public void Can_Close_Diagram()
        {
            diagram1.Close(FromBool(false));
            try
            {
                diagram1.Width = 100;
                Assert.AreNotEqual(100, diagram1.Width);
            } catch { 
                
            }
        }

        [STATestMethod]
        public void Can_Undo_Redo_Changes()
        {
            int oldWidth = 700;
            diagram1.Width = oldWidth;
            int newWidth = 900;
            diagram1.Width = newWidth;
            Assert.AreEqual(newWidth, diagram1.Width, "Diagram width does not match");
            diagram1.Undo(1);
            Assert.AreEqual(oldWidth, diagram1.Width, "Undo failed");
            diagram1.Redo(1);
            Assert.AreEqual(newWidth, diagram1.Width, "Redo failed");
        }
    }
}
