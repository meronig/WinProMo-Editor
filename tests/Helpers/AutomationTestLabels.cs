using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestLabels : AutomationTestElements
    {

        protected ILabel blockATitle;
        protected ILabel blockA1Title;
        protected ILabel blockA2Title;
        protected ILabel blockBTitle;
        protected ILabel blockB1Title;
        protected ILabel blockB2Title;
        protected ILabel blockCTitle;
        protected ILabel edgeXTitle;
        protected ILabel edgeZTitle;
        protected ILabel diagramLabel;

        [TestInitialize]
        public void Setup()
        {
            base.Setup();
            blockATitle = blockA.Labels[1];
            blockA1Title = blockA1.Labels[1];
            blockA2Title = blockA2.Labels[1];
            blockBTitle = blockB.Labels[1];
            blockB1Title = blockB1.Labels[1];
            blockB2Title = blockB2.Labels[1];
            blockCTitle = blockC.Labels[1];
            edgeXTitle = edgeX.Labels[1];
            edgeZTitle = edgeZ.Labels[1];
            diagramLabel = diagram1.Labels[1];

            Assert.IsNotNull(blockATitle);
            Assert.IsNotNull(blockA1Title);
            Assert.IsNotNull(blockA2Title);
            Assert.IsNotNull(blockBTitle);
            Assert.IsNotNull(blockB1Title);
            Assert.IsNotNull(blockB2Title);
            Assert.IsNotNull(blockCTitle);
            Assert.IsNotNull(edgeXTitle);
            Assert.IsNotNull(edgeZTitle);
            Assert.IsNotNull(diagramLabel);
        }

    }
}
