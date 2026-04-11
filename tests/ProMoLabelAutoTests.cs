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
        public void Can_Get_Label_ID_LockFlags()
        {
            Assert.AreEqual("1174", diagramLabel.ID);
            Assert.AreEqual(0, diagramLabel.LockFlags);
        }

        [STATestMethod]
        public void Can_Set_Label_Text()
        {
            string text = "New Label Text";
            diagramLabel.Text = text;
            Assert.AreEqual(text, diagramLabel.Text);
        }

        [STATestMethod]
        public void Can_Set_Label_Text_Style()
        {
            string fontName = "Arial";
            short fontSize = 24;
            short fontWeight = 800;
            bool fontItalic = true;
            bool fontUnderline = true;
            bool fontStrikeout = true;
            uint textColor = 1000;

            diagramLabel.FontName = fontName;
            diagramLabel.FontSize = fontSize;
            diagramLabel.FontWeight = fontWeight;
            diagramLabel.FontItalic = FromBool(fontItalic);
            diagramLabel.FontUnderline = FromBool(fontUnderline);
            diagramLabel.FontStrikeOut = FromBool(fontStrikeout);
            diagramLabel.TextColor = textColor;

            Assert.AreEqual(fontName, diagramLabel.FontName);
            Assert.AreEqual(fontSize, diagramLabel.FontSize);
            Assert.AreEqual(fontWeight, diagramLabel.FontWeight);
            Assert.AreEqual(fontItalic, ToBool(diagramLabel.FontItalic));
            Assert.AreEqual(fontUnderline, ToBool(diagramLabel.FontUnderline));
            Assert.AreEqual(fontStrikeout, ToBool(diagramLabel.FontStrikeOut));
            Assert.AreEqual(textColor, diagramLabel.TextColor);
        }

        [STATestMethod]
        public void Can_Set_Label_Background_Style()
        {
            uint bkColor = 1000;
            short bkMode = 0;

            diagramLabel.BkColor = bkColor;
            diagramLabel.BkMode = bkMode;

            Assert.AreEqual(bkColor, diagramLabel.BkColor);
            Assert.AreEqual(bkMode, diagramLabel.BkMode);
        }

        [STATestMethod]
        public void Can_Set_Label_Text_Position()
        {
            short vAlign = 0;
            short hAlign = 0;
            bool multiline = true;

            diagramLabel.TextMultiLine = FromBool(multiline);
            diagramLabel.TextHorizontalAlignment = hAlign;
            diagramLabel.TextVerticalAlignment = vAlign;

            Assert.AreEqual(multiline, ToBool(diagramLabel.TextMultiLine));
            Assert.AreEqual(hAlign, diagramLabel.TextHorizontalAlignment);
            Assert.AreEqual(vAlign, diagramLabel.TextVerticalAlignment);
        }

        [STATestMethod]
        public void Can_Set_Label_Geometry()
        {
            Assert.AreEqual(97, diagramLabel.Left);
            Assert.AreEqual(47, diagramLabel.Top);
            Assert.AreEqual(153, diagramLabel.Right);
            Assert.AreEqual(62, diagramLabel.Bottom);
            Assert.AreEqual(56, diagramLabel.Width);
            Assert.AreEqual(15, diagramLabel.Height);

            double newLeft = 200;
            double newTop = 150;
            double newWidth = 500;
            double newHeight = 200;

            diagramLabel.Left = newLeft;
            diagramLabel.Top = newTop;
            diagramLabel.Width = newWidth;
            diagramLabel.Height = newHeight;

            Assert.AreEqual(newLeft, diagramLabel.Left);
            Assert.AreEqual(newTop, diagramLabel.Top);
            Assert.AreEqual(newWidth, diagramLabel.Width);
            Assert.AreEqual(newHeight, diagramLabel.Height);
            Assert.AreEqual(newLeft + newWidth, diagramLabel.Right);
            Assert.AreEqual(newTop + newHeight, diagramLabel.Bottom);

            double newRight = 750;
            double newBottom = 400;

            diagramLabel.Right = newRight;
            diagramLabel.Bottom = newBottom;

            Assert.AreEqual(newRight, diagramLabel.Right);
            Assert.AreEqual(newBottom, diagramLabel.Bottom);
            Assert.AreEqual(newWidth, diagramLabel.Width);
            Assert.AreEqual(newHeight, diagramLabel.Height);
            Assert.AreEqual(newRight - newWidth, diagramLabel.Left);
            Assert.AreEqual(newBottom - newHeight, diagramLabel.Top);
        }

        [STATestMethod]
        public void Can_Get_Label_Property()
        {
            WinProMo.IProperty property = blockATitle.Property();
            Assert.IsNotNull(property, "Property is null");
        }

        [STATestMethod]
        public void Can_Duplicate_Label()
        {
            ILabel label = diagramLabel.Duplicate();
            Assert.IsNotNull(label);
            ILabel label2 = diagram1.Labels[label.ID];
            Assert.AreEqual(label, label2);
        }

        [STATestMethod]
        public void Can_Delete_Label()
        {
            string id = diagramLabel.ID;
            diagramLabel.Delete();
            ILabel label = diagram1.Labels[id];
            Assert.IsNull(label, "Label is not null");
        }

        [STATestMethod]
        public void Can_Get_Label_Element()
        {
            IBlock block = blockATitle.Element();
            Assert.IsNotNull(block, "Element is null");
            Assert.AreEqual(blockA, block);
        }

        [STATestMethod]
        public void Can_Get_Label_Diagram()
        {
            IDiagram diagram = diagramLabel.Diagram();
            Assert.IsNotNull(diagram, "Diagram is null");
            Assert.AreEqual(diagram1, diagram);
        }
    }
}
