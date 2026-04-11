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
    public class ProMoElementAutoTests : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_Element_ID_Type_LockFlags()
        {
            Assert.AreEqual("promo_block_view", blockA.Type, "Block type does not match");
            Assert.AreEqual("4", blockA.ID);
            Assert.AreEqual(0, blockA.LockFlags);
        }

        [STATestMethod]
        public void Can_Set_Element_Line_Style()
        {
            uint lineColor = 1000;
            short lineWidth = 2;
            tagLineStyle lineStyle = tagLineStyle.lsDotted;

            blockA.LineColor = lineColor;
            blockA.LineWidth = lineWidth;
            blockA.LineStyle = lineStyle;

            Assert.AreEqual(lineColor, blockA.LineColor);
            Assert.AreEqual(lineWidth, blockA.LineWidth);
            Assert.AreEqual(lineStyle, blockA.LineStyle);
        }

        [STATestMethod]
        public void Can_Set_Element_Text_Style()
        {
            string fontName = "Arial";
            short fontSize = 24;
            short fontWeight = 800;
            bool fontItalic = true;
            bool fontUnderline = true;
            bool fontStrikeout = true;
            uint textColor = 1000;

            blockA.FontName = fontName;
            blockA.FontSize = fontSize;
            blockA.FontWeight = fontWeight;
            blockA.FontItalic = FromBool(fontItalic);
            blockA.FontUnderline = FromBool(fontUnderline);
            blockA.FontStrikeOut = FromBool(fontStrikeout);
            blockA.TextColor = textColor;

            Assert.AreEqual(fontName, blockA.FontName);
            Assert.AreEqual(fontSize, blockA.FontSize);
            Assert.AreEqual(fontWeight, blockA.FontWeight);
            Assert.AreEqual(fontItalic, ToBool(blockA.FontItalic));
            Assert.AreEqual(fontUnderline, ToBool(blockA.FontUnderline));
            Assert.AreEqual(fontStrikeout, ToBool(blockA.FontStrikeOut));
            Assert.AreEqual(textColor, blockA.TextColor);
        }

        [STATestMethod]
        public void Can_Set_Element_Background_Style()
        {
            uint bkColor = 1000;
            tagBkMode bkMode = tagBkMode.bkTransparent;

            blockA.BkColor = bkColor;
            blockA.BkMode = bkMode;

            Assert.AreEqual(bkColor, blockA.BkColor);
            Assert.AreEqual(bkMode, blockA.BkMode);
        }

        [STATestMethod]
        public void Can_Set_Element_Text_Position()
        {
            tagHorizontalAlignment hAlign = tagHorizontalAlignment.haLeft;
            tagVerticalAlignment vAlign = tagVerticalAlignment.vaTop;
            bool multiline = true;

            blockA.TextMultiLine = FromBool(multiline);
            blockA.TextHorizontalAlignment = hAlign;
            blockA.TextVerticalAlignment = vAlign;

            Assert.AreEqual(multiline, ToBool(blockA.TextMultiLine));
            Assert.AreEqual(hAlign, blockA.TextHorizontalAlignment);
            Assert.AreEqual(vAlign, blockA.TextVerticalAlignment);
        }

        [STATestMethod]
        public void Can_Get_Labels_Object()
        {
            ILabels elements = blockA.Labels;
            Assert.IsNotNull(elements);
        }

        [STATestMethod]
        public void Can_Get_Properties_Object()
        {
            IProperties properties = blockA.Properties;
            Assert.IsNotNull(properties);
        }

        [STATestMethod]
        public void Can_Duplicate_Element()
        {
            IBlock block = blockA.Duplicate();
            Assert.IsNotNull(block);
            IBlock block2 = diagram1.Elements[block.ID];
            Assert.AreEqual(block, block2);
        }

        [STATestMethod]
        public void Can_Delete_Element()
        {
            string id = blockA.ID;
            blockA.Delete();
            IBlock block = diagram1.Elements[id];
            Assert.IsNull(block, "Block is not null");
        }

        [STATestMethod]
        public void Can_Get_Element_Diagram()
        {
            IDiagram diagram = blockA.Diagram();
            Assert.IsNotNull(diagram, "Diagram is null");
            Assert.AreEqual(diagram1, diagram);
        }
    }
}
