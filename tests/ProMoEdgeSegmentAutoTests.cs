using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoEdgeSegmentAutoTests : AutomationTestSegments
    {
        [STATestMethod]
        public void Can_Get_Segment_Geometry()
        {
            Assert.AreEqual(211, segmentX1.Left);
            Assert.AreEqual(163, segmentX1.Top);
            Assert.AreEqual(210, segmentX1.Right);
            Assert.AreEqual(275, segmentX1.Bottom);
            Assert.AreEqual(-1, segmentX1.Width);
            Assert.AreEqual(112, segmentX1.Height);
        }

        [STATestMethod]
        public void Can_Get_Next_Segment()
        {
            dynamic next = segmentX1.Next;
            Assert.IsNotNull(next);
            Assert.AreEqual(segmentX2, next);

            next = segmentX2.Next;
            Assert.IsNull(next);

        }

        [STATestMethod]
        public void Can_Get_Prev_Segment()
        {
            dynamic prev = segmentX2.Prev;
            Assert.IsNotNull(prev);
            Assert.AreEqual(segmentX1, prev);

            prev = segmentX1.Prev;
            Assert.IsNull(prev);

        }
    }
}
