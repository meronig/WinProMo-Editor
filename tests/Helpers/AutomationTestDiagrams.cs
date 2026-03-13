using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestDiagrams : AutomationTestBase
    {

        protected IDiagram diagram1;

        [TestInitialize]
        public void Setup()
        {
            diagram1 = OpenTestDiagram1();
            Assert.IsNotNull(diagram1);
        }

        [TestCleanup]
        public void Cleanup()
        {
            try
            {
                if (diagram1 != null)
                {
                    diagram1.Close(FromBool(false));
                }
            }
            catch
            {
            }
            finally
            {
                diagram1 = null;
            }
        }

        protected IDiagram OpenTestDiagram1()
        {
            IApplication app = CreateApplication();
            IDiagrams diagrams = app.Diagrams;
            Assert.IsNotNull(diagrams);
            // Attempt to open the first diagram
            string path = Path.Combine(
                AppDomain.CurrentDomain.BaseDirectory,
                "Models",
                "DemoPlugin.wpd");
            Console.WriteLine($"Opened diagram: {path}");
            return diagrams.Open(path);
        }
    }
}
