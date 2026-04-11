using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WinProMo;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestElements : AutomationTestDiagrams
    {

        protected IBlock blockA;
        protected IBlock blockA1;
        protected IBlock blockA2;
        
        protected IBlock blockB;
        protected IBlock blockB1;
        protected IBlock blockB2;

        protected IBlock blockC;

        protected IEdge edgeX;
        protected IEdge edgeZ;

        [TestInitialize]
        public void Setup()
        {
            base.Setup();
            blockA = diagram1.Elements["4"];
            blockA1 = diagram1.Elements["30"];
            blockA2 = diagram1.Elements["72"];

            blockB = diagram1.Elements["15"];
            blockB1 = diagram1.Elements["49"];
            blockB2 = diagram1.Elements["119"];

            blockC = diagram1.Elements["461"];

            edgeX = diagram1.Elements["391"];
            edgeZ = diagram1.Elements["522"];

            Assert.IsNotNull(blockA);
            Assert.IsNotNull(blockA1);
            Assert.IsNotNull(blockA2);
            Assert.IsNotNull(blockB);
            Assert.IsNotNull(blockB1);
            Assert.IsNotNull(blockB2);
            Assert.IsNotNull(blockC);
            Assert.IsNotNull(edgeX);
            Assert.IsNotNull(edgeZ);
        }

    }
}
