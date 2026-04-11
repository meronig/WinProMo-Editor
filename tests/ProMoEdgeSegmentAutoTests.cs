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
    public class ProMoEdgeSegmentAutoTests : AutomationTestSegments
    {
        [STATestMethod]
        public void Can_Set_Segment_Geometry()
        {
            Assert.AreEqual(211, segmentX1.StartX);
            Assert.AreEqual(163, segmentX1.StartY);
            Assert.AreEqual(210, segmentX1.EndX);
            Assert.AreEqual(275, segmentX1.EndY);
            Assert.AreEqual(1, segmentX1.Width);
            Assert.AreEqual(112, segmentX1.Height);

            Assert.AreEqual(210, segmentX2.StartX);
            Assert.AreEqual(275, segmentX2.StartY);
            Assert.AreEqual(340, segmentX2.EndX);
            Assert.AreEqual(266, segmentX2.EndY);
            Assert.AreEqual(130, segmentX2.Width);
            Assert.AreEqual(9, segmentX2.Height);

            double newStartX = 220;
            double newStartY = 170;

            segmentX2.StartX = newStartX;
            segmentX2.StartY = newStartY;

            Assert.AreEqual(newStartX, segmentX2.StartX);
            Assert.AreEqual(newStartY, segmentX2.StartY);
            Assert.AreEqual(newStartX, segmentX1.EndX);
            Assert.AreEqual(newStartY, segmentX1.EndY);

            Assert.AreEqual(211, segmentX1.StartX);
            Assert.AreEqual(163, segmentX1.StartY);
            Assert.AreEqual(340, segmentX2.EndX);
            Assert.AreEqual(266, segmentX2.EndY);

        }

        [STATestMethod]
        public void Can_Get_Next_Segment()
        {
            IEdgeSegment next = segmentX1.Next();
            Assert.IsNotNull(next);
            Assert.AreEqual(segmentX2, next);

            next = segmentX2.Next();
            Assert.IsNull(next);

        }

        [STATestMethod]
        public void Can_Get_Prev_Segment()
        {
            IEdgeSegment prev = segmentX2.Prev();
            Assert.IsNotNull(prev);
            Assert.AreEqual(segmentX1, prev);

            prev = segmentX1.Prev();
            Assert.IsNull(prev);

        }

        [STATestMethod]
        public void Can_Split_Segment()
        {
            IEdgeSegment newSeg = segmentX1.Split();
            Assert.IsNotNull(newSeg);
            IEdgeSegment newPrev = newSeg.Prev();
            IEdgeSegment segNext = segmentX1.Next();
            Assert.AreEqual(segmentX1, newPrev);
            Assert.AreEqual(newSeg, segNext);

            Assert.AreEqual(211, segmentX1.StartX);
            Assert.AreEqual(163, segmentX1.StartY);
            Assert.AreEqual(210, segmentX1.EndX);
            Assert.AreEqual(219, segmentX1.EndY);
            Assert.AreEqual(210, newSeg.StartX);
            Assert.AreEqual(219, newSeg.StartY);
            Assert.AreEqual(210, newSeg.EndX);
            Assert.AreEqual(275, newSeg.EndY);

        }

        [STATestMethod]
        public void Can_Remove_Segment()
        {
            segmentX1.Remove();
            IEdgeSegment prev = segmentX2.Prev();
            Assert.IsNull(prev);
            Assert.AreEqual(211, segmentX2.StartX);
            Assert.AreEqual(163, segmentX2.StartY);
            Assert.AreEqual(340, segmentX2.EndX);
            Assert.AreEqual(266, segmentX2.EndY);
        }

        [STATestMethod]
        public void Can_Get_Segment_Diagram()
        {
            IDiagram diagram = segmentX1.Diagram();
            Assert.AreEqual(diagram1, diagram);
        }

        [STATestMethod]
        public void Can_Get_Segment_Element()
        {
            IEdge edge = segmentX1.Element();
            Assert.AreEqual(edgeX, edge);
        }
    }
}
