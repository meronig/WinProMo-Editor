using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoElementAutoTests : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_Element_ID_Type()
        {
            Assert.AreEqual("promo_block_view", blockA.Type, "Block type does not match");
            Assert.AreEqual("4", blockA.ID);
        }

        [STATestMethod]
        public void Can_Get_Element_Line_Style()
        {
            Assert.AreEqual((uint)0, blockA.LineColor);
            Assert.AreEqual(1, blockA.LineWidth);
            Assert.AreEqual(1, blockA.LineStyle);
        }

        [STATestMethod]
        public void Can_Get_Element_Text_Style()
        {
            Assert.AreEqual("Courier New", blockA.FontName);
            Assert.AreEqual(12, blockA.FontSize);
            Assert.AreEqual(400, blockA.FontWeight);
            Assert.IsFalse(ToBool(blockA.FontItalic));
            Assert.IsFalse(ToBool(blockA.FontUnderline));
            Assert.IsFalse(ToBool(blockA.FontStrikeOut));
            Assert.AreEqual((uint)0, blockA.TextColor);
        }

        [STATestMethod]
        public void Can_Get_Element_Background_Style()
        {
            Assert.AreEqual((uint)16777215, blockA.BkColor);
            Assert.AreEqual(1, blockA.BkMode);
        }

        [STATestMethod]
        public void Can_Get_Element_Text_Position()
        {
            Assert.IsFalse(ToBool(blockA.TextMultiLine));
            Assert.AreEqual(1, blockA.TextHorizontalAlignment);
            Assert.AreEqual(4, blockA.TextVerticalAlignment);
        }
    }
}
