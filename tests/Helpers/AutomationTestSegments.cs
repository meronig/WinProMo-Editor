using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestSegments : AutomationTestElements
    {

        protected dynamic segmentX1;
        protected dynamic segmentX2;
        protected dynamic segmentZ;

        [TestInitialize]
        public void Setup()
        {
            base.Setup();
            segmentX1 = edgeX.Segments[0];
            segmentX2 = edgeX.Segments[1];
            segmentZ = edgeZ.Segments[0];

            Assert.IsNotNull(segmentX1);
            Assert.IsNotNull(segmentX2);
            Assert.IsNotNull(segmentZ);
            
        }

    }
}
