using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinProMo_App.Tests.Helpers
{
    public abstract class AutomationTestElements : AutomationTestDiagrams
    {

        protected dynamic blockA;
        protected dynamic blockA1;
        protected dynamic blockA2;
        
        protected dynamic blockB;
        protected dynamic blockB1;
        protected dynamic blockB2;

        protected dynamic edgeX;
        protected dynamic edgeZ;

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

            edgeX = diagram1.Elements["391"];
            edgeZ = diagram1.Elements["522"];

            Assert.IsNotNull(blockA);
            Assert.IsNotNull(blockA1);
            Assert.IsNotNull(blockA2);
            Assert.IsNotNull(blockB);
            Assert.IsNotNull(blockB1);
            Assert.IsNotNull(blockB2);
            Assert.IsNotNull(edgeX);
            Assert.IsNotNull(edgeZ);
        }

    }
}
