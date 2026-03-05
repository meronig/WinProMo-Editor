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
    }
}
