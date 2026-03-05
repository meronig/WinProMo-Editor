using Microsoft.Testing.Platform.Extensions.Messages;
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
    public class ProMoLabelAutoTest : AutomationTestLabels
    {

        [STATestMethod]
        public void Can_Get_Label_Text_Style()
        {
            Assert.AreEqual("Courier New", blockA.FontName);
            Assert.AreEqual(12, blockA.FontSize);
            Assert.AreEqual(400, blockA.FontWeight);
            Assert.IsFalse(blockA.FontItalic);
            Assert.IsFalse(blockA.FontUnderline);
            Assert.IsFalse(blockA.FontStrikeOut);
            Assert.AreEqual((uint)0, blockA.TextColor);
        }

        [STATestMethod]
        public void Can_Get_Label_Background_Style()
        {
            Assert.AreEqual((uint)16777215, blockA.BkColor);
            Assert.AreEqual(1, blockA.BkMode);
        }

        [STATestMethod]
        public void Can_Get_Label_Text_Position()
        {
            Assert.IsFalse(blockA.TextMultiLine);
            Assert.AreEqual(1, blockA.TextHorizontalAlignment);
            Assert.AreEqual(4, blockA.TextVerticalAlignment);
        }

        [STATestMethod]
        public void Can_Get_Label_Geometry()
        {
            Assert.AreEqual(183, blockA.Left);
            Assert.AreEqual(105, blockA.Top);
            Assert.AreEqual(490, blockA.Right);
            Assert.AreEqual(163, blockA.Bottom);
            Assert.AreEqual(307, blockA.Width);
            Assert.AreEqual(58, blockA.Height);
        }

        [STATestMethod]
        public void Can_Get_Label_Property()
        {
            WinProMo.IProperty property = blockATitle.Property;
            Assert.IsNotNull(property, "Property is null");
        }
    }
}
