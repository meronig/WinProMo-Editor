using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestProperties : AutomationTestElements
    {

        protected IProperty blockATitle;
        protected IProperty blockA1Title;
        protected IProperty blockA2Title;
        protected IProperty blockBTitle;
        protected IProperty blockB1Title;
        protected IProperty blockB2Title;
        protected IProperty edgeXTitle;
        protected IProperty edgeZTitle;

        [TestInitialize]
        public void Setup()
        {
            base.Setup();
            blockATitle = blockA.Properties[1];
            blockA1Title = blockA1.Properties[1];
            blockA2Title = blockA2.Properties[1];
            blockBTitle = blockB.Properties[1];
            blockB1Title = blockB1.Properties[1];
            blockB2Title = blockB2.Properties[1];
            edgeXTitle = edgeX.Properties[1];
            edgeZTitle = edgeZ.Properties[1];
            
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
