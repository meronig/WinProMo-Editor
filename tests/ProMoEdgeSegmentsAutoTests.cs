using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo_App.Tests.Helpers;

namespace WinProMo_App.Tests
{
    [TestClass]
    public class ProMoEdgeSegmentsAutoTests : AutomationTestElements
    {
        [STATestMethod]
        public void Can_Get_Segments_Count()
        {
            dynamic segments = edgeX.Segments;
            Assert.IsNotNull(segments, "Segments collection is null");
            Assert.AreEqual(2, segments.Count, "Expected 2 segments for edge X");
        }

        [STATestMethod]
        public void Can_Get_Segment_Objects_By_Position()
        {
            dynamic segments = edgeX.Segments;
            Assert.IsNotNull(segments, "Segments collection is null");
            dynamic segment = segments[0];
            Assert.IsNotNull(segment, "Segment at position 0 is null");
            Assert.AreEqual(211, segment.Left);
            segment = segments[1];
            Assert.IsNotNull(segment, "Segment at position 1 is null");
            Assert.AreEqual(210, segment.Left);

        }
    }
}
