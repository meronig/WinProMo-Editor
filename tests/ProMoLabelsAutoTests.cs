using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoLabelsAutoTest : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_Labels_Count()
        {
            dynamic labels = blockB1.Labels;
            Assert.IsNotNull(labels, "Labels collection is null");
            Assert.AreEqual(1, labels.Count, "Expected 1 label for block B1");
        }

        [STATestMethod]
        public void Can_Get_Label_IDs()
        {
            dynamic labels = blockB1.Labels;
            Assert.IsNotNull(labels, "Labels collection is null");
            var ids = labels.IDs;
            Assert.IsNotNull(ids, "IDs collection is null");
            Assert.AreEqual(1, ids.Length, "Expected 1 label for block B1");
            Assert.IsTrue(((object[])ids).Cast<string>().Contains("2975"), "Expected label not found");
        }

        [STATestMethod]
        public void Can_Get_Label_Objects_By_Position()
        {
            dynamic labels = blockB1.Labels;
            Assert.IsNotNull(labels, "Labels collection is null");
            dynamic label = labels[0];
            Assert.IsNotNull(label, "Label is null");
        }

        [STATestMethod]
        public void Can_Get_Label_Objects_By_Name()
        {
            dynamic labels = blockB1.Labels;
            Assert.IsNotNull(labels, "Labels collection is null");
            dynamic label = labels["2975"];
            Assert.IsNotNull(label, "Label is null");
        }
    }
}
