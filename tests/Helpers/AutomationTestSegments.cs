using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestSegments : AutomationTestElements
    {

        protected IEdgeSegment segmentX1;
        protected IEdgeSegment segmentX2;
        protected IEdgeSegment segmentZ;

        [TestInitialize]
        public void Setup()
        {
            base.Setup();
            segmentX1 = edgeX.Segments[1];
            segmentX2 = edgeX.Segments[2];
            segmentZ = edgeZ.Segments[1];

            Assert.IsNotNull(segmentX1);
            Assert.IsNotNull(segmentX2);
            Assert.IsNotNull(segmentZ);
            
        }

    }
}
