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

        private string _testDir;


        [TestInitialize]
        public void Setup()
        {
            IApplication app = CreateApplication();
            diagrams = app.Diagrams;
            Assert.IsNotNull(diagrams);
            _testDir = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            Directory.CreateDirectory(_testDir);
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

            for (int i = 0; i < 3; i++)
            {
                try
                {
                    Directory.Delete(_testDir, true);
                    break;
                }
                catch
                {
                    System.Threading.Thread.Sleep(50);
                }
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
            IDiagram diagram1 = diagrams.Add("demoPlugin");
            Assert.IsNotNull(diagram1, "Failed to create diagram.");
            Assert.IsTrue(diagrams.Count() > 0, "Expected at least one diagram to be open.");
            diagram1.Close(FromBool(false));
            diagram1.Application().Quit(FromBool(false));
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

        [STATestMethod]
        public void Can_Save_Diagrams()
        {
            IDiagram diagram1 = diagrams.Add("demoPlugin");
            Assert.IsNotNull(diagram1, "Failed to create diagram.");
            Assert.IsTrue(diagrams.Count() > 0, "Expected at least one diagram to be open.");

            string filePath = Path.Combine(_testDir, "test.wpd");

            diagram1.SaveAs(filePath);
            Assert.IsTrue(File.Exists(filePath), "File was not created.");
            Assert.IsTrue(new FileInfo(filePath).Length > 0, "File is empty.");

            DateTime firstWrite = File.GetLastWriteTime(filePath);

            diagram1.Width += 100; // Make a change to ensure the diagram is dirty

            System.Threading.Thread.Sleep(1100);

            diagrams.Save(FromBool(true));

            DateTime secondWrite = File.GetLastWriteTime(filePath);
            
            diagram1.Close(FromBool(false));
            diagram1.Application().Quit(FromBool(false));

            Assert.IsTrue(secondWrite > firstWrite, $"Expected timestamp to increase. Before: {firstWrite}, After: {secondWrite}");

        }
    }
}
