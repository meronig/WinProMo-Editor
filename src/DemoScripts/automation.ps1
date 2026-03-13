function Create-Block($diagram, $left, $top, $width, $height, $text) {

    # Create block
    $block = $diagram.Elements().Add("promo_block_view")

    $block.Left = $left
    $block.Top = $top
    $block.Width = $width
    $block.Height = $height

    if ($text) {
        $block.Properties("Title").Value = $text
    }

    return $block
}


function Connect-Blocks($diagram, $src, $dst) {

    $edge = $diagram.Elements().Add("promo_edge_view")

    $edge.Source = $src
    $edge.Destination = $dst

    $seg0x = $edge.Segments(0).EndX()
    $seg0y = $edge.Segments(0).StartY()

    # create simple straight segment
    $seg = $edge.Segments(0).Split()

    if ($edge.Segments().Count() -gt 0) {

        $seg.StartX = $seg0x
        $seg.StartY = $seg0y

    }

    return $edge
}


function Main {

    # Start application
    $app = New-Object -ComObject WinProMo.Application

    $diagram = $app.Diagrams().Add("demoPlugin")

    $diagram.Width = 1200
    $diagram.Height = 800

    # ---- Root blocks ----

    $root1 = Create-Block $diagram 100 100 200 120 "Root A"
    $root2 = Create-Block $diagram 600 100 200 120 "Root B"

    # ---- Nested sub-blocks ----

    $sub1 = Create-Block $diagram 130 150 120 70 "Sub A1"
    $sub2 = Create-Block $diagram 130 240 120 70 "Sub A2"

    $root1.SubBlocks().Add($sub1)
    $root1.SubBlocks().Add($sub2)

    # ---- Boundary blocks ----

    $boundary1 = Create-Block $diagram 90 90 40 40 "In"
    $boundary2 = Create-Block $diagram 310 150 40 40 "Out"

    $root1.BoundaryBlocks().Add($boundary1, 11)
    $root1.BoundaryBlocks().Add($boundary2, 13)

    # ---- Another nested structure ----

    $sub3 = Create-Block $diagram 630 150 120 70 "Sub B1"
    $root2.SubBlocks().Add($sub3)

    # ---- Connect elements ----

    $edge1 = Connect-Blocks $diagram $boundary1 $sub1
    $edge2 = Connect-Blocks $diagram $sub2 $boundary2
    $edge3 = Connect-Blocks $diagram $root1 $root2

    Write-Host "Demo diagram created."
    
    $diagram.Close(1)

    # Cleanup COM objects
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($edge1) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($edge2) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($edge3) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($root1) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($root2) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($sub1) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($sub2) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($sub3) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($boundary1) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($boundary2) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($diagram) | Out-Null
    [System.Runtime.Interopservices.Marshal]::ReleaseComObject($app) | Out-Null

    [GC]::Collect()
    [GC]::WaitForPendingFinalizers()
}

Main