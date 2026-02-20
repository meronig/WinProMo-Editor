using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestLabels : AutomationTestElements
    {

        protected dynamic blockATitle;
        protected dynamic blockA1Title;
        protected dynamic blockA2Title;
        protected dynamic blockBTitle;
        protected dynamic blockB1Title;
        protected dynamic blockB2Title;
        protected dynamic edgeXTitle;
        protected dynamic edgeZTitle;

        [TestInitialize]
        public void Setup()
        {
            base.Setup();
            blockATitle = blockA.Labels[0];
            blockA1Title = blockA1.Labels[0];
            blockA2Title = blockA2.Labels[0];
            blockBTitle = blockB.Labels[0];
            blockB1Title = blockB1.Labels[0];
            blockB2Title = blockB2.Labels[0];
            edgeXTitle = edgeX.Labels[0];
            edgeZTitle = edgeZ.Labels[0];

            Assert.IsNotNull(blockATitle);
            Assert.IsNotNull(blockA1Title);
            Assert.IsNotNull(blockA2Title);
            Assert.IsNotNull(blockBTitle);
            Assert.IsNotNull(blockB1Title);
            Assert.IsNotNull(blockB2Title);
            Assert.IsNotNull(edgeXTitle);
            Assert.IsNotNull(edgeZTitle);

        }

    }
}
