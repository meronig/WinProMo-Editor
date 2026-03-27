using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoAppAutoTests : AutomationTestBase
    {
        [STATestMethod]
        public void Can_Create_Application_Object()
        {
            IApplication app = CreateApplication();
            Assert.IsNotNull(app);
        }
        
        [STATestMethod]
        public void Can_Get_Creatable_Diagrams()
        {
            IApplication app = CreateApplication();
            string[] diagrams = app.CreatableDiagramTypes;
            Assert.IsNotNull(diagrams);
            Assert.IsTrue(diagrams.Length > 0, "Expected at least one creatable diagram.");
        }

        [STATestMethod]
        public void Can_Get_Diagrams_Object()
        {
            IApplication app = CreateApplication();
            IDiagrams diagrams = app.Diagrams;
            Assert.IsNotNull(diagrams);
        }

        [STATestMethod]
        public void Can_Get_Active_Document_Object()
        {
            IApplication app = CreateApplication();
            IDiagram diagram = app.Diagrams.Add("demoPlugin"); 
            Assert.IsNotNull(diagram);
            IDiagram activeDiagram = app.ActiveDocument();
            Assert.IsNotNull(activeDiagram);
            Assert.AreEqual(activeDiagram, diagram);
            activeDiagram.Close(FromBool(false));
            app.Quit(FromBool(false));
        }
    }
}
