using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoDiagramsAutoTests: AutomationTestBase
    {

        protected IDiagrams diagrams;
        protected IDiagram diagram1;

        [TestInitialize]
        public void Setup()
        {
            IApplication app = CreateApplication();
            diagrams = app.Diagrams;
            Assert.IsNotNull(diagrams);
        }

        [TestCleanup]
        public void Cleanup()
        {
            try
            {
                if (diagram1 != null)
                {
                    diagram1.Close(false);
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

        private void OpenDiagram()
        {
            // Attempt to open the first diagram
            string path = Path.Combine(
                AppDomain.CurrentDomain.BaseDirectory,
                "Models",
                "DemoPlugin.wpd");
            Console.WriteLine($"Opened diagram: {path}");
            diagram1 = diagrams.Open(path);
            Assert.IsNotNull(diagram1, "Failed to open diagram.");
        }

        [STATestMethod]
        public void Can_Open_Diagram()
        {
            OpenDiagram();
            Assert.IsTrue(diagrams.Count() > 0, "Expected at least one diagram to be open.");
        }

        [STATestMethod]
        public void Can_Create_Diagram()
        {
            //Commented out as the Add method requires interaction with the UI to select a diagram type, which is not possible in an automated test environment.
            IDiagram diagram = diagrams.Add("demoPlugin");
            Assert.IsNotNull(diagram, "Failed to create diagram.");
            Assert.IsTrue(diagrams.Count() > 0, "Expected at least one diagram to be open.");
            diagram.Close(false);
        }

        [STATestMethod]
        public void Can_Get_Diagram_Names()
        {
            string[] ids = diagrams.IDs;
            Assert.IsNotNull(ids, "Diagrams collection is null");
            Assert.AreEqual(0, ids.Length, "Expected 0 diagrams");
            OpenDiagram();
            ids = diagrams.IDs;
            Assert.IsNotNull(ids, "Diagrams collection is null");
            Assert.IsTrue(ids.Length > 0, "Expected at least one diagram to be open.");
        }

        [STATestMethod]
        public void Can_Get_Diagram_Objects_By_Position()
        {
            OpenDiagram();
            IDiagram diagram0 = diagrams[0];
            Assert.IsNotNull(diagram0, "First diagram is null");
            Assert.AreEqual(diagram1, diagram0, "First diagram is not the one created");
        }
    }
}
