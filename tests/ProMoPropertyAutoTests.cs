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
    public class ProMoPropertyAutoTest : AutomationTestProperties
    {
        [STATestMethod]
        public void Can_Get_Property_Info()
        {
            Assert.AreEqual("Title", blockATitle.Name, "property name does not correspond");
            Assert.AreEqual(3, blockATitle.Type, "property type does not correspond");
            Assert.IsFalse(blockATitle.IsReadOnly(), "property is read-only");
            Assert.IsFalse(blockATitle.IsMultivalue(), "property is multivalue");
            Assert.IsFalse(blockATitle.IsComposite(), "property is composite");
        }

        [STATestMethod]
        public void Can_Get_Property_Value()
        {
            Assert.AreEqual("A", blockATitle.Value, "property value does not correspond");
        }

        [STATestMethod]
        public void Can_Get_Property_Children_Count()
        {
            Assert.AreEqual(0, blockATitle.Count(), "Expected 0 child properties");
        }

        [STATestMethod]
        public void Can_Get_Property_Child_Names()
        {
            string[] names = blockATitle.ChildNames;
            Assert.IsNotNull(names, "Names collection is null");
            Assert.AreEqual(0, names.Length, "Expected 0 child properties");
        }

        [STATestMethod]
        public void Can_Get_Property_Label()
        {
            ILabel label = blockATitle.Label();
            Assert.IsNotNull(label, "Names collection is null");
        }
    }
}
