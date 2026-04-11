function CreateBlock(diagram, left, top, width, height, text)
{
    var block = diagram.Elements().Add("promo_block_view");

    block.Left = left;
    block.Top = top;
    block.Width = width;
    block.Height = height;

    if (text)
    {
        block.Properties("Title").Value = text;
    }

    return block;
}


function ConnectBlocks(diagram, src, dst)
{
    var edge = diagram.Elements().Add("promo_edge_view");

    edge.Source = src;
    edge.Destination = dst;

    var seg0x = edge.Segments(0).EndX();
    var seg0y = edge.Segments(0).StartY();

    var seg = edge.Segments(0).Split();

    if (edge.Segments().Count() > 0)
    {
        seg.StartX = seg0x;
        seg.StartY = seg0y;
    }

    return edge;
}


function Main()
{
    var app = new ActiveXObject("WinProMo.Application");

    var diagram = app.Diagrams().Add("demoPlugin");

    diagram.Width = 1200;
    diagram.Height = 800;

    // ---- Root blocks ----

    var root1 = CreateBlock(diagram, 100, 100, 200, 120, "Root A");
    var root2 = CreateBlock(diagram, 600, 100, 200, 120, "Root B");

    // ---- Nested sub-blocks ----

    var sub1 = CreateBlock(diagram, 130, 150, 120, 70, "Sub A1");
    var sub2 = CreateBlock(diagram, 130, 240, 120, 70, "Sub A2");

    root1.SubBlocks().Add(sub1);
    root1.SubBlocks().Add(sub2);

    // ---- Boundary blocks ----
    
    var boundary1 = CreateBlock(diagram, 90, 90, 40, 40, "In");
    var boundary2 = CreateBlock(diagram, 310, 150, 40, 40, "Out");

    root1.BoundaryBlocks().Add(boundary1, 11);
    root1.BoundaryBlocks().Add(boundary2, 13);

    // ---- Another nested structure ----

    var sub3 = CreateBlock(diagram, 630, 150, 120, 70, "Sub B1");
    root2.SubBlocks().Add(sub3);

    // ---- Connect elements ----

    var edge1 = ConnectBlocks(diagram, boundary1, sub1);
    var edge2 = ConnectBlocks(diagram, sub2, boundary2);
    var edge3 = ConnectBlocks(diagram, root1, root2);

    WScript.Echo("Demo diagram created.");

    diagram.Close(true);
	
	app.Quit(false);

    // JScript does not require explicit ReleaseComObject
    // Just drop references:

    edge1 = null;
    edge2 = null;
    edge3 = null;

    root1 = null;
    root2 = null;

    sub1 = null;
    sub2 = null;
    sub3 = null;

    boundary1 = null;
    boundary2 = null;

    diagram = null;
    app = null;

    CollectGarbage();
}

Main();